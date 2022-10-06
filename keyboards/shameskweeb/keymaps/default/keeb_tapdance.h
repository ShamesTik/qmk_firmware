enum { TD_WIN, CT_FNWIN, CT_WIN, };

// void fnwin_finished(qk_tap_dance_state_t *state, void *user_data) {
//     if (state->count == 1) {
//         register_code16();
//     } else {
//         register_code(KC_LGUI);
//     }
// }

// void fnwin_reset(qk_tap_dance_state_t *state, void *user_data) {
//     if (state->count == 1) {
//         unregister_code16();
//     } else {
//         unregister_code(KC_LGUI);
//     }
// }

void wingui_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_LGUI);
    } else {
        register_code16(S(KC_F22));
    }
}

void wingui_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_LGUI);
    } else {
        unregister_code16(S(KC_F22));
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Windows, twice for F22
    [TD_WIN] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_F22),
    // Tap once for Windows, twice for Shift-F22
    [CT_WIN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, wingui_finished, wingui_reset),
    // [CT_FNWIN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, fnwin_finished, fnwin_reset),
};
