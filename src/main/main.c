#include "../game/game.h"
#include <stdio.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main(int argc, char *argv[]) {
  printf("Number of arguments: %d\n", argc);
  printf("Program name: %s\n", argv[0]);
  printf("main call\n");
  struct Game *game = initGame(WINDOW_HEIGHT, WINDOW_WIDTH);
  int x = StartGame(game);

  if (x != 0) {
    return x;
  }

  return 0;
}
