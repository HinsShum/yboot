/**
 * @file config\win32\options.h
 *
 * Copyright (C) 2021
 *
 * options.h is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @author HinsShum hinsshum@qq.com
 *
 * @encoding utf-8
 */
#ifndef __CONFIG_WIN32_OPTIONS_H
#define __CONFIG_WIN32_OPTIONS_H

#ifdef __cplusplus
extern "C"
{
#endif

/*---------- includes ----------*/
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#if !defined(CONFIG_SILENT) && !defined(NDEBUG)
#include <stdio.h>
#endif
#include <windows.h>

/*---------- macro ----------*/
#undef assert
#ifdef NDEBUG
#define assert(expr)                    ((void)0U)
#else
#define assert(expr)                    do { if(!(expr)) { for(;;); }} while(0)
#endif

/* format to string
 */
#define _STRING(x)                      #x              /*<< only format alphabet as string */
#define STRING(x)                       _STRING(x)      /*<< format alphabet or digit as string */

/* system variables defined
 */
#define SYS_VERSION                     ((VERSION_MAJOR << 24) | (VERSION_MINOR << 16) | (VERSION_FIX << 8) | VERSION_BUILD)
#define SYS_VERSION_STRING              (STRING(VERSION_MAJOR)"."STRING(VERSION_MINOR)"."STRING(VERSION_FIX)"."STRING(VERSION_BUILD))
#define SYS_MODEL_NAME                  "yboot"
#define SYS_HW_VERSION                  ((HW_VERSION_MAJOR << 8) | HW_VERSION_MINOR)
#define SYS_PRODUCT_TIME                (__DATE__)
#define SYS_VENDOR                      "HinsShum"

/* system delay function
 */
#define __delay_ms(ms)                  (Sleep(ms))
#define __delay_us(us)
#define __get_ticks()                   (ticks_get())
#define MS2TICKS(ms)                    (ms)

/* print macros
 */
#ifndef CONFIG_SILENT
#define __debug_message(x, y...)        printf("\033[32;22m" x, ##y)
#define __debug_info(x, y...)           printf("\033[37;22m" x, ##y)
#define __debug_warn(x, y...)           printf("\033[31;22m" x, ##y)
#define __debug_error(x, y...)          printf("\033[31;22m" x, ##y)
#define __debug_cont(x, y...)           printf(x, ##y)
#else
#define __debug_message(x, y...)
#define __debug_info(x, y...)
#define __debug_warn(x, y...)
#define __debug_error(x, y...)
#define __debug_cont(x, y...)
#endif

/* embed flash information
 */
#define CONFIG_EMBED_FLASH_BASE         (0x0)
#define CONFIG_EMBED_FLASH_SIZE         (0x10000)       /*<< 64 * 1024 */
#define CONFIG_EMBED_FLASH_BLOCK_SIZE   (0x400)         /*<< 1 * 1024 */
#define CONFIG_EMBED_FLASH_END          (CONFIG_EMBED_FLASH_BASE + CONFIG_EMBED_FLASH_SIZE)
#define CONFIG_EMBED_FLASH_WRITE_GRAN   (32)

/* fifo size config
 */
#define CONFIG_FIFO_SIZE                (1024)

/*---------- type define ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
extern uint64_t ticks_get(void);

#ifdef __cplusplus
}
#endif
#endif /* __CONFIG_WIN32_OPTIONS_H */