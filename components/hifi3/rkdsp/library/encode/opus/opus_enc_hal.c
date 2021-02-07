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

#include "opus_enc_hal.h"
#include "trace.h"
#include <time.h>

#if ENABLE_OPUS_ENCODE
#define OPUS_TIME_TEST     (0)

static opus_enc_t g_opus_enc;

opus_enc_t *enc_get_opus_enc()
{
    return &g_opus_enc;
}

int32_t AudioOpusEncodeOpen(uint32_t A2B_EncOpus)
{
    struct audio_server_data_share *pEncDat = (struct audio_server_data_share *)A2B_EncOpus;
    struct audio_config *opus_cfg = (struct audio_config *)pEncDat->dat[0];
    struct opus_info *info = (struct opus_info *)pEncDat->dat[1];
    xthal_dcache_region_invalidate(info, sizeof(struct opus_info));
    int err;

    opus_enc_t *opus_enc = enc_get_opus_enc();
    memset(opus_enc, 0, sizeof(opus_enc_t));
    opus_enc->comments = ope_comments_create();
    LOGD("opus_enc->comments %x\n", opus_enc->comments);
    opus_enc->max_packets = info->max_packets;
    if (info->comment_num)
    {
        char **comments = (char **)info->comments;
        xthal_dcache_region_invalidate(comments,
                                       sizeof(char *) * info->comment_num);
        int i;
        for (i = 0; i < info->comment_num; i++)
            ope_comments_add(opus_enc->comments, NULL, comments[i]);
    }
    else
    {
        ope_comments_add(opus_enc->comments, "ARTIST", "RK");
    }
    opus_enc->ab_share_dat = pEncDat;

    opus_enc->_encoder = ope_encoder_create_pull(opus_enc->comments,
                                                 opus_cfg->sample_rate, opus_cfg->channels,
                                                 opus_cfg->channels > 8 ? 255 : (opus_cfg->channels > 2),
                                                 &err);
    if (opus_enc->_encoder == NULL || err != OPUS_OK)
    {
        LOGD("ope_encoder_create_callbacks = %d %s\n", err, ope_strerror(err));
        ope_comments_destroy(opus_enc->comments);
        return -1;
    }
    int nb_streams = 1, nb_coupled = 0;
    int opus_frame_param = OPUS_FRAMESIZE_20_MS;
    int vbr = 1;
    uint32_t bitrate;
    int frame_size = opus_frame_param <= OPUS_FRAMESIZE_40_MS
                     ? 120 << (opus_frame_param - OPUS_FRAMESIZE_2_5_MS)
                     : (opus_frame_param - OPUS_FRAMESIZE_20_MS + 1) * 960;
    ope_encoder_ctl(opus_enc->_encoder, OPUS_SET_EXPERT_FRAME_DURATION(opus_frame_param));
    ope_encoder_ctl(opus_enc->_encoder, OPE_SET_MUXING_DELAY(0));
    ope_encoder_ctl(opus_enc->_encoder, OPE_GET_NB_STREAMS(&nb_streams));
    ope_encoder_ctl(opus_enc->_encoder, OPE_GET_NB_COUPLED_STREAMS(&nb_coupled));
    if (opus_cfg->bitrate)
    {
        bitrate = opus_cfg->bitrate;
        vbr = 0;
    }
    else
    {
        bitrate = ((64000 * nb_streams + 32000 * nb_coupled) *
                   (IMIN(48, IMAX(8, ((opus_cfg->sample_rate < 44100 ? opus_cfg->sample_rate : 48000) + 1000) / 1000)) + 16) + 32) >> 6;
    }
    bitrate = IMIN(opus_cfg->channels * 256000, bitrate);
    LOGD("rate %d ch %d bitrate %d\n", opus_cfg->sample_rate, opus_cfg->channels, bitrate);
    ope_encoder_ctl(opus_enc->_encoder, OPUS_SET_BITRATE(bitrate));
    ope_encoder_ctl(opus_enc->_encoder, OPUS_SET_VBR(vbr));
    ope_encoder_ctl(opus_enc->_encoder, OPUS_SET_SIGNAL(OPUS_SIGNAL_VOICE));
    ope_encoder_ctl(opus_enc->_encoder, OPUS_SET_COMPLEXITY(0));
    ope_encoder_ctl(opus_enc->_encoder, OPUS_SET_PACKET_LOSS_PERC(0));

    opus_enc->frame_size = opus_cfg->sample_rate / 50;    // 20ms
    opus_enc->sample_rate = opus_cfg->sample_rate;
    opus_enc->channels = opus_cfg->channels;
    opus_enc->_buffer_in = (short *)memalign(128, opus_enc->frame_size * opus_enc->channels * sizeof(short));

    ope_encoder_flush_header(opus_enc->_encoder);
    unsigned char *out_buf;
    uint32_t out_len = 0;
    int ret = ope_encoder_get_page(opus_enc->_encoder, &out_buf, &opus_enc->header_size, 0);
    if (ret == 1)
    {
        opus_enc->_buffer_header = (short *)memalign(128, opus_enc->header_size);
        memcpy(opus_enc->_buffer_header, out_buf, opus_enc->header_size);
        xthal_dcache_region_writeback((void *)opus_enc->_buffer_header, opus_enc->header_size);
    }
    pEncDat->dat[0] = (uint32_t)opus_enc;
    pEncDat->dat[1] = 0;
    xthal_dcache_region_writeback((void *)pEncDat, sizeof(struct audio_server_data_share));
    xthal_dcache_region_writeback((void *)opus_enc, sizeof(opus_enc_t));

    return 0;
}

int32_t AudioOpusEncode(void)
{
#if OPUS_TIME_TEST
    clock_t t11 = 0, t00 = 0;
    t11 = clock();
#endif
    opus_enc_t *opus_enc = enc_get_opus_enc();
    int ret;

    xthal_dcache_region_invalidate(opus_enc->_buffer_in, opus_enc->frame_size * opus_enc->channels * sizeof(short));
    ope_encoder_write(opus_enc->_encoder, opus_enc->_buffer_in, opus_enc->frame_size);
#if OPUS_TIME_TEST
    t00 = clock();
    LOGD("timer_opus_enc = %d (cycle)\n", t00 - t11);
#endif
    opus_enc->packets++;
    ret = ope_encoder_get_page(opus_enc->_encoder, &opus_enc->_buffer_out, &opus_enc->enc_size,
                               (opus_enc->max_packets != 0) && (opus_enc->packets >= opus_enc->max_packets));
    if (ret == 1)
    {
        xthal_dcache_region_writeback((void *)opus_enc->_buffer_out, opus_enc->enc_size);
        opus_enc->packets = 0;
    }
    opus_enc->ab_share_dat->dat[1] = opus_enc->enc_size;
    xthal_dcache_region_writeback((void *)opus_enc->ab_share_dat, sizeof(struct audio_server_data_share));
    xthal_dcache_region_writeback((void *)opus_enc, sizeof(opus_enc_t));

    return 0;
}

int32_t AudioOpusEncodeFinish(void)
{
    opus_enc_t *opus_enc = enc_get_opus_enc();
    int ret;

    if (opus_enc->drain_flag == 0)
    {
        ope_encoder_drain(opus_enc->_encoder);
        opus_enc->drain_flag = 1;
    }
    ret = ope_encoder_get_page(opus_enc->_encoder, &opus_enc->_buffer_out, &opus_enc->enc_size, 0);
    if (ret == 1)
    {
        xthal_dcache_region_writeback((void *)opus_enc->_buffer_out, opus_enc->enc_size);
    }

    opus_enc->ab_share_dat->dat[1] = opus_enc->enc_size;
    xthal_dcache_region_writeback((void *)opus_enc->ab_share_dat, sizeof(struct audio_server_data_share));
    xthal_dcache_region_writeback((void *)opus_enc, sizeof(opus_enc_t));

    return 0;
}

int32_t AudioOpusEncodeClose(void)
{
    LOGD("opus encode close");
    opus_enc_t *opus_enc = enc_get_opus_enc();
    if (opus_enc->_encoder)
    {
        free(opus_enc->_buffer_header);
        free(opus_enc->_buffer_in);
        ope_encoder_destroy(opus_enc->_encoder);
        ope_comments_destroy(opus_enc->comments);

        opus_enc->_encoder = NULL;
    }

    return 0;
}
#endif
