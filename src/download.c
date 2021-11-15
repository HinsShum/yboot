/**
 * @file src\download.c
 *
 * Copyright (C) 2021
 *
 * download.c is free software: you can redistribute it and/or modify
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

/*---------- includes ----------*/
#include "download.h"
#include "simplefifo.h"
#include "platform.h"
#include "ymodem.h"
#include "md5.h"
#include "config/errorno.h"
#include "config/options.h"
#include <string.h>
#include <stdio.h>

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
/*---------- variable ----------*/
static ymodem_context_t _ymodem_ctx;
static uint8_t _buf[CONFIG_RECV_BUFFER_SIZE];

/*---------- function ----------*/
static bool _getc(uint8_t *ch, uint32_t ms)
{
    bool retval = false;

    do {
        if(simplefifo_read(g_plat.dev.fifo, ch, 1)) {
            retval = true;
            break;
        }
        __delay_ms(1);
    } while(--ms);

    return retval;
}

static bool _putc(const uint8_t ch)
{
    debug_cont("%c", (char)ch);

    return true;
}

static bool _file_verify(const char *filename, uint32_t filesize)
{
    printf("%s: %dBytes\n", filename, filesize);

    return true;
}

static bool _frame_save(uint32_t offset, const uint8_t *frame, uint32_t size)
{
    return true;
}

int32_t download_file(void)
{
    int32_t retval = CY_ERROR;

    memset(&_ymodem_ctx, 0, sizeof(_ymodem_ctx));
    _ymodem_ctx.pbuf = _buf;
    _ymodem_ctx.size = CONFIG_RECV_BUFFER_SIZE;
    _ymodem_ctx.get_char = _getc;
    _ymodem_ctx.putc = _putc;
    _ymodem_ctx.frame_save = _frame_save;
    _ymodem_ctx.file_verify = _file_verify;
    debug_message("Start YMODEM...\r\n");
    simplefifo_reset(g_plat.dev.fifo);
    ymodem_init(&_ymodem_ctx);
    if(YMODEM_ERR_OVER == ymodem_recv_file()) {
        debug_message("OK\r\n");
        retval = CY_EOK;
    } else {
        debug_error("ERROR\r\n");
    }
    simplefifo_reset(g_plat.dev.fifo);

    return retval;
}
