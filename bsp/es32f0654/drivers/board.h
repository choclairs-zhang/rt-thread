/*
 * File      : board.h
 * Copyright (C) 2018 Shanghai Eastsoft Microelectronics Co., Ltd.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author        Notes
 * 2019-01-23     wangyq        the first version
 */

// <<< Use Configuration Wizard in Context Menu >>>
#ifndef __BOARD_H__
#define __BOARD_H__

#include <es32f065x.h>

#define ES32F0_SRAM_SIZE    0x8000
#define ES32F0_SRAM_END     (0x20000000 + ES32F0_SRAM_SIZE)

#ifdef __CC_ARM
    extern int Image$$RW_IRAM1$$ZI$$Limit;
    #define HEAP_BEGIN  ((void *)&Image$$RW_IRAM1$$ZI$$Limit)
#elif __ICCARM__
    #pragma section="HEAP"
    #define HEAP_BEGIN  (__segment_end("HEAP"))
#else
    extern int __bss_end;
    #define HEAP_BEGIN  ((void *)&__bss_end)
#endif

#define HEAP_END    ES32F0_SRAM_END

void rt_hw_board_init(void);

#endif
