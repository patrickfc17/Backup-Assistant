#pragma once

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    __uint16_t twidth;
    __uint16_t theight;
    bool error;
} terminal_sizes;

terminal_sizes get_terminal_dimensions(bool fail);
