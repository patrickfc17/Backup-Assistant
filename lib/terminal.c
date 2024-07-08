#include "../include/terminal.h"

#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

terminal_sizes get_terminal_dimensions(const bool should_fail) {
  struct winsize wsize;
  terminal_sizes tsize = {.twidth = 0, .theight = 0, .error = false};

  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &wsize) < 0 && should_fail) {
    fprintf(stderr, "Fail to retrieve terminal dimensions");
    exit(-1);
  }

  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &wsize) < 0 && !should_fail) {
    tsize.error = true;

    return tsize;
  }

  tsize.twidth = wsize.ws_col;
  tsize.theight = wsize.ws_row;

  return tsize;
}
