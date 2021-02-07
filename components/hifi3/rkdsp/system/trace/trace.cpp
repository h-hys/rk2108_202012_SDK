/*
 * Copyright (c) 2019 Rockchip Electronics Co. Ltd.
 * Author: Huaping Liao <huaping.liao@rock-chips.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "trace.h"

#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

#include "error.h"
#include "version.h"
#include "section.h"

#include "uart.h"
#include "mailbox.h"
#include "cache.h"
#include "iomap.h"

#define MAX_STRING_SIZE 128
enum log_out {
    DSP_TRACE_DISABLE    = -1,
    DSP_TRACE_TO_UART    = 0,
    DSP_TRACE_TO_HOST    = 1,
};

struct dsp_trace {
    enum log_out out;
    char *buffer;

    uint32_t slot_size;
    uint32_t slot_count;

    uint32_t slot_index;
    uint32_t trace_index;

    int tracing;

#if AP_DBG
    int trace_result;
#endif

    char trace_buffer[MAX_STRING_SIZE];
    struct mbox_client mbox;
};

__sys_data__ struct dsp_trace g_trace = {DSP_TRACE_TO_UART};

static __sys__ unsigned int mini_strlen(const char *s)
{
    unsigned int len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}

static __sys__ unsigned int mini_itoa(int value, unsigned int radix,
        unsigned int uppercase, unsigned int unsig, char *buffer,
        unsigned int zero_pad)
{
    char *pbuffer = buffer;
    int negative = 0;
    unsigned int i, len;

    /* No support for unusual radixes. */
    if (radix > 16)
        return 0;

    if (value < 0 && !unsig) {
        negative = 1;
        value = -value;
    }

    /* This builds the string back to front ... */
    do {
        int digit = value % radix;
        *(pbuffer++) =
                (digit < 10 ? '0' + digit : (uppercase ? 'A' : 'a') + digit - 10);
        value /= radix;
    } while (value > 0);

    for (i = (pbuffer - buffer); i < zero_pad; i++)
        *(pbuffer++) = '0';

    if (negative)
        *(pbuffer++) = '-';

    *(pbuffer) = '\0';

    /* ... now we reverse it (could do it recursively but will
     * conserve the stack space) */
    len = (pbuffer - buffer);
    for (i = 0; i < len / 2; i++) {
        char j = buffer[i];
        buffer[i] = buffer[len - i - 1];
        buffer[len - i - 1] = j;
    }

    return len;
}

struct mini_buff {
    char *buffer, *pbuffer;
    unsigned int buffer_len;
};

static __sys__ int _putc(int ch, struct mini_buff *b)
{
    if ((unsigned int)((b->pbuffer - b->buffer) + 1) >= b->buffer_len)
        return 0;
    *(b->pbuffer++) = ch;
    *(b->pbuffer) = '\0';
    return 1;
}

static __sys__ int _puts(char *s, unsigned int len, struct mini_buff *b)
{
    unsigned int i;

    if (b->buffer_len - (b->pbuffer - b->buffer) - 1 < len)
        len = b->buffer_len - (b->pbuffer - b->buffer) - 1;

    /* Copy to buffer */
    for (i = 0; i < len; i++)
        *(b->pbuffer++) = s[i];
    *(b->pbuffer) = '\0';

    return len;
}

__sys__ int mini_vsnprintf(char *buffer, unsigned int buffer_len,
                           const char *fmt, va_list va)
{
    struct mini_buff b;
    char bf[24];
    char ch;

    b.buffer = buffer;
    b.pbuffer = buffer;
    b.buffer_len = buffer_len;

    while ((ch = *(fmt++))) {
        if ((unsigned int)((b.pbuffer - b.buffer) + 1) >= b.buffer_len)
            break;
        if (ch != '%')
            _putc(ch, &b);
        else {
            char zero_pad = 0;
            char *ptr;
            unsigned int len;

            ch = *(fmt++);

            /* Zero padding requested */
            if (ch == '0') {
                ch = *(fmt++);
                if (ch == '\0')
                    goto end;
                if (ch >= '0' && ch <= '9')
                    zero_pad = ch - '0';
                ch = *(fmt++);
            }

            switch (ch) {
            case 0:
                goto end;

            case 'u':
            case 'd':
                len = mini_itoa(va_arg(va, unsigned int), 10, 0, (ch == 'u'),
                        bf, zero_pad);
                _puts(bf, len, &b);
                break;
            case 'l':
                ch = *(fmt++);
                if (ch == 'd' || ch == 'u') {
                    len = mini_itoa(va_arg(va, unsigned long long), 10, 0,
                            (ch == 'u'), bf, zero_pad);
                    _puts(bf, len, &b);
                }
                break;
            case 'x':
            case 'X':
                len = mini_itoa(va_arg(va, unsigned int), 16, (ch == 'X'), 1,
                        bf, zero_pad);
                _puts(bf, len, &b);
                break;

            case 'c':
                _putc((char)(va_arg(va, int)), &b);
                break;

            case 's':
                ptr = va_arg(va, char*);
                _puts(ptr, mini_strlen(ptr), &b);
                break;

            default:
                _putc(ch, &b);
                break;
            }
        }
    }
    end : return b.pbuffer - b.buffer;
}

__sys__ int mini_snprintf(char* buffer, unsigned int buffer_len,
        const char *fmt, ...)
{
    int ret;
    va_list va;
    va_start(va, fmt);
    ret = mini_vsnprintf(buffer, buffer_len, fmt, va);
    va_end(va);

    return ret;
}

__sys__ void print_to_host(const char *format, ...)
{
    va_list args;
    char *out;

    if (g_trace.buffer == 0)
        return;

    // Select slot
    out = g_trace.buffer
            + g_trace.slot_size * (g_trace.slot_index % g_trace.slot_count);

    // Prepare slot for trace
    memset(out, 0, g_trace.slot_size);

    memset(g_trace.trace_buffer, 0, MAX_STRING_SIZE);
    va_start(args, format);
    mini_vsnprintf(g_trace.trace_buffer, MAX_STRING_SIZE, format, args);
    memcpy(out, g_trace.trace_buffer, g_trace.slot_size - 1);
    va_end(args);
    xthal_dcache_region_writeback(out, g_trace.slot_size);
    if (!g_trace.tracing) {
        g_trace.tracing = 1;
        mbox_send_data(g_trace.mbox.id, g_trace.mbox.chan, DSP_CMD_TRACE,
                (uint32_t)g_trace.slot_index);
    }

    g_trace.slot_index++;
}

__sys__ void print_to_uart(const char *format, ...)
{
    va_list args;

    if (g_trace.out == DSP_TRACE_DISABLE)
        return;

    memset(g_trace.trace_buffer, 0, MAX_STRING_SIZE);

    va_start(args, format);
    mini_vsnprintf(g_trace.trace_buffer, MAX_STRING_SIZE, format, args);
    if (g_trace.out == DSP_TRACE_TO_HOST) {
        print_to_host(g_trace.trace_buffer);
    } else {
        uart_tx_string(g_trace.trace_buffer, strlen(g_trace.trace_buffer));
    }
    va_end(args);
}

__sys__ int trace_receive_data(struct mbox_client *client,
                               uint32_t cmd, uint32_t data)
{
    if (cmd != DSP_CMD_TRACE_DONE)
        return -EINVALID;

    g_trace.trace_index = data;
    g_trace.tracing = 0;

    return SUCCESS;
}

__sys__ void trace_flush(void)
{
    if (!g_trace.tracing) {
        g_trace.tracing = 1;
        mbox_send_data(MBOX_ID, g_trace.mbox.chan, DSP_CMD_TRACE,
                       (uint32_t)g_trace.slot_index);
    }
}

__sys__ void trace_disable(void)
{
    g_trace.out = DSP_TRACE_DISABLE;
}

__sys__ int trace_init(enum mbox_id mbox_id, char *buffer, uint32_t buffer_size, uint32_t slot_size)
{
    if (buffer_size == 0 || buffer_size % slot_size != 0)
        return -EINVALID;

    g_trace.tracing = 0;
    g_trace.trace_index = 0;
    g_trace.slot_index = 0;
    g_trace.buffer = buffer;
    g_trace.slot_size = slot_size;
    g_trace.slot_count = buffer_size / slot_size;

    g_trace.mbox.id = mbox_id;
    g_trace.mbox.chan = MBOX_CHAN_3;
    g_trace.mbox.receive_data = trace_receive_data;

    mbox_register_client(&g_trace.mbox);

    print_to_host("DSP is ready to work, firmware version: %s\n", DSP_VERSION);

    return SUCCESS;
}

__sys__ void rk_assert_handler(const char *ex_string, const char *func, uint32_t line)
{
    char *buffer = (char *)memalign(CACHE_LINE_SIZE, MAX_STRING_SIZE);
    if (buffer)
        mini_snprintf(buffer, MAX_STRING_SIZE,
                      "HiFi3: (%s) assertion failed at function:%s, line number:%d\n",
                      ex_string, func, line);
    mbox_send_data(MBOX_ID, MBOX_CHAN_1, DSP_CMD_ASSERT, (uint32_t)buffer);
    while(1);
}

#if AP_DBG

#define DSP_TRACE_BUFFER_SIZE         (1 * 1024)
#define DSP_TRACE_SLOT_SIZE           (128)
#define DSP_TRACE_SLOT_COUNT          (DSP_TRACE_BUFFER_SIZE / DSP_TRACE_SLOT_SIZE)

__sys__ int ap_trace_init(enum mbox_id mbox_id)
{
    g_trace.tracing = 0;
    g_trace.trace_index = 0;
    g_trace.slot_index = 0;
    g_trace.buffer = (char *)calloc(DSP_TRACE_BUFFER_SIZE, 1);
    if (!g_trace.buffer) {
        g_trace.trace_result = -ENOMEM;
        return -ENOMEM;
    }
    g_trace.slot_size = DSP_TRACE_SLOT_SIZE;
    g_trace.slot_count = DSP_TRACE_SLOT_COUNT;

    g_trace.mbox.id = mbox_id;
    g_trace.mbox.chan = MBOX_CHAN_3;
    g_trace.mbox.receive_data = trace_receive_data;
    xthal_dcache_region_writeback(&g_trace, sizeof(g_trace));

    mbox_register_client(&g_trace.mbox);
    mbox_send_data(g_trace.mbox.id, g_trace.mbox.chan,
                   DSP_CMD_TRACE_CONFIG_DONE, (uint32_t)&g_trace);
    LOGD("DSP is ready to work, firmware version: %s\n", DSP_VERSION);

    return SUCCESS;
}
#endif
