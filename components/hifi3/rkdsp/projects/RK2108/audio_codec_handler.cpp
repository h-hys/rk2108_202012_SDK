/*
 * Copyright (c) 2020 Rockchip Electronics Co. Ltd.
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

#include <time.h>

#include "error.h"
#include "section.h"
#include "typedef.h"
#include "loader.h"
#include "work.h"

#include "wakeup.h"
#include "trace.h"
#include "intc.h"

#if ENABLE_OPUS_ENCODE
#include "opus_enc_hal.h"
#endif
#if ENABLE_OPUS_DECODE
#include "opus_dec_hal.h"
#endif

#define DSP_CODEC_OPUS_ENCODE_OPEN      0x50000001
#define DSP_CODEC_OPUS_ENCODE_PROCESS   0x50000002
#define DSP_CODEC_OPUS_ENCODE_FINISH    0x50000003
#define DSP_CODEC_OPUS_ENCODE_CLOSE     0x50000004
#define DSP_CODEC_OPUS_DECODE_OPEN      0x50000005
#define DSP_CODEC_OPUS_DECODE_PROCESS   0x50000006
#define DSP_CODEC_OPUS_DECODE_FINISH    0x50000007
#define DSP_CODEC_OPUS_DECODE_CLOSE     0x50000008

__sys__ int codec_handler(struct worker *worker, struct work *work)
{
    int ret = 0;

    switch (work->algo_type)
    {
#if ENABLE_OPUS_ENCODE
    case DSP_CODEC_OPUS_ENCODE_OPEN:
        ret = AudioOpusEncodeOpen(work->param);
        break;
    case DSP_CODEC_OPUS_ENCODE_PROCESS:
        ret = AudioOpusEncode();
        break;
    case DSP_CODEC_OPUS_ENCODE_FINISH:
        ret = AudioOpusEncodeFinish();
        break;
    case DSP_CODEC_OPUS_ENCODE_CLOSE:
        ret = AudioOpusEncodeClose();
        break;
#endif
#if ENABLE_OPUS_DECODE
    case DSP_CODEC_OPUS_DECODE_OPEN:
        ret = AudioOpusDecodeOpen(work->param);
        break;
    case DSP_CODEC_OPUS_DECODE_PROCESS:
        ret = AudioOpusDecode(work->param);
        break;
    case DSP_CODEC_OPUS_DECODE_CLOSE:
        ret = AudioOpusDecodeClose(work->param);
        break;
#endif
    default:
        ret = -1;
        break;
    }

    return ret;
}
