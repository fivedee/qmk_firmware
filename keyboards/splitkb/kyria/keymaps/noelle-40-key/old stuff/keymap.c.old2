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

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

enum layers {
    DEFAULT = 0,
    LOWER,
    RAISE,
    ADJUST,
    MODS
};

enum custom_keycodes {
    TRUE_WHITE = SAFE_RANGE,
    PALE_YELLOW,
    BLOSSOM,
    BLUISH_WHITE,
    RED,
    PLEAD,
    EYES,
    P_HEART,
    KISS,
    PENS,
    SUS,
    WEH,
    FLUSH,
    POGG,
    HUG,
    THINK,
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

    [DEFAULT] = LAYOUT(KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO, LSFT_T(KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO, KC_NO, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO, KC_NO, OSL(4), KC_ESC, KC_SPC, MO(1), MO(2), KC_ENT, KC_BSPC, OSL(4), KC_NO),

    [LOWER] = LAYOUT(KC_NO, KC_GRV, KC_TILD, KC_LBRC, KC_RBRC, KC_AMPR, KC_TRNS, KC_7, KC_8, KC_9, KC_PLUS, KC_NO, KC_TRNS, KC_AT, KC_EXLM, KC_LPRN, KC_RPRN, KC_PERC, KC_MINS, KC_4, KC_5, KC_6, KC_ASTR, KC_TRNS, KC_NO, KC_HASH, KC_CIRC, KC_LCBR, KC_RCBR, KC_DLR, KC_NO, KC_NO, KC_NO, KC_NO, KC_UNDS, KC_1, KC_2, KC_3, KC_EQL, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_NO),

    [RAISE] = LAYOUT(KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_TRNS, KC_PGDN, LCTL(KC_LEFT), KC_UP, LCTL(KC_RGHT), KC_HOME, KC_NO, KC_TRNS, KC_F5, KC_F6, KC_F7, KC_F8, KC_TRNS, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_TRNS, KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_PSCR, KC_SCRL, KC_PAUS, KC_CAPS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_DEL, KC_TRNS, KC_NO),

    [ADJUST] = LAYOUT(KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_NO, KC_TRNS, LCTL(KC_A), LCTL(KC_S), LGUI(KC_D), KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, DT_DOWN, DT_PRNT, DT_UP, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO),

    [MODS] = LAYOUT(KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_TRNS, KC_TRNS, LCTL(KC_Y), KC_TRNS, KC_RCTL, KC_RALT, KC_RGUI, KC_NO, KC_TRNS, OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), LCTL(KC_F), KC_TRNS, KC_TRNS, KC_TRNS, OSM(MOD_RCTL), OSM(MOD_RALT), OSM(MOD_RGUI), KC_TRNS, KC_NO, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, SGUI(KC_S), KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS, OS_CLEAR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, OS_CLEAR, KC_TRNS, KC_NO) 
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TRUE_WHITE:
            if (record->event.pressed) {
                rgblight_sethsv(HSV_TRUE_WHITE);
            } else {
            }
            break;
        case PALE_YELLOW:
            if (record->event.pressed) {
                rgblight_sethsv(HSV_PALE_YELLOW);
            } else {
            }
            break;
        case BLOSSOM:
            if (record->event.pressed) {
                rgblight_sethsv(HSV_BLOSSOM);
            } else {
            }
            break;
        case BLUISH_WHITE:
            if (record->event.pressed) {
                rgblight_sethsv(HSV_BLUISH_WHITE);
            } else {
            }
            break;
        case RED:
            if (record->event.pressed) {
                rgblight_sethsv(HSV_RED);
            } else {
            }
            break;
        case PLEAD:
            if (record->event.pressed) {
                SEND_STRING(":pleading_face:");
            } else {
            }
            break;
        case EYES:
            if (record->event.pressed) {
                SEND_STRING(":eyes:");
            } else {
            }
            break;
        case P_HEART:
            if (record->event.pressed) {
                SEND_STRING(":purple_heart:");
            } else {
            }
            break;
        case KISS:
            if (record->event.pressed) {
                SEND_STRING(":kissing_heart:");
            } else {
            }
            break;
        case PENS:
            if (record->event.pressed) {
                SEND_STRING(":pensusie:");
            } else {
            }
            break;
        case SUS:
            if (record->event.pressed) {
                SEND_STRING(":SusieSus:");
            } else {
            }
            break;
        case WEH:
            if (record->event.pressed) {
                SEND_STRING(":noelleWEEHHH:");
            } else {
            }
            break;
        case FLUSH:
            if (record->event.pressed) {
                SEND_STRING(":flush:");
            } else {
            }
            break;
        case POGG:
            if (record->event.pressed) {
                SEND_STRING(":pogg:");
            } else {
            }
            break;
        case HUG:
            if (record->event.pressed) {
                SEND_STRING(":hug:");
            } else {
            }
            break;
        case THINK:
            if (record->event.pressed) {
                SEND_STRING(":thinkelle:");
            } else {
            }
            break;
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
  return update_tri_layer_state(state, LOWER, RAISE, ADJUST);
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

	// Write host Keyboard LED Status to OLEDs
	led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(led_usb_state.caps_lock ? PSTR("CAPLCK \n\n") : PSTR("       \n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case DEFAULT:
            oled_write_P(PSTR("BASE\n\n"), false);
            break;
        case LOWER:
            oled_write_P(PSTR("LOWER\n\n"), false);
            break;
        case RAISE:
            oled_write_P(PSTR("RAISE\n\n"), false);
            break;
        case ADJUST:
            oled_write_P(PSTR("ADJUST\n\n"), false);
            break;
        case MODS:
            oled_write_P(PSTR("MODS\n\n"), false);
            break;
        default:
            oled_write_P(PSTR("???\n\n"), false);
    }
    
	// Modifier Status
	uint8_t mod_state = get_oneshot_mods();
		oled_write_P(PSTR("CMD  "), mod_state & MOD_MASK_GUI);
		oled_write_P(PSTR("ALT  "), mod_state & MOD_MASK_ALT);
		oled_write_P(PSTR("CTRL "), mod_state & MOD_MASK_CTRL);
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

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // ALT TAB
        if (clockwise) {
            if (!is_alt_tab_active) {
                is_alt_tab_active = true;
                register_code(KC_LALT);
            }
            alt_tab_timer = timer_read();
            tap_code16(KC_TAB);
        } else {
            if (!is_alt_tab_active) {
                is_alt_tab_active = true;
                register_code(KC_LALT);
            }
            alt_tab_timer = timer_read();
            tap_code16(S(KC_TAB));
        }
    } else if (index == 1) {
        if (layer_state_is(DEFAULT)) {
            // Scrolling by word
            if (clockwise) {
                tap_code16(C(KC_RGHT));
            } else {
                tap_code16(C(KC_LEFT));
            }
        } else if (layer_state_is(LOWER)) {
            //Navigate between Discord channels
            if (clockwise) {
                tap_code16(A(KC_DOWN));
            } else {
                tap_code16(A(KC_UP));
            }
        } else if (layer_state_is(RAISE)) {
            //Navigate between Discord servers
            if (clockwise) {
                tap_code16(C(A(KC_DOWN)));
            } else {
                tap_code16(C(A(KC_UP)));
            }
        } else if (layer_state_is(RAISE)) {
            //Adjust RGB Brightness
            if (clockwise) {
                tap_code16(RGB_VAD);
            } else {
                tap_code16(RGB_VAI);
            }
        }
    }
    return false;
}
#endif

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 500) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}
