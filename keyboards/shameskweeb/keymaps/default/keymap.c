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
    TINY,
    WIDE,
    SCRIPT, // doesnt work 
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
         case TINY:
            oled_write_P(PSTR("TINY    "), false);
            break;
       case SCRIPT:
            oled_write_P(PSTR("SCRIPT  "), false);
            break;

        case WIDE:
            oled_write_P(PSTR("WIDE    "), false);
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
        XXXXXXX,                        XXXXXXX, TO(AUSSIE), TO(TINY),TO(WIDE), TO(SCRIPT), XXXXXXX, XXXXXXX,                   UC_M_WC, UC_M_LN, UC_M_MA, UC_M_EM,  XXXXXXX, XXXXXXX, KC_NLCK, KC_CAPS, KC_SLCK,
        XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,               XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,               XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX,  KC_WH_D,  KC_WH_U, XXXXXXX, KC_WH_U, XXXXXXX,
        XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R
        ),
[TINY]       = LAYOUT(
        _______,                        TO(BASE), _______, _______,  _______,  _______, _______, _______,                   _______, _______, _______, _______,  _______, _______, _______, _______, _______,
        _______,_______,                _______,  X(TINY_1),   X(TINY_2),    X(TINY_3),   X(TINY_4),   X(TINY_5),  X(TINY_6),  X(TINY_7),  X(TINY_8),   X(TINY_9),   X(TINY_0),   _______, _______,  _______, _______,
        _______,_______,                _______,  X(TINY_Q),   X(TINY_W),    X(TINY_E),   X(TINY_R),   X(TINY_T),            X(TINY_Z),  X(TINY_U),   X(TINY_I),   X(TINY_O),   X(TINY_P),    _______, _______, _______,
        _______,_______,          LT(2, KC_ESC), X(TINY_A),   X(TINY_S),    X(TINY_D),   X(TINY_F),   X(TINY_G),             X(TINY_H),  X(TINY_J),   X(TINY_K),   X(TINY_L),   _______, _______, _______, _______, _______,
        _______,_______,               KC_LSFT, _______, X(TINY_Y),    X(TINY_X),   X(TINY_C),   X(TINY_V),  X(TINY_B),      X(TINY_N),  X(TINY_M),   _______,_______, _______, _______, _______, _______,
        _______,_______,                _______, _______,_______, KC_SPC, MO(SPACE_FN),                                KC_SPC, KC_SPC, KC_RALT,MO(FN),  _______, _______, _______, _______
        ),
[WIDE]       = LAYOUT(
        _______,                        TO(BASE), _______, _______,  _______,  _______, _______, _______,                   _______, _______, _______, _______,  _______, _______, _______, _______, _______,
        _______,_______,                _______,  X(WIDE_1),   X(WIDE_2),    X(WIDE_3),   X(WIDE_4),   X(WIDE_5),  X(WIDE_6),  X(WIDE_7),  X(WIDE_8),   X(WIDE_9),   X(WIDE_0),   _______, _______,  _______, _______,
        _______,_______,                _______,  XP(WIDE_S_Q, WIDE_L_Q),   XP(WIDE_S_W, WIDE_L_W),    XP(WIDE_S_E, WIDE_L_E),   XP(WIDE_S_R, WIDE_L_R),   XP(WIDE_S_T, WIDE_L_T),            XP(WIDE_S_Z, WIDE_L_Z),  XP(WIDE_S_U, WIDE_L_U),   XP(WIDE_S_I, WIDE_L_I),   XP(WIDE_S_O, WIDE_L_O),   XP(WIDE_S_P, WIDE_L_P),    _______, _______, _______,
        _______,_______,          LT(2, KC_ESC), XP(WIDE_S_A, WIDE_L_A),   XP(WIDE_S_S, WIDE_L_S),    XP(WIDE_S_D, WIDE_L_D),   XP(WIDE_S_F, WIDE_L_F),   XP(WIDE_S_G, WIDE_L_G),             XP(WIDE_S_H, WIDE_L_H),  XP(WIDE_S_J, WIDE_L_J),   XP(WIDE_S_K, WIDE_L_K),   XP(WIDE_S_L, WIDE_L_L),   _______, _______, _______, _______, _______,
        _______,_______,               KC_LSFT, _______, XP(WIDE_S_Y, WIDE_L_Y),    XP(WIDE_S_X, WIDE_L_X),   XP(WIDE_S_C, WIDE_L_C),   XP(WIDE_S_V, WIDE_L_V),  XP(WIDE_S_B, WIDE_L_B),      XP(WIDE_S_N, WIDE_L_N),  XP(WIDE_S_M, WIDE_L_M),   _______,_______, _______, _______, _______, _______,
        _______,_______,                _______, _______,_______, KC_SPC, MO(SPACE_FN),                                KC_SPC, KC_SPC, KC_RALT,MO(FN),  _______, _______, _______, _______
        ),
[SCRIPT]       = LAYOUT(
        _______,                        TO(BASE), _______, _______,  _______,  _______, _______, _______,                   _______, _______, _______, _______,  _______, _______, _______, _______, _______,
        _______,_______,                _______,  _______,   _______,    _______,   _______,   _______,  _______,  _______,  _______,   _______,   _______,   _______, _______,  _______, _______,
        _______,_______,                _______,  XP(SCRIPT_S_Q, SCRIPT_L_Q),   XP(SCRIPT_S_W, SCRIPT_L_W),    XP(SCRIPT_S_E, SCRIPT_L_E),   XP(SCRIPT_S_R, SCRIPT_L_R),   XP(SCRIPT_S_T, SCRIPT_L_T),            XP(SCRIPT_S_Z, SCRIPT_L_Z),  XP(SCRIPT_S_U, SCRIPT_L_U),   XP(SCRIPT_S_I, SCRIPT_L_I),   XP(SCRIPT_S_O, SCRIPT_L_O),   XP(SCRIPT_S_P, SCRIPT_L_P),    _______, _______, _______,
        _______,_______,          LT(2, KC_ESC), XP(SCRIPT_S_A, SCRIPT_L_A),   XP(SCRIPT_S_S, SCRIPT_L_S),    XP(SCRIPT_S_D, SCRIPT_L_D),   XP(SCRIPT_S_F, SCRIPT_L_F),   XP(SCRIPT_S_G, SCRIPT_L_G),             XP(SCRIPT_S_H, SCRIPT_L_H),  XP(SCRIPT_S_J, SCRIPT_L_J),   XP(SCRIPT_S_K, SCRIPT_L_K),   XP(SCRIPT_S_L, SCRIPT_L_L),   _______, _______, _______, _______, _______,
        _______,_______,               KC_LSFT, _______, XP(SCRIPT_S_Y, SCRIPT_L_Y),    XP(SCRIPT_S_X, SCRIPT_L_X),   XP(SCRIPT_S_C, SCRIPT_L_C),   XP(SCRIPT_S_V, SCRIPT_L_V),  XP(SCRIPT_S_B, SCRIPT_L_B),      XP(SCRIPT_S_N, SCRIPT_L_N),  XP(SCRIPT_S_M, SCRIPT_L_M),   _______,_______, _______, _______, _______, _______,
        _______,_______,                _______, _______,_______, KC_SPC, MO(SPACE_FN),                                KC_SPC, KC_SPC, KC_RALT,MO(FN),  _______, _______, _______, _______
        ),
[AUSSIE]       = LAYOUT(
        _______,                        TO(BASE), X(SNEK), _______,  _______,  _______, _______, _______,                   _______, _______, _______, _______,  _______, _______, _______, _______, _______,
        _______,_______,                _______,  X(AUSSIE_1),   X(AUSSIE_2),    X(AUSSIE_3),   X(AUSSIE_4),   X(AUSSIE_5),  KC_9,  X(AUSSIE_7),  KC_8,   KC_6,   KC_0,   _______, _______,  _______, _______,
        _______,_______,                _______,  KC_B,   X(AUSSIE_W),    X(AUSSIE_E),   X(AUSSIE_R),   X(AUSSIE_T),            KC_Y,  KC_N,   X(AUSSIE_I),   KC_O,   KC_D,    _______, _______, _______,
        _______,_______,          LT(2, KC_ESC), X(AUSSIE_A),   KC_S,    KC_P,   X(AUSSIE_F),   X(AUSSIE_G),             X(AUSSIE_H),  X(AUSSIE_J),   X(AUSSIE_K),   KC_L,   _______, _______, _______, _______, _______,
        _______,_______,               KC_LSFT, _______, X(AUSSIE_Y),    X(AUSSIE_X),   X(AUSSIE_C),   X(AUSSIE_V),  KC_Q,      KC_U,  X(AUSSIE_M),   _______,_______, _______, _______, _______, _______,
        _______,_______,                _______, _______,_______, KC_SPC, MO(SPACE_FN),                                KC_SPC, KC_SPC, KC_RALT,MO(FN),  _______, _______, _______, _______
        )
//
// [CLEAR]       = LAYOUT(
//         _______,                        _______, _______, _______,  _______,  _______, _______, _______,                   _______, _______, _______, _______,  _______, _______, _______, _______, KC_SLCK,
//         _______, _______,               _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______,  _______, _______, _______, _______, _______,
//         _______, _______,               _______, _______,_______, _______, _______, _______,                            _______, _______, _______,  _______,  _______, _______, _______, _______,
//         _______, _______,               _______, _______, _______, _______, _______, _______,                            _______, _______, _______,  _______,  _______, _______, _______, _______, QK_BOOT,
//         _______, _______,               _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______,  _______,  _______, _______, _______, _______,
//         _______, _______,               _______, _______, _______, _______, _______,                                     _______, _______, _______,  _______,  _______, _______, _______, _______
//         )
};
