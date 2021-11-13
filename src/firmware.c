/**
 * @file src\firmware.c
 *
 * Copyright (C) 2021
 *
 * firmware.c is free software: you can redistribute it and/or modify
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
#include "firmware.h"
#include "flash.h"
#include "platform.h"
#include "checksum.h"
#include "config/errorno.h"
#include "config/options.h"
#include <string.h>

/*---------- macro ----------*/
#define FIRMWARE_INFO_MAGIC                         (0x00769394)

/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
typedef struct {
    uint32_t magic;
    uint32_t fsize;
    uint8_t md5[16];
    bool updated;
    uint8_t reserve[5];
    uint16_t crc16;
} firmware_info_t;

/*---------- variable ----------*/
static firmware_info_t _firmware;

/*---------- function ----------*/
static void _set_default_information(firmware_info_t *info)
{
    info->magic = FIRMWARE_INFO_MAGIC;
    info->fsize = 0;
    info->updated = true;
    info->crc16 = 0;
    memset(info->md5, 0, ARRAY_SIZE(info->md5));
    memset(info->reserve, 0, ARRAY_SIZE(info->reserve));
}

int32_t firmware_init(void)
{
    int32_t retval = CY_ERROR;

    do {
        /* get app backup information from flash */
        if(!device_read(g_plat.dev.backup_flash, &_firmware, CONFIG_APP_BK_INFO_LOCATION, sizeof(_firmware))) {
            break;
        }
        /* check information */
        if(_firmware.magic != FIRMWARE_INFO_MAGIC) {
            break;
        }
        if(checksum_crc16_xmodem((void *)&_firmware, sizeof(_firmware))) {
            break;
        }
        retval = CY_EOK;
    } while(0);
    if(retval != CY_EOK) {
        _set_default_information(&_firmware);
    }

    return retval;
}

bool firmware_get_updated_flag(void)
{
    return _firmware.updated;
}
