// Copyright 2022 ShamesTik (@ShamesTik)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "sendstring_german.h"

#include "keeb_macro.h"
#include "keeb_tapdance.h"
#include "keeb_keyoverride.h"
#include "unicode.c"

enum layers {
    BASE,
    SPACE_FN,
    CAPS_FN,
    FN,
    AUSSIE,
    SUPER,
    CLEAR,
};

bool isRecording = false;

void dynamic_macro_record_start_user(void) { isRecording = true; }
void dynamic_macro_record_end_user(int8_t direction) { isRecording = false; }

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write_P(PSTR("BASE     "), false);
            break;
        case SPACE_FN:
            oled_write_P(PSTR("SPACE    "), false);
            break;
        case CAPS_FN:
            oled_write_P(PSTR("CAPS_FN  "), false);
            break;
        case FN:
            oled_write_P(PSTR("FN       "), false);
            break;
        case AUSSIE:
            oled_write_P(PSTR("AUSSIE   "), false);
            break;
        case SUPER:
            oled_write_P(PSTR("TINY    "), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }
    oled_write_P(isRecording ? PSTR("\tREC\n") : PSTR("    \n"), false);
    // oled_write_P(PSTR("\n"), false);

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    oled_write_P(PSTR("\nWPM: "), false);
    oled_write(get_u8_str(get_current_wpm(), ' '), false);

    return false;
}
#endif

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case BASE:
            if (index == 0) {
                if (clockwise) {
                    tap_code(KC_UP);
                } else {
                    tap_code(KC_DOWN);
                }
            }
            break;
        case SPACE_FN:
            if (index == 0) {
                if (clockwise) {
                    tap_code_delay(KC_VOLU, 10);
                } else {
                    tap_code_delay(KC_VOLD, 10);
                }
            }
            break;
        case CAPS_FN:
            if (index == 0) {
                if (clockwise) {
                    tap_code(KC_WH_U);
                } else {
                    tap_code(KC_WH_D);
                }
            }
            break;
        case FN:
            if (index == 0) {
                if (clockwise) {
                    tap_code(KC_LEFT);
                } else {
                    tap_code(KC_RIGHT);
                }
            }
            break;
    }
    return false;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE]  = LAYOUT(
        KC_1,                           KC_ESC,  KC_F1,  KC_F2,   KC_F3,  KC_F4,  KC_F5, KC_F6, KC_F7, KC_F8, KC_F9,      KC_F10,KC_F11, KC_F12, KC_PSCR,KC_PPLS, KC_PMNS,
        KC_VOLD,KC_VOLU,                KC_GRV,  KC_1,   KC_2,    KC_3,   KC_4,   KC_5,  KC_6,                            KC_7,  KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL,  KC_BSPC, KC_INS,
        KC_MPRV,KC_MNXT,                KC_TAB,  KC_Q,   KC_W,    KC_E,   KC_R,   KC_T,                                   KC_Y,  KC_U,   KC_I,   KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_DEL,
        DM_RSTP,KC_MUTE,          LT(2, KC_ESC), KC_A,   KC_S,    KC_D,   KC_F,   KC_G,                                   KC_H,  KC_J,   KC_K,   KC_L,   KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT, KC_PGUP,
        DM_PLY1, DM_PLY2,               KC_LSFT, KC_NUBS,KC_Z,    KC_X,   KC_C,   KC_V,  KC_B,                            KC_N,  KC_M,   KC_COMM,KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN,
        MAIL,   KC_2,                   KC_LCTL, TD(CT_WIN),KC_LALT, KC_SPC, MO(SPACE_FN),                                KC_SPC, KC_SPC, KC_RALT,MO(FN),  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
        ),
[SPACE_FN] = LAYOUT(
        QK_BOOT,                        KC_ESC,  KC_F13, KC_F14,  KC_F15, KC_F16, KC_F17,                                KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, _______, KC_HOME, KC_END,
        QK_BOOT, _______,               _______, KC_6,   KC_7,    KC_8,   KC_9,   KC_0, _______,                         _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,               _______, _______, KC_UP,  KC_ENT,  KC_BSPC,KC_DEL,                                _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,               KC_CAPS, KC_LEFT,KC_DOWN, KC_RGHT, _______,_______,                               KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT,  _______, _______, _______, _______, _______,
        _______, _______, OSM(MOD_LCTL|MOD_LSFT),_______,_______, _______, _______,_______,  _______,                     _______, _______, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2,
        _______, _______,               KC_LOCK, _______, _______, _______, _______,                                       _______,_______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
        ),
[CAPS_FN]  = LAYOUT(
        _______,                        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,               _______, KC_Z, KC_U, KC_I, KC_O, KC_P, KC_M,                                     _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______,               _______, RALT(KC_Q), LSFT(KC_SLSH), RALT(KC_8), RALT(KC_9), LSFT(KC_NUHS),                   LSFT(KC_1), KC_NUBS, LSFT(KC_NUBS), LSFT(KC_0), LSFT(KC_6), _______, _______, _______,
        DM_REC1, DM_REC2,               _______, RALT(KC_MINS), LSFT(KC_7), RALT(KC_7), RALT(KC_0), LSFT(KC_RBRC),       LSFT(KC_MINS), LSFT(KC_8), LSFT(KC_9), KC_PMNS, LSFT(KC_DOT), RALT(KC_Q), _______, _______, _______,
        _______, _______,               _______, _______, KC_NUHS, LSFT(KC_4), RALT(KC_NUBS), RALT(KC_RBRC), BACKTIK,    KC_PPLS, LSFT(KC_5), LSFT(KC_2), LSFT(KC_NUHS), LSFT(KC_COMM), _______, _______, _______,
        _______, _______,               _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______, _______, _______
        ),
[FN]       = LAYOUT(
        _______,                        _______, TG(AUSSIE), TG(SUPER),  _______,  _______, _______, _______,                   _______, _______, _______, _______,  _______, _______, KC_NLCK, KC_CAPS, KC_SLCK,
        _______, _______,               _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______,  _______, _______, _______, _______, _______,
        _______, _______,               _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,                            _______, _______, _______,  _______,  _______, _______, _______, _______,
        _______, _______,               _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,                            _______, _______, _______,  _______,  _______, _______, _______, _______, QK_BOOT,
        _______, _______,               _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______,  KC_WH_D,  KC_WH_U, _______, KC_WH_U, _______,
        _______, _______,               _______, _______, _______, _______, _______,                                     _______, _______, _______,  _______,  _______, KC_WH_L, KC_WH_D, KC_WH_R
        ),
[AUSSIE]       = LAYOUT(
        _______,                        TO(BASE), X(SNEK), _______,  _______,  _______, _______, _______,                   _______, _______, _______, _______,  _______, _______, _______, _______, _______,
        _______,_______,                _______,  X(AUSSIE_1),   X(AUSSIE_2),    X(AUSSIE_3),   X(AUSSIE_4),   X(AUSSIE_5),  X(AUSSIE_6),  X(AUSSIE_7),  X(AUSSIE_8),   X(AUSSIE_9),   X(AUSSIE_0),   _______, _______,  _______, _______,
        _______,_______,                _______,  X(AUSSIE_Q),   X(AUSSIE_W),    X(AUSSIE_E),   X(AUSSIE_R),   X(AUSSIE_T),            X(AUSSIE_Z),  X(AUSSIE_U),   X(AUSSIE_I),   X(AUSSIE_O),   X(AUSSIE_P),    _______, _______, _______,
        _______,_______,          LT(2, KC_ESC), X(AUSSIE_A),   X(AUSSIE_S),    X(AUSSIE_D),   X(AUSSIE_F),   X(AUSSIE_G),             X(AUSSIE_H),  X(AUSSIE_J),   X(AUSSIE_K),   X(AUSSIE_L),   _______, _______, _______, _______, _______,
        _______,_______,               KC_LSFT, _______, X(AUSSIE_Y),    X(AUSSIE_X),   X(AUSSIE_C),   X(AUSSIE_V),  X(AUSSIE_B),      X(AUSSIE_N),  X(AUSSIE_M),   _______,_______, _______, _______, _______, _______,
        _______,_______,                _______, _______,_______, KC_SPC, MO(SPACE_FN),                                KC_SPC, KC_SPC, KC_RALT,MO(FN),  _______, _______, _______, _______
        ),

[SUPER]       = LAYOUT(
        _______,                        TO(BASE), _______, _______,  _______,  _______, _______, _______,                   _______, _______, _______, _______,  _______, _______, _______, _______, _______,
        _______,_______,                _______,  X(SUPER_1),   X(SUPER_2),    X(SUPER_3),   X(SUPER_4),   X(SUPER_5),  X(SUPER_6),  X(SUPER_7),  X(SUPER_8),   X(SUPER_9),   X(SUPER_0),   _______, _______,  _______, _______,
        _______,_______,                _______,  X(SUPER_Q),   X(SUPER_W),    X(SUPER_E),   X(SUPER_R),   X(SUPER_T),            X(SUPER_Z),  X(SUPER_U),   X(SUPER_I),   X(SUPER_O),   X(SUPER_P),    _______, _______, _______,
        _______,_______,          LT(2, KC_ESC), X(SUPER_A),   X(SUPER_S),    X(SUPER_D),   X(SUPER_F),   X(SUPER_G),             X(SUPER_H),  X(SUPER_J),   X(SUPER_K),   X(SUPER_L),   _______, _______, _______, _______, _______,
        _______,_______,               KC_LSFT, _______, X(SUPER_Y),    X(SUPER_X),   X(SUPER_C),   X(SUPER_V),  X(SUPER_B),      X(SUPER_N),  X(SUPER_M),   _______,_______, _______, _______, _______, _______,
        _______,_______,                _______, _______,_______, KC_SPC, MO(SPACE_FN),                                KC_SPC, KC_SPC, KC_RALT,MO(FN),  _______, _______, _______, _______
        ),
[CLEAR]       = LAYOUT(
        _______,                        _______, _______, _______,  _______,  _______, _______, _______,                   _______, _______, _______, _______,  _______, _______, _______, _______, KC_SLCK,
        _______, _______,               _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______,  _______, _______, _______, _______, _______,
        _______, _______,               _______, _______,_______, _______, _______, _______,                            _______, _______, _______,  _______,  _______, _______, _______, _______,
        _______, _______,               _______, _______, _______, _______, _______, _______,                            _______, _______, _______,  _______,  _______, _______, _______, _______, QK_BOOT,
        _______, _______,               _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______,  _______,  _______, _______, _______, _______,
        _______, _______,               _______, _______, _______, _______, _______,                                     _______, _______, _______,  _______,  _______, _______, _______, _______
        )
};
