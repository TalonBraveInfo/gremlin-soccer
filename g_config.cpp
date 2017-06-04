/* Copyright (C) 1997 Gremlin Interactive Ltd.
 * With modifications by Mark E Sowden
 */

#include <cstdlib>

#include "euro_def.h"

#include "config.h"
#include "eurodefs.h"
#include "defines.h"

void ReadConfigFile(void) {
    BYTE *h = (BYTE*)malloc(sizeof(match_data) + (sizeof(int) * 12));

    // todo

    free(h);
}