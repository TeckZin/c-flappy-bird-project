#ifndef PIPE_H
#define PIPE_H

#include "../game.h"
#include <stdbool.h>

struct Pipe {
  SDL_Texture *texture;
  SDL_Rect rect;
};

struct Pipe **generatePipe(int, int);

void renderPipeTexture(struct Pipe *, SDL_Renderer *renderer);

void pipeUpdate(struct Pipe *);

#endif
