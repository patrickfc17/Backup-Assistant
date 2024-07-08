#pragma once

#include <stdbool.h>
#include <stdio.h>

typedef struct {
  __uint16_t twidth;
  __uint16_t theight;
  bool error;
} terminal_sizes;

terminal_sizes get_terminal_dimensions(bool fail);
