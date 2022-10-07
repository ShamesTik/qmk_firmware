enum unicode_names {
    AUSSIE_A,
    AUSSIE_B,
    AUSSIE_C,
    AUSSIE_D,
    AUSSIE_E,
    AUSSIE_F,
    AUSSIE_G,
    AUSSIE_H,
    AUSSIE_I,
    AUSSIE_J,
    AUSSIE_K,
    AUSSIE_L,
    AUSSIE_M,
    AUSSIE_N,
    AUSSIE_O,
    AUSSIE_P,
    AUSSIE_Q,
    AUSSIE_R,
    AUSSIE_S,
    AUSSIE_T,
    AUSSIE_U,
    AUSSIE_V,
    AUSSIE_W,
    AUSSIE_X,
    AUSSIE_Y,
    AUSSIE_Z,
    AUSSIE_1,
    AUSSIE_2,
    AUSSIE_3,
    AUSSIE_4,
    AUSSIE_5,
    AUSSIE_6,
    AUSSIE_7,
    AUSSIE_8,
    AUSSIE_9,
    AUSSIE_0,
    SNEK,
    SUPER_A,
    SUPER_B,
    SUPER_C,
    SUPER_D,
    SUPER_E,
    SUPER_F,
    SUPER_G,
    SUPER_H,
    SUPER_I,
    SUPER_J,
    SUPER_K,
    SUPER_L,
    SUPER_M,
    SUPER_N,
    SUPER_O,
    SUPER_P,
    SUPER_Q,
    SUPER_R,
    SUPER_S,
    SUPER_T,
    SUPER_U,
    SUPER_V,
    SUPER_W,
    SUPER_X,
    SUPER_Y,
    SUPER_Z,
    SUPER_1,
    SUPER_2,
    SUPER_3,
    SUPER_4,
    SUPER_5,
    SUPER_6,
    SUPER_7,
    SUPER_8,
    SUPER_9,
    SUPER_0,
};

const uint32_t PROGMEM unicode_map[] = {
    [AUSSIE_A] = 0x0250, // a
    [AUSSIE_B] = 'q', // a
    [AUSSIE_C] = 0x0254, // c
    [AUSSIE_D] = 'p',    // d
    [AUSSIE_E] = 0x01DD, // e
    [AUSSIE_F] = 0x025F, // f
    [AUSSIE_G] = 0x0183, // g
    [AUSSIE_H] = 0x0265, // h
    [AUSSIE_I] = 0x1D09, // i
    [AUSSIE_J] = 0x027E, // j
    [AUSSIE_K] = 0x029E, // k
    [AUSSIE_L] = 'l',    // l
    [AUSSIE_M] = 0x026F, // m
    [AUSSIE_N] = 'u',    // n
    [AUSSIE_O] = 'o',    // o
    [AUSSIE_P] = 'd',    // p
    [AUSSIE_Q] = 'b',    // q
    [AUSSIE_R] = 0x0279, // r
    [AUSSIE_S] = 's',    // s
    [AUSSIE_T] = 0x0287, // t
    [AUSSIE_U] = 'n',    // u
    [AUSSIE_V] = 0x028C, // v
    [AUSSIE_W] = 0x028D, // w
    [AUSSIE_X] = 0x2717, // x
    [AUSSIE_Y] = 0x028E, // y
    [AUSSIE_Z] = 'z',    // z
    [AUSSIE_1] = 0x0269, // 1
    [AUSSIE_2] = 0x3139, // 2
    [AUSSIE_3] = 0x0190, // 3
    [AUSSIE_4] = 0x3123, // 4
    [AUSSIE_5] = 0x03DB, // 5
    [AUSSIE_6] = '9',    // 6
    [AUSSIE_7] = 0x3125, // 7
    [AUSSIE_8] = '8',    // 8
    [AUSSIE_9] = '6',    // 9
    [AUSSIE_0] = '0',     // 0
    [SNEK]  = 0x1F40D, // 🐍
    [SUPER_A] = 0x1D43, // a
    [SUPER_B] = 0x1D47, // b
    [SUPER_C] = 0x1D9C, // c
    [SUPER_D] = 0x1D48, // d
    [SUPER_E] = 0x1D49, // e
    [SUPER_F] = 0x1DA0, // f
    [SUPER_G] = 0x1D4D, // g
    [SUPER_H] = 0x02B0, // h
    [SUPER_I] = 0x2071, // i
    [SUPER_J] = 0x02B2, // j
    [SUPER_K] = 0x1D4F, // k
    [SUPER_L] = 0x02E1, // l
    [SUPER_M] = 0x1D50, // m
    [SUPER_N] = 0x207F, // n
    [SUPER_O] = 0x1D52, // o
    [SUPER_P] = 0x1D56, // p
    [SUPER_Q] = 0x06F9, // q
    [SUPER_R] = 0x02B3, // r
    [SUPER_S] = 0x02E2, // s
    [SUPER_T] = 0x1D57, // t
    [SUPER_U] = 0x1D58, // u
    [SUPER_V] = 0x1D5B, // v
    [SUPER_W] = 0x02B7, // w
    [SUPER_X] = 0x02E3, // x
    [SUPER_Y] = 0x02B8, // y
    [SUPER_Z] = 0x1DBB, // z
    [SUPER_1] = 0x00B9, // 1
    [SUPER_2] = 0x00B2, // 2
    [SUPER_3] = 0x00B3, // 3
    [SUPER_4] = 0x2074, // 4
    [SUPER_5] = 0x2075, // 5
    [SUPER_6] = 0x2076, // 6
    [SUPER_7] = 0x2077, // 7
    [SUPER_8] = 0x2078, // 8
    [SUPER_9] = 0x2079, // 9
    [SUPER_0] = 0x2070  // 0
};
