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

#ifndef _AUDIO_OPUS_ENC_HAL_H_
#define _AUDIO_OPUS_ENC_HAL_H_

#include <stddef.h>
#include "audio_codec.h"
#include "arch.h"
#include "opusenc.h"

#if ENABLE_OPUS_ENCODE

struct opus_info
{
    int max_packets;
    int comment_num;
    uint32_t comments;
};

typedef struct _opus_enc_s
{
    OggOpusEnc          *_encoder;
    OggOpusComments     *comments;
    int                 sample_rate;
    int                 channels;
    int                 frame_size;
    short               *_buffer_in;
    short               *_buffer_header;
    short               *_buffer_out;
    int                 header_size;
    int                 enc_size;
    int                 drain_flag;
    int                 packets;
    int                 max_packets;

    struct audio_server_data_share *ab_share_dat;
} opus_enc_t;

#ifdef __cplusplus
extern "C" {
#endif
extern int32_t AudioOpusEncodeOpen(uint32_t A2B_EncOpus);
extern int32_t AudioOpusEncodeClose(void);
extern int32_t AudioOpusEncode(void);
extern int32_t AudioOpusEncodeFinish(void);
#ifdef __cplusplus
}
#endif

#endif      // ENABLE_OPUS_ENCODE
#endif      // _AUDIO_SPEEX_ENC_HAL_H_
