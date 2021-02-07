/*
 *  Copyright (C) 2019, Fuzhou Rockchip Electronics Co., Ltd.
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

#ifndef _AUDIO_OPUS_DEC_HAL_H_
#define _AUDIO_OPUS_DEC_HAL_H_

#include <stddef.h>
#include "audio_codec.h"
#include "celt.h"
#include "ogg.h"
#include "opus.h"

#define OPUS_FRAME_SIZE     960

typedef struct _opus_dec_s
{
    OpusDecoder *decoder;
    char        *buffer_in;
    uint32_t    bytes_in;
    uint16_t    *buffer_out;
    uint32_t    bytes_out;

    struct audio_server_data_share *ab_share_dat;
} opus_dec_t;

#ifdef __cplusplus
extern "C" {
#endif
int32_t AudioOpusDecodeOpen(uint32_t A2B_EncOpus);
int32_t AudioOpusDecodeClose(uint32_t A2B_EncOpus);
int32_t AudioOpusDecode(uint32_t A2B_EncOpus);
#ifdef __cplusplus
}
#endif

#endif        // _AUDIO_OPUS_DEC_HAL_H_
