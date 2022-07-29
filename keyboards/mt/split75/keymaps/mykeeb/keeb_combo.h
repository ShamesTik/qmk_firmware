enum combos { MAILADDRESS, CLEAR_LINE, COMBO_LENGTH }; // COMBO_LENGTH needs to be last
uint16_t COMBO_LEN = COMBO_LENGTH;  // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM mail_address[] = {KC_M, KC_A, COMBO_END};
const uint16_t PROGMEM clear_line[]   = {KC_C, KC_D, COMBO_END};

combo_t key_combos[] = {
    [MAILADDRESS] = COMBO_ACTION(mail_address),
    [CLEAR_LINE]  = COMBO_ACTION(clear_line),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case MAILADDRESS:
            if (pressed) {
                SEND_STRING("TODO: Add Mailaddress");
            }
            break;
        case CLEAR_LINE:
            if (pressed) {
                tap_code16(KC_END);
                tap_code16(S(KC_HOME));
                tap_code16(KC_BSPC);
            }
            break;
    }
}
