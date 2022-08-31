// Copyright 2022 ShamesTik (@ShamesTik)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
enum layers{
  _QWERTY,
  _FN,
  _ADJ
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    }
//    else if (index == 1) { /* Second encoder */
//        if (clockwise) {
//            rgb_matrix_increase_hue();
//        } else {
//            rgb_matrix_decrease_hue();
//        }
//    }
    return false;
}
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_1, KC_2,
        KC_3, KC_4,
        KC_5, KC_6,
        KC_7, KC_8
    )
//    [_FN] = LAYOUT(
//        KC_1, KC_2,
//        QK_BOOT,KC_5,
//        KC_4, KC_5,
//        TO(_QWERTY), TO(_ADJ)
//    ),
//    [_ADJ] = LAYOUT(
//        KC_1, KC_2,
//        KC_4, KC_5,
//        KC_4, KC_5,
//        TO(_QWERTY), TO(_FN)
//    )
};

//const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//[_QWERTY] = LAYOUT(
//    LT(_FN,KC_1), KC_2, KC_3,
//    KC_4, KC_5, KC_6,
//    KC_4, KC_5, KC_6,
//    KC_1, KC_2, KC_3
//),
//[_FN] = LAYOUT(
//    KC_1, KC_2, QK_BOOT,
//    KC_4, KC_5, KC_6,
//    KC_4, KC_5, KC_6,
//    TO(_QWERTY), TO(_ADJ), KC_1
//),
//[_ADJ] = LAYOUT(
//    KC_1, KC_2,KC_3,
//    KC_4, KC_5, KC_6,
//    KC_1, KC_2, KC_3,
//    TO(_QWERTY), TO(_FN), KC_1
//)
//};
//
#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("FN\n"), false);
            break;
        case _ADJ:
            oled_write_P(PSTR("ADJ\n"), false);
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
