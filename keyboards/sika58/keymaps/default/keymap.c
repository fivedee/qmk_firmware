// Copyright 2023 Noelle (@fivedee)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
	_BASE = 0,
	_FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT_split_6x4(
		KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5,					KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS,
		MO(1), KC_Q, KC_W, KC_E, KC_R, KC_T,					KC_Y, KC_U, KC_I, KC_O, KC_P, KC_QUOT,
		KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_ESC, KC_GRV, KC_H, KC_J, KC_K, KC_L, KC_SCLN, MO(1),
			KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MINS, KC_EQL, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
				KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_ENT, KC_BSPC, KC_DEL, OSM(MOD_MEH)
    ),
	[1] = LAYOUT_split_6x4(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,					KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU, KC_MUTE,
		KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_TRNS,					KC_PGUP, LCTL(KC_LEFT), KC_UP, LCTL(KC_LEFT), KC_HOME, KC_TRNS,
		KC_TRNS, KC_F5, KC_F6, KC_F7, KC_F8, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_TRNS,
			KC_F9, KC_F10, KC_F11, KC_F12, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_PSCR, KC_SCRL, KC_PAUS, KC_CAPS,
				KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_TRNS
    )
};
