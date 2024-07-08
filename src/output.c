#include "../include/output.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "../include/terminal.h"
#include "../include/global.h"

void repeat(const char *fragment, const size_t times) {
  for (size_t i = 0; i < times; i++) printf("%s", fragment);
}

void welcome() {
  const uint16_t DEFAULT_WIDTH = 50;

  terminal_sizes tsizes = get_terminal_dimensions(false);

  if (tsizes.error) tsizes.twidth = DEFAULT_WIDTH;

  char *user = getenv("USER") ? getenv("USER") : "There";
  const char template_message[] = "Hello %s!";

  const uint8_t SPACE_LEFT = 2;
  const char COVER_SPECIAL_CHAR[] = "-";

  const size_t length = strlen(template_message) + strlen(user) + 1;
  uint16_t spacing = (tsizes.twidth - length) / 2 - 1;

  char hello_message[length];
  sprintf(hello_message, template_message, user);

  printf(TERMINAL_GREEN);

  repeat(COVER_SPECIAL_CHAR, tsizes.twidth - SPACE_LEFT);
  printf("\n");

  repeat("* ", spacing / 2);
  printf("%s%s%s", TERMINAL_BLUE, hello_message, TERMINAL_GREEN);
  repeat(" *", spacing / 2 + SPACE_LEFT);
  printf("\n");

  repeat(COVER_SPECIAL_CHAR, tsizes.twidth - SPACE_LEFT);
  printf("\n");
}
