#ifndef PIPE_H
#define PIPE_H

#include "../game.h"

struct Pipe {
  int posX;
  int topPosY;
};

struct Pipe *generatePipe();

#endif
