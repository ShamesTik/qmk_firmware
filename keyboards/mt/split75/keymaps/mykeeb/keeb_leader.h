LEADER_EXTERNS();
void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // SEQ_ONE_KEY(KC_F) {
        // SEQ_TWO_KEYS(KC_Q, KC_E) {
        // SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
        // SEND_STRING("QMK is awesome.");
        // }
        SEQ_ONE_KEY(KC_T) {
            SEND_STRING(SS_LCTRL(SS_LSFT("t")));
        }
        SEQ_TWO_KEYS(KC_A, KC_M) {
            SEND_STRING("TODO: Add Mailaddress");
        }
    }
}
