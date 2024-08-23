#include "game.h"
#include "bird/bird.h"
#include <stdlib.h>

struct Game *initGame() {
  struct Game *game = malloc(sizeof(struct Game));
  if (game == NULL) {
    return NULL;
  }
  game->birdObject = malloc(sizeof(struct Bird));
  if (game->birdObject == NULL) {
    free(game);
    return NULL;
  }

  game->birdObject->posX = 0;
  game->birdObject->posY = 0;
  game->birdObject->deltaY = 0;

  return game;
}
