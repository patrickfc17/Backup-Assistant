#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#include "../include/terminal.h"
#include "../include/output.h"

void repeat(const char *fragment, const size_t times)
{
    for (size_t i = 0; i < times; i++)
        printf("%s", fragment);
}

void welcome()
{
    terminal_sizes tsizes = get_terminal_dimensions(true);

    char *user = getenv("USER") ? getenv("USER") : "There";
    const char template_message[] = "Hello %s!";

    const uint8_t LEFT_SPACE = 2;
    const char COVER_SPECIAL_CHAR[] = "-";

    const size_t length = strlen(template_message) + strlen(user) + 1;
    uint16_t spacing = (tsizes.twidth - length) / 2 - 1;

    char hello_message[length];
    sprintf(hello_message, template_message, user);

    printf("\033[32m");

    repeat(COVER_SPECIAL_CHAR, tsizes.twidth - LEFT_SPACE);
    printf("\n");

    repeat("* ", spacing / 2);
    printf("\033[34m%s\033[32m", hello_message);
    repeat(" *", spacing / 2 + LEFT_SPACE);
    printf("\n");

    repeat(COVER_SPECIAL_CHAR, tsizes.twidth - LEFT_SPACE);
    printf("\n");
}
