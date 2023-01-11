// Copyright 2023 Noelle (@fivedee)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* Key matrix size */
/* Rows are doubled up */
#define MATRIX_ROWS 10
#define MATRIX_COLS 7

/* Wiring of the controller */
#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F5, F6, F7, B1, B3, B2, B6 }
#define DIODE_DIRECTION COL2ROW
#define SOFT_SERIAL_PIN D2

/* Debounce timer to eliminate double presses. Set to 0 if not needed. */
#define DEBOUNCE 5

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
