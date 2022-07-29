enum unicode_names {
    FLOOR,
    WALL,
    TOPL,
    TOPR,
    BOTTOML,
    BOTTOMR,
    MID,
    MIDL,
    MIDR,
    MIDB,
    MIDT
};

const uint32_t PROGMEM unicode_map[] = {
    [FLOOR] = 0x2500,   // ─
    [WALL]  = 0x2502,   // │
    [TOPL] = 0x250C,    // ┌
    [TOPR] = 0x2510,    // ┐
    [BOTTOML] = 0x2514, // └
    [BOTTOMR] = 0x2518, // ┘
    [MID] = 0x253C,     //  ┼
    [MIDL] = 0x0251C,   // ├ 
    [MIDR] = 0x2524,    //  ┤
    [MIDT] = 0x252C,    // ┬
    [MIDB] = 0x2534,    // ┴
};
