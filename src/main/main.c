#include "../game/game.h"
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main(int argc, char *argv[]) {
  printf("Number of arguments: %d\n", argc);
  printf("Program name: %s\n", argv[0]);
  printf("main call\n");

  /* init_keyboard(); */
  char cwd[PATH_MAX];
  if (getcwd(cwd, sizeof(cwd)) != NULL) {
    printf("Current working directory: %s\n", cwd);
  } else {
    perror("getcwd() error");
  }
  struct Game *game = initGame(WINDOW_HEIGHT, WINDOW_WIDTH);
  int x = StartGame(game);

  if (x != 0) {
    return x;
  }
  /* close_keyboard(); */

  return 0;
}
