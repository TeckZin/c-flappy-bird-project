#ifndef BIRD_H
#define BIRD_H
#include "../../../include/SDL2/SDL.h"
#include <stdbool.h>

struct Bird {
  float deltaY;
  SDL_Texture *texture;
  SDL_Rect rect;
};

struct Bird *initBird();

void handleBirdInput(struct Bird *b);

void renderBirdTexture(struct Bird *bird, SDL_Renderer *renderer);

bool birdUpdate(struct Bird *, int);

bool birdDead(struct Bird *, int);

#endif
