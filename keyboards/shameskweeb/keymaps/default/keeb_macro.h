enum custom_keycodes { MAIL = SAFE_RANGE, BACKTIK, SINGLEGRAVE };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    switch (keycode) {
        case MAIL:
            if (record->event.pressed) {
                SEND_STRING("REMOVEDMAIL");
            } else {
                // when keycode MAIL is released
            }
            break;
        case BACKTIK:
            if (record->event.pressed) {
                register_code16(LSFT(KC_EQL));
                unregister_code16(LSFT(KC_EQL));
            } else {
                register_code(KC_SPC);
                unregister_code(KC_SPC);
            }
            break;
        case SINGLEGRAVE:
            if (record->event.pressed) {
                register_code(KC_GRAVE);
                unregister_code(KC_GRAVE);
            } else {
                register_code(KC_SPC);
                unregister_code(KC_SPC);
            }
            break;
    }
    return true;
}
