#ifndef GAME_H
#define GAME_H

struct Game {
  struct Bird *birdObject;
  // array of pipe
  struct Pipe *pipeObject;
};

struct Game *initGame();

#endif
