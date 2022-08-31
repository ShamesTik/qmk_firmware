// Copyright 2022 ShamesTik (@ShamesTik)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define LAYOUT( \
	L00, L01, L02, R00, R01, R02,   \
        L10, L11, L12, R10, R11, R12  \
) { \
	{ L00, L01, L02 },  \
	{ R00, R01, R02 },  \
	{ L10, L11, L12 },  \
	{ R10, R11, R12 } \
}
