/* Copyright 2022 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef RGBLIGHT_ENABLE
#include "custom_colors.h"
#define RGBLIGHT_HUE_STEP  8
#define RGBLIGHT_SAT_STEP  8
#define RGBLIGHT_VAL_STEP  8
#define RGBLIGHT_LIMIT_VAL 150
#define RGBLIGHT_LED_MAP {0,1,2,9,8,7,4,3,5,6,19,18,17,10,11,12,15,16,14,13}
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_TWINKLE
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#endif

// Lets you roll mod-tap keys
#define IGNORE_MOD_TAP_INTERRUPT

//Tapping term settings
#define TAPPING_TERM 140

//Combo mod settings
#define COMBO_TERM 40
#define COMBO_HOLD_TERM 140
#define COMBO_ONLY_FROM_LAYER 0

// Allows to use either side as the master. Look at the documentation for info:
// https://docs.qmk.fm/#/config_options?id=setting-handedness
#define EE_HANDS

// EC11K encoders have a different resolution than other EC11 encoders.
// When using the default resolution of 4, if you notice your encoder skipping
// every other tick, lower the resolution to 2.
#define ENCODER_RESOLUTION 2

// Points to a custom font file
#define OLED_FONT_H "noellefont.c"

// VIA specific settings
#define DYNAMIC_KEYMAP_LAYER_COUNT 5