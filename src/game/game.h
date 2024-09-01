#ifndef GAME_H
#define GAME_H

#include "../../include/SDL2/SDL.h"

struct Game {
  struct Bird *birdObject;
  // array of pipe
  struct Pipe **pipeObject;
  int windowHeight;
  int windowWidth;
};

struct Game *initGame(int, int);

int StartGame(struct Game *);

void update(struct Game *, SDL_Renderer *);

#endif
