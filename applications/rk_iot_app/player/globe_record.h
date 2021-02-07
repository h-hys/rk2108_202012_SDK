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

#ifndef _GLOBE_RECORD_H_
#define _GLOBE_RECORD_H_

#include <stdbool.h>
#include <stdio.h>
typedef enum rtos_record_cmd
{
    RtosRecordCmd_AIStart,               //  AI dialog record
    RtosRecordCmd_WechatStart,           //  wechat recoard
    RtosRecordCmd_ZToEStart,             //  Chinese to English record
    RtosRecordCmd_EtoZStart,             //  Englisth to Chinese record
    RtosRecordCmd_Stop,                  //  Stop record
    RtosRecordCmd_Cannel,                //  canl record
} rtos_record_cmd;

typedef struct _RtosRecordData
{
    bool flag ;
    uint8_t *add ;
    struct _RtosRecordData *next ;
} RtosRecordData_Def;

typedef struct rtos_record_msg
{
    rtos_record_cmd cmd ;
} rtos_record_msg;

typedef struct _GptRecordFun
{
    RtosRecordData_Def *RecordDataHead ;
    RtosRecordData_Def *RecordDataEnd ;
    uint8_t RecordDataNum ;
    int (*Send)(rtos_record_cmd cmd) ;
} RtosRecordFun_Def;

extern RtosRecordFun_Def RtosRecordFun ;

void rtos_record_init(void) ;
void rtos_record_data_deinit(void) ;
int rtos_record_send(rtos_record_cmd cmd) ;

#endif  //_GLOBE_RECORD_H_