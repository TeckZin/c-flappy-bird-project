#include "bird.h"
#include "../../renderer/renderer.h"
#include <stdlib.h>

#define KEY_UP 65
#define KEY_SPACE 32

struct Bird *initBird() {
  /* char filename[] = ""; */
  struct Bird *bird = malloc(sizeof(struct Bird));

  return bird;
};

void renderBirdTexture(struct Bird *bird, SDL_Renderer *renderer) {
  bird->texture = loadTexture(renderer, "assets/flappy-bird.png");
  if (bird->texture == NULL) {
    printf("Failed to load bird texture! SDL_Error: %s\n", SDL_GetError());
  }
};

bool birdUpdate(struct Bird *b, int height) {
  if (b->deltaY < 0.30) {
    b->deltaY += 0.03;
  }

  /* printf("bird y: %d\n", b->rect.y); */

  b->rect.y = ceil((float)b->rect.y + b->deltaY);
  /* printf("%d\n", height); */
  /* return true; */
  return birdDead(b, height);
};

bool birdDead(struct Bird *b, int height) { return b->rect.y < height; };

void handleBirdInput(struct Bird *b) { b->deltaY = -3; };
