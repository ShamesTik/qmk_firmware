enum custom_keycodes { MAIL = SAFE_RANGE, BACKTIK, SINGLEGRAVE };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MAIL:
            if (record->event.pressed) {
                SEND_STRING("TODO: my emailadress");

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
