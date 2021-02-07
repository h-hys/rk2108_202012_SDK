/*
 *  Copyright (C) 2020, Fuzhou Rockchip Electronics Co., Ltd.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of Fuzhou Rockchip Electronics Co., Ltd. nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#if ENABLE_OPUS_ENCODE

#include "trace.h"
#include <time.h>
#include "opus_dec_hal.h"

int32_t AudioOpusDecodeOpen(uint32_t A2B_DecOpus)
{
    struct audio_server_data_share *share_data = (struct audio_server_data_share *)A2B_DecOpus;
    opus_dec_t *opus;
    int err;
    opus = malloc(sizeof(opus_dec_t));
//    opus = memalign(sizeof(opus_dec_t), 128);
    if (!opus)
    {
        LOGD("opus malloc error");
        return -1;
    }

    opus->decoder = opus_decoder_create(48000, 2, &err);
    opus->buffer_out = (uint16_t *)malloc(OPUS_FRAME_SIZE * 4 * sizeof(uint16_t));
//    opus->buffer_out = (uint16_t *)memalign(OPUS_FRAME_SIZE * 4 * sizeof(uint16_t), 128);
    if (!opus->buffer_out)
    {
        LOGD("opus buffer_out malloc error");
        free(opus);
        return -1;
    }
    opus->ab_share_dat = share_data;
    share_data->dat[0] = (uint32_t)opus;
    xthal_dcache_region_writeback((void *)opus, sizeof(opus_dec_t));
    xthal_dcache_region_writeback((void *)share_data, sizeof(struct audio_server_data_share));

    return 0;
}

int32_t AudioOpusDecodeClose(uint32_t A2B_DecOpus)
{
    struct audio_server_data_share *share_data = (struct audio_server_data_share *)A2B_DecOpus;
    opus_dec_t *opus = (opus_dec_t *)share_data->dat[0];
    free(opus->buffer_out);
    opus_decoder_destroy(opus->decoder);
    free(opus);

    return 0;
}

int32_t AudioOpusDecode(uint32_t A2B_DecOpus)
{
    struct audio_server_data_share *share_data = (struct audio_server_data_share *)A2B_DecOpus;
    opus_dec_t *opus = (opus_dec_t *)share_data->dat[0];
    int len;

    xthal_dcache_region_invalidate((void *)opus, sizeof(opus_dec_t));
    xthal_dcache_region_invalidate(opus->buffer_in, opus->bytes_in);
    len = opus_decode(opus->decoder,
                      (unsigned char *)opus->buffer_in,
                      opus->bytes_in,
                      (opus_val16 *)opus->buffer_out,
                      OPUS_FRAME_SIZE,
                      0);
    if (len <= 0)
    {
        LOGD("decode error %d", len);
        return -1;
    }
    opus->bytes_out = len * 2 * 2;
    xthal_dcache_region_writeback((void *)opus->buffer_out, len * 2 * 2);
    xthal_dcache_region_writeback((void *)opus, sizeof(opus_dec_t));

    return 0;
}
#endif
