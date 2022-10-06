const key_override_t brightness_up_over= ko_make_basic(MOD_MASK_CTRL, KC_VOLU, KC_BRIU);
const key_override_t brightness_down_over= ko_make_basic(MOD_MASK_CTRL, KC_VOLD, KC_BRID);

const key_override_t next_fastforward_over= ko_make_basic(MOD_MASK_CTRL, KC_MNXT, KC_MFFD);
const key_override_t prev_rewind_do_ver= ko_make_basic(MOD_MASK_CTRL, KC_MPRV, KC_MRWD);

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_CTRL, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&brightness_up_over,
	&brightness_down_over,
	&next_fastforward_over,
	&prev_rewind_do_ver,
	&delete_key_override,
	NULL // Null terminate the array of overrides!
};
