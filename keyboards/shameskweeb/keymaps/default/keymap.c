// Copyright 2022 ShamesTik (@ShamesTik)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "sendstring_german.h"

#include "keeb_macro.h"
#include "keeb_tapdance.h"
#include "keeb_keyoverride.h"

enum layers {
    BASE,
    SPACE_FN,
    CAPS_FN,
    FN,
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case BASE:
            if (index == 0) {
                if (clockwise) {
                    tap_code_delay(KC_UP, 10);
                } else {
                    tap_code_delay(KC_DOWN, 10);
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
    }
    return false;
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write_P(PSTR("BASE\n"), false);
            break;
        case SPACE_FN:
            oled_write_P(PSTR("SPACE\n"), false);
            break;
        case CAPS_FN:
            oled_write_P(PSTR("CAPS_FN\n"), false);
            break;
        case FN:
            oled_write_P(PSTR("FN\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}

#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE]  = LAYOUT(
    KC_1,                            KC_ESC,  KC_F1,  KC_F2,   KC_F3,  KC_F4,  KC_F5, KC_F6, KC_F7, KC_F8, KC_F9,      KC_F10,KC_F11, KC_F12, KC_PSCR,KC_PPLS, KC_PMNS,
    KC_VOLD,KC_VOLU,                KC_GRV,  KC_1,   KC_2,    KC_3,   KC_4,   KC_5,  KC_6,                            KC_7,  KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL,  KC_BSPC, KC_INS,
    KC_MPRV,KC_MNXT,                KC_TAB,  KC_Q,   KC_W,    KC_E,   KC_R,   KC_T,                                   KC_Y,  KC_U,   KC_I,   KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_DEL,
    DM_RSTP,KC_MUTE,          LT(2, KC_ESC), KC_A,   KC_S,    KC_D,   KC_F,   KC_G,                                   KC_H,  KC_J,   KC_K,   KC_L,   KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT, KC_PGUP,
DM_PLY1, DM_PLY2,               KC_LSFT, KC_NUBS,KC_Z,    KC_X,   KC_C,   KC_V,  KC_B,                            KC_N,  KC_M,   KC_COMM,KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN,
MAIL,   KC_2,                   KC_LCTL, TD(CT_WIN),KC_LALT, KC_SPC, MO(SPACE_FN),                                          KC_SPC, KC_SPC,        KC_RALT,MO(FN),  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
),
[SPACE_FN] = LAYOUT(
    QK_BOOT,                KC_ESC,  KC_F13, KC_F14,  KC_F15, KC_F16, KC_F17,                                KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, _______, KC_HOME, KC_END,
    QK_BOOT, _______,               _______, KC_6,   KC_7,    KC_8,   KC_9,   KC_0, _______,                         _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______,               _______, _______, KC_UP,  KC_ENT,  KC_BSPC,KC_DEL,                                _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______,               KC_CAPS, KC_LEFT,KC_DOWN, KC_RGHT,_______,_______,                               KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT,  _______, _______, _______, _______, _______,
    DM_REC1, DM_REC2, OSM(MOD_LCTL|MOD_LSFT),_______,_______, _______,_______,_______,  _______,                     _______, _______, _______, _______, _______, KC_BTN1, KC_WH_U, KC_BTN2,
_______, _______,                   KC_LOCK, _______,_______, _______,_______,                                       _______,_______,          _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_R
),
[CAPS_FN]  = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______,               _______, KC_Z, KC_U, KC_I, KC_O, KC_P, KC_M,                                     _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______,               _______, LSFT(KC_SLSH), RALT(KC_8), RALT(KC_9), LSFT(KC_NUHS),                   LSFT(KC_1), KC_NUBS, LSFT(KC_NUBS), LSFT(KC_0), LSFT(KC_6), _______, _______, _______,
    _______, _______,               _______, RALT(KC_MINS), LSFT(KC_7), RALT(KC_7), RALT(KC_0), LSFT(KC_RBRC),       LSFT(KC_MINS), LSFT(KC_8), LSFT(KC_9), KC_PMNS, LSFT(KC_DOT), RALT(KC_Q), _______, _______, _______,
    _______, _______,               _______, _______, KC_NUHS, LSFT(KC_4), RALT(KC_NUBS), RALT(KC_RBRC), BACKTIK,    KC_PPLS, LSFT(KC_5), LSFT(KC_2), LSFT(KC_NUHS), LSFT(KC_COMM), _______, _______, _______,
    _______, _______,               _______, _______, _______, _______, _______,                                     _______, _______,          _______, _______, _______, _______, _______, _______
),
[FN]       = LAYOUT(
    _______, _______, BL_TOGG, BL_INC,  BL_DEC,  BL_STEP, _______, _______,                   RGB_TOG, RGB_MOD, RGB_RMOD, _______,  RGB_M_K, RGB_M_X, KC_CAPS, KC_NLCK, KC_SLCK,
    _______, _______,               _______, _______, _______, _______, _______, _______, _______,                   RGB_M_P, RGB_M_B, RGB_M_R,  RGB_M_SW, RGB_M_SN, RGB_M_G, RGB_M_T, _______,
    _______, _______,               _______, _______, KC_MS_U, _______, RGB_VAI, RGB_VAD,                            RGB_HUI, RGB_HUD, _______,  _______,  _______, _______, _______, _______,
    _______, _______,               KC_CAPS, KC_MS_L, KC_MS_D, KC_MS_R, RGB_SPI, RGB_SPD,                            RGB_SAI, RGB_SAD, _______,  _______,  _______, _______, _______, _______, RESET,
    _______, _______,               _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______,  KC_WH_D,  KC_WH_U, _______, _______, _______,
    GE_NORM, GE_SWAP,               _______, _______, _______, _______, _______,                                     _______, _______,          _______,  _______,  _______, _______, _______, EEP_RST
)
};
