#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
    const char template_message[] = "-- Hello %s! --";

    const size_t length = strlen(template_message) + strlen(user) + 1;
    char hello_message[length];

    sprintf(hello_message, template_message, user);

    __uint16_t spacing = (tsizes.twidth - length) / 2;

    repeat(" ", spacing);
    printf("%s", hello_message);
    repeat(" ", spacing);

    printf("\n");
}
