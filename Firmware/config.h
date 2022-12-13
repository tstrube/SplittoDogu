// Copyright 2022 Timo Strube (@tstrube)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

#define MATRIX_COLS 8
#define MATRIX_ROWS 10
#define MATRIX_COL_PINS { B2, B6, B3, B1, F7, F6, F5, F4 }
#define MATRIX_ROW_PINS { B7, D5, C7, F1, F0 }
#define MATRIX_COL_PINS_RIGHT { F4, F5, F6, F7, B1, B3, B6, B2 }

#define ENCODERS_PAD_A { C6, D7, B5 }
#define ENCODERS_PAD_B { D4, E6, B4 }

#define SOFT_SERIAL_PIN D3
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_OLED_ENABLE
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_USB_DETECT