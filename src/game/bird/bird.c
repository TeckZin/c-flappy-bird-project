#include "bird.h"
#include "../../renderer/renderer.h"
#include <stdlib.h>

struct Bird *initBird() {
  /* char filename[] = ""; */
  struct Bird *bird = malloc(sizeof(struct Bird));

  return bird;
};

void renderBirdTexture(struct Bird *bird, SDL_Renderer *renderer) {
  bird->texture = loadTexture(renderer, "flappy-bird.png");
  if (bird->texture == NULL) {
    printf("Failed to load bird texture! SDL_Error: %s\n", SDL_GetError());
  }
};

void simmulateGravity(struct Bird *b) { b->deltaY += 0.25; };
