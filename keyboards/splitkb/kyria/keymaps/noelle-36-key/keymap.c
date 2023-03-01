/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include QMK_KEYBOARD_H
#include "noelleanim.h"

enum layers {
    DEFAULT = 0,
    SYM,
    NAV,
    NUM,
	MODS,
	ADJUST
};

enum custom_keycodes {
	OS_CLEAR
};


// clang-format off
#define LAYOUT_via( \
    L00, L01, L02, L03, L04, L05, LE0, LE1, RE0, RE1, R06, R07, R08, R09, R10, R11, \
    L12, L13, L14, L15, L16, L17,                     R18, R19, R20, R21, R22, R23, \
    L24, L25, L26, L27, L28, L29, L30, L31, R32, R33, R34, R35, R36, R37, R38, R39, \
                   L40, L41, L42, L43, L44, R45, R46, R47, R48, R49 \
) \
{ \
    { LE0,   LE1,   L05,   L04,   L03,   L02,   L01,   L00   }, \
    { RE0,   RE1,   L17,   L16,   L15,   L14,   L13,   L12   }, \
    { L31,   L30,   L29,   L28,   L27,   L26,   L25,   L24   }, \
    { L44,   L43,   L42,   L41,   L40,   KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, R06,   R07,   R08,   R09,   R10,   R11   }, \
    { KC_NO, KC_NO, R18,   R19,   R20,   R21,   R22,   R23   }, \
    { R32,   R33,   R34,   R35,   R36,   R37,   R38,   R39   }, \
    { R45,   R46,   R47,   R48,   R49,   KC_NO, KC_NO, KC_NO }, \
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [DEFAULT] = LAYOUT(KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO, KC_NO, LSFT_T(KC_A), KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, RSFT_T(KC_QUOT), KC_NO, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO, KC_NO, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO, KC_NO, QK_LEAD, LT(3,KC_SPC), LT(1,KC_TAB), KC_NO, KC_NO, LT(2,KC_ENT), KC_BSPC, OSL(4), KC_NO),

    [SYM] = LAYOUT(KC_NO, KC_GRV, KC_TILD, KC_LBRC, KC_RBRC, KC_AMPR, KC_TRNS, KC_LT, KC_GT, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_AT, KC_EXLM, KC_LPRN, KC_RPRN, KC_PERC, KC_ASTR, KC_MINS, KC_PLUS, KC_COLN, KC_SCLN, KC_NO, KC_NO, KC_HASH, KC_CIRC, KC_LCBR, KC_RCBR, KC_DLR, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_UNDS, KC_BSLS, KC_PIPE, KC_EQL, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO),

    [NAV] = LAYOUT(KC_NO, KC_TRNS, KC_TRNS, LSA(KC_DOWN), LSA(KC_UP), KC_TRNS, KC_PGDN, LCTL(KC_LEFT), KC_UP, LCTL(KC_RGHT), KC_HOME, KC_NO, KC_NO, LALT(KC_TAB), LSA(KC_TAB), LALT(KC_DOWN), LALT(KC_UP), KC_TRNS, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_NO, KC_NO, KC_TRNS, KC_TRNS, LCA(KC_DOWN), LCA(KC_UP), KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_PSCR, KC_SCRL, KC_PAUS, KC_CAPS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_INS, KC_DEL, KC_NO),

    [NUM] = LAYOUT(KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_TRNS, KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS, KC_NO, KC_NO, KC_F5, KC_F6, KC_F7, KC_F8, KC_TRNS, KC_TRNS, KC_4, KC_5, KC_6, KC_TRNS, KC_NO, KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_1, KC_2, KC_3, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_0, KC_NO),

	[MODS] = LAYOUT(KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RCTL, KC_RALT, KC_RGUI, KC_NO, KC_NO, OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, OSM(MOD_RCTL), OSM(MOD_RALT), OSM(MOD_RGUI), KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, OS_CLEAR, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO),

	[ADJUST] = LAYOUT(KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, DT_DOWN, DT_PRNT, DT_UP, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO) 
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OS_CLEAR:
			if (record->event.pressed) {
				clear_oneshot_layer_state(ONESHOT_PRESSED);
				clear_oneshot_mods();
			} else {
			}
			break;
        }
    return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, SYM, NAV, ADJUST);
}

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
  if (is_keyboard_master())
  {
    // QMK Logo and version information
    // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    // clang-format on

    oled_write_P(qmk_logo, false);
    oled_write_P(PSTR("Kyria rev2.1"), false);

	// Write host Caps Lock LED Status *or* Caps Word status, with Caps Word overriding Caps Lock
	if (is_caps_word_on()) {
			oled_write_P(PSTR(" CAPWRD \n\n"), false);
		} else {
			led_t led_usb_state = host_keyboard_led_state();
    		oled_write_P(led_usb_state.caps_lock ? PSTR(" CAPLCK \n\n") : PSTR("       \n\n"), false);
		}
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case DEFAULT:
            oled_write_P(PSTR("BASE\n\n"), false);
            break;
        case SYM:
            oled_write_P(PSTR("SYM \n\n"), false);
            break;
        case NAV:
            oled_write_P(PSTR("NAV \n\n"), false);
            break;
        case NUM:
            oled_write_P(PSTR("NUM \n\n"), false);
            break;
		case MODS:
            oled_write_P(PSTR("MODS\n\n"), false);
            break;
		case ADJUST:
            oled_write_P(PSTR("ADJ \n\n"), false);
            break;
        default:
            oled_write_P(PSTR("??? \n\n"), false);
    }
    
	// Modifier Status
	uint8_t mod_state = get_oneshot_mods();
		oled_write_P(PSTR("CMD "), mod_state & MOD_MASK_GUI);
		oled_write_P(PSTR(" ALT "), mod_state & MOD_MASK_ALT);
		oled_write_P(PSTR(" CTL"), mod_state & MOD_MASK_CTRL);
    // Write host Keyboard LED Status to OLEDs
    /*led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(led_usb_state.num_lock ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state.caps_lock ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);*/
  }
  else
  {
    render_deer();
  }

  return false;
}
#endif

LEADER_EXTERNS();

void matrix_scan_user(void) {
	LEADER_DICTIONARY() {
		leading = false;
		leader_end();
		//ESC
		SEQ_ONE_KEY(KC_Q) {
			tap_code(KC_ESC);
		}
		//CAPS WORD
		SEQ_TWO_KEYS(KC_C, KC_W) {
			caps_word_toggle();
		}
		//CAPS LOCK
		SEQ_TWO_KEYS(KC_C, KC_L) {
			tap_code(KC_CAPS);
		}
		//CLOSE WINDOW
		SEQ_TWO_KEYS(KC_Q, KC_T) {
			tap_code16(A(KC_F4));
		}
		//CUT
		SEQ_ONE_KEY(KC_X) {
			tap_code16(C(KC_X));
		}
		//COPY
		SEQ_ONE_KEY(KC_C) {
			tap_code16(C(KC_C));
		}
		//PASTE
		SEQ_ONE_KEY(KC_V) {
			tap_code16(C(KC_V));
		}
		//UNDO
		SEQ_ONE_KEY(KC_Z) {
			tap_code16(C(KC_Z));
		}
		//REDO
		SEQ_ONE_KEY(KC_Y) {
			tap_code16(C(KC_Y));
		}
		//SAVE
		SEQ_ONE_KEY(KC_S) {
			tap_code16(C(KC_S));
		}
		//SAVE AS
		SEQ_TWO_KEYS(KC_S, KC_A) {
			tap_code16(C(S(KC_S)));
		}
		//SHOW DESKTOP
		SEQ_ONE_KEY(KC_D) {
			tap_code16(G(KC_D));
		}
		//SELECT ALL
		SEQ_ONE_KEY(KC_A) {
			tap_code16(C(KC_A));
		}
		//FIND
		SEQ_ONE_KEY(KC_F) {
			tap_code16(C(KC_F));
		}
		//SCREENSHOT
		SEQ_TWO_KEYS(KC_S, KC_C) {
			tap_code16(S(G(KC_S)));
		}
		//BLOSSOM
		SEQ_FOUR_KEYS(KC_M, KC_A, KC_R, KC_I)
			SEND_STRING(":blossom:");
	}
}