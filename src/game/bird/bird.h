#ifndef BIRD_H
#define BIRD_H
#include "../../../include/SDL2/SDL.h"

struct Bird {
  int posX;
  int posY;
  float deltaY;
  SDL_Texture *texture;
  SDL_Rect rect;
};

struct Bird *initBird();

void renderBirdTexture(struct Bird *bird, SDL_Renderer *renderer);

void simmulateGravity(struct Bird *b);

#endif
