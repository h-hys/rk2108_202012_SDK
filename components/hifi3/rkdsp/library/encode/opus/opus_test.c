#if ENABLE_OPUS_TEST

#include <stddef.h>
#include <time.h>
#include "audio_codec.h"
#include "opusenc.h"
#include "arch.h"

#define EX_RTATE       (48000)
#define EX_CHANNEL     (4)
#define ENABLE_DBG     (1)
#define READ_SIZE      (EX_RTATE/50)
int g_test_count = 0;

int opusenc_test(const char *inf, const char *outf)
{
  FILE *fin;
  OggOpusEnc *enc;
  OggOpusComments *comments;
  int error;
  clock_t clk_start, clk_end;
  #if OPUSENC_DEBUG
  static int t00 = 0,t11 = 0;
  #endif

  fin = fopen(inf, "rb");
  if (!fin) {
    fprintf(stderr, "cannot open input file: %s\n", inf);
    return 1;
  }
  comments = ope_comments_create();
  ope_comments_add(comments, "ARTIST", "Someone");
  ope_comments_add(comments, "TITLE", "Some track");
  enc = ope_encoder_create_file(outf, comments, EX_RTATE, EX_CHANNEL, EX_CHANNEL > 8 ? 255 : (EX_CHANNEL > 2), &error);
  if (!enc) {
    fprintf(stderr, "error encoding to file %s: %s\n", outf, ope_strerror(error));
    ope_comments_destroy(comments);
    fclose(fin);
    return 1;
  }
  int nb_streams = 1, nb_coupled = 0;
  int opus_frame_param = OPUS_FRAMESIZE_20_MS;
  int frame_size = opus_frame_param <= OPUS_FRAMESIZE_40_MS
              ? 120 << (opus_frame_param - OPUS_FRAMESIZE_2_5_MS)
              : (opus_frame_param - OPUS_FRAMESIZE_20_MS + 1) * 960;
  ope_encoder_ctl(enc, OPUS_SET_EXPERT_FRAME_DURATION(opus_frame_param));
  ope_encoder_ctl(enc, OPE_SET_MUXING_DELAY(0));
  ope_encoder_ctl(enc, OPE_GET_NB_STREAMS(&nb_streams));
  ope_encoder_ctl(enc, OPE_GET_NB_COUPLED_STREAMS(&nb_coupled));
  uint32_t bitrate=((64000*nb_streams+32000*nb_coupled)*
               (IMIN(48,IMAX(8,((EX_RTATE<44100?EX_RTATE:48000)+1000)/1000))+16)+32)>>6;
  bitrate=IMIN(EX_CHANNEL*256000,bitrate);
  bitrate = 128000;
  printf("rate %d ch %d bitrate %d\n",EX_RTATE, EX_CHANNEL, bitrate);
  ope_encoder_ctl(enc, OPUS_SET_BITRATE(bitrate));
  ope_encoder_ctl(enc, OPUS_SET_VBR(1));
  ope_encoder_ctl(enc, OPUS_SET_SIGNAL(OPUS_SIGNAL_VOICE));
  ope_encoder_ctl(enc, OPUS_SET_COMPLEXITY(0));
  ope_encoder_ctl(enc, OPUS_SET_PACKET_LOSS_PERC(0));

  while (1) {
    short buf[2*960*EX_CHANNEL];
    int ret = fread(buf, EX_CHANNEL*sizeof(short), frame_size, fin);
    // printf("%s %d\n", __func__, __LINE__);
    if (ret > 0) {

#if ENABLE_DBG
    clk_start = clock();
#if (defined(__XTENSA__) && defined(ISS_PROCESS))
xt_iss_trace_level(3);
xt_iss_client_command("all", "enable");
#endif
#endif
      ope_encoder_write(enc, buf, ret);

#if ENABLE_DBG
#if (defined(__XTENSA__) && defined(ISS_PROCESS))
 xt_iss_trace_level(0);
 xt_iss_client_command("all", "disable");
#endif
    clk_end = clock();
    g_test_count++;
    printf("g_test_count = %d,cycle = %d %d\n", g_test_count, clk_end - clk_start, (clk_end - clk_start) * 50);
    if (g_test_count >= 10)
        return 0;
#endif

    } else
        break;
  }
  ope_encoder_drain(enc);
  ope_encoder_destroy(enc);
  ope_comments_destroy(comments);
  fclose(fin);
  return 0;
}

#endif
