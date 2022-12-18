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
    SPACEFAT_FN,
    CAPS_FN,
    FN,
    CLEAR
};

bool isRecording = false;

void dynamic_macro_record_start_user(void) {
    isRecording = true;
}
void dynamic_macro_record_end_user(int8_t direction) {
    isRecording = false;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

#ifdef OLED_ENABLE
void update_layer_status(void) {
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write_P(PSTR("BASE     "), false);
            break;
        case SPACE_FN:
            oled_write_P(PSTR("SPACE    "), false);
            break;
        case SPACEFAT_FN:
            oled_write_P(PSTR("SPACEFAT "), false);
            break;
        case CAPS_FN:
            oled_write_P(PSTR("CAPS_FN  "), false);
            break;
        case FN:
            oled_write_P(PSTR("FN       "), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}

bool oled_task_user(void) {
    update_layer_status();

    oled_write_P(isRecording ? PSTR("\tREC\n") : PSTR("    \n"), false);

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
        DM_RSTP,KC_MUTE,          LT(CAPS_FN, KC_ESC), KC_A,   KC_S,    KC_D,   KC_F,   KC_G,                             KC_H,  KC_J,   KC_K,   KC_L,   KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT, KC_PGUP,
        DM_PLY1, DM_PLY2,               KC_LSFT, KC_NUBS,KC_Z,    KC_X,   KC_C,   KC_V,  KC_B,                            KC_N,  KC_M,   KC_COMM,KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN,
        MAIL,   KC_2,                   KC_LCTL, TD(CT_WIN),KC_LALT, KC_SPC, MO(SPACE_FN),                                KC_SPC, MO(SPACEFAT_FN), KC_RALT,MO(FN),  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
        ),
[SPACE_FN] = LAYOUT(
        QK_BOOT,                        KC_ESC,  KC_F13, KC_F14,  KC_F15, KC_F16, KC_F17,                                KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, _______, KC_HOME, KC_END,
        QK_BOOT, _______,               _______, KC_6,   KC_7,    KC_8,   KC_9,   KC_0, _______,                         _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,               _______, _______, KC_UP,  KC_ENT,  KC_BSPC,KC_DEL,                               _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,               KC_CAPS, KC_LEFT,KC_DOWN, KC_RGHT, _______,_______,                              KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT,  _______, _______, _______, TURBO, _______,
        _______, _______, OSM(MOD_LCTL|MOD_LSFT),_______,_______, _______, _______,_______,  _______,                    _______, _______, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2,
        _______, _______,               KC_LOCK, _______, _______, _______, _______,                                     _______,_______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
        ),
[SPACEFAT_FN] = LAYOUT(
        _______,                        _______,  _______, _______,  _______, _______, _______,                           _______, _______, _______, _______, _______, _______, _______, KC_LNUM, KC_LCAP, KC_LSCR,
        _______, _______,               _______, KC_P1,   KC_P2,    KC_P3,   KC_P4,   KC_P5, KC_P6,                       KC_P7, KC_P8, KC_P9, KC_P0, _______, _______, _______, _______,
        _______, _______,               _______, _______, _______,  _______,  _______,_______,                            _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,               _______, _______,_______, _______, _______,_______,                               _______, _______, _______,  _______,  _______, _______, _______, _______, _______,
        _______, _______,               _______, _______,_______, _______, _______,_______,  _______,                     _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,               _______, _______, _______, _______, _______,                                      _______,_______, _______, _______, _______, _______, _______, _______
),
[CAPS_FN]  = LAYOUT(
        _______,                        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,               _______, LSA(KC_1), LSA(KC_2), LSA(KC_3), LSA(KC_4), LSA(KC_5), LSA(KC_6),       LSA(KC_7), LSA(KC_8), LSA(KC_9), LSA(KC_0), _______, _______, _______, _______,
        _______, _______,               _______, RALT(KC_Q), LSFT(KC_SLSH), RALT(KC_8), RALT(KC_9), LSFT(KC_NUHS),       LSFT(KC_1), KC_NUBS, LSFT(KC_NUBS), LSFT(KC_0), LSFT(KC_6), _______, _______, _______,
        DM_REC1, DM_REC2,               _______, RALT(KC_MINS), LSFT(KC_7), RALT(KC_7), RALT(KC_0), LSFT(KC_RBRC),       LSFT(KC_MINS), LSFT(KC_8), LSFT(KC_9), KC_PMNS, LSFT(KC_DOT), RALT(KC_Q), _______, _______, _______,
        _______, _______,               _______, _______, KC_NUHS, LSFT(KC_4), RALT(KC_NUBS), RALT(KC_RBRC), BACKTIK,    KC_PPLS, LSFT(KC_5), LSFT(KC_2), LSFT(KC_NUHS), LSFT(KC_COMM), _______, _______, _______,
        _______, _______,               _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______, _______, _______
        ),
[FN]       = LAYOUT(
        XXXXXXX,                        XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, KC_LNUM, KC_LCAP, KC_LSCR,
        XXXXXXX, XXXXXXX,               DT_PRNT, DT_UP, DT_DOWN, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,               XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,               XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX,  KC_WH_D,  KC_WH_U, XXXXXXX, KC_WH_U, XXXXXXX,
        XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R
        )
// [CLEAR]       = LAYOUT(
//         _______,                        _______, _______, _______,  _______,  _______, _______, _______,                _______, _______, _______,  _______,  _______, _______, _______, _______, KC_SLCK,
//         _______, _______,               _______, _______, _______, _______, _______, _______, _______,                  _______, _______, _______,  _______,  _______, _______, _______, _______,
//         _______, _______,               _______, _______,_______, _______, _______, _______,                            _______, _______, _______,  _______,  _______, _______, _______, _______,
//         _______, _______,               _______, _______, _______, _______, _______, _______,                           _______, _______, _______,  _______,  _______, _______, _______, _______, QK_BOOT,
//         _______, _______,               _______, _______, _______, _______, _______, _______, _______,                  _______, _______, _______,  _______,  _______, _______, _______, _______,
//         _______, _______,               _______, _______, _______, _______, _______,                                    _______, _______, _______,  _______,  _______, _______, _______, _______
//         )
};
