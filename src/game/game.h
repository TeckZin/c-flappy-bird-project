#ifndef GAME_H
#define GAME_H

#define MAX_PIPES = 10
#include "../../include/SDL2/SDL.h"

struct Game {
  struct Bird *birdObject;
  // array of pipe
  struct Pipe **pipeObjects;
  int pipeCount;
  int windowHeight;
  int windowWidth;
};

struct Game *initGame(int, int);

void appendPipes(struct Game *game, struct Pipe **pipes);

int StartGame(struct Game *);

void update(struct Game *, SDL_Renderer *);

void cleanUpGame(struct Game *game);

#endif
