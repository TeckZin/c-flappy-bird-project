#include "pipe.h"
#include "../../renderer/renderer.h"
#include <stdlib.h>
#include <time.h>

struct Pipe **generatePipe(int height, int width, SDL_Texture *texture) {
  struct Pipe **pipes = malloc(sizeof(struct Pipe *) * 2);
  int gap = 140;
  int pipeHeight = 75;
  int minHeight = pipeHeight + gap;
  int maxHeight = height - gap;
  srand(time(NULL));
  int r = (rand() % (maxHeight - minHeight + 1)) + minHeight;
  struct Pipe *topPipe = malloc(sizeof(struct Pipe));
  topPipe->rect.w = 100;
  topPipe->rect.h = r;
  topPipe->rect.y = 0 + 10;
  topPipe->rect.x = width - 50;

  struct Pipe *bottomPipe = malloc(sizeof(struct Pipe));
  bottomPipe->rect.w = 100;
  bottomPipe->rect.h = height - r - gap - 10;
  bottomPipe->rect.y = r + gap;
  bottomPipe->rect.x = width - 50;
  bottomPipe->texture = texture;
  topPipe->texture = texture;
  pipes[0] = topPipe;
  pipes[1] = bottomPipe;

  // Print values for top pipe
  printf("r: %d\n", r);
  printf("Top Pipe: x=%d, y=%d, w=%d, h=%d\n", topPipe->rect.x, topPipe->rect.y,
         topPipe->rect.w, topPipe->rect.h);

  // Print values for bottom pipe
  printf("Bottom Pipe: x=%d, y=%d, w=%d, h=%d\n", bottomPipe->rect.x,
         bottomPipe->rect.y, bottomPipe->rect.w, bottomPipe->rect.h);

  return pipes;
}

SDL_Texture *renderPipeTexture(SDL_Renderer *renderer) {
  SDL_Texture *texture = loadTexture(renderer, "assets/pipe.png");
  if (texture == NULL) {
    printf("Failed to load pipe texture! SDL_Error: %s\n", SDL_GetError());
  }
  return texture;
};

void pipeUpdate(struct Pipe *pipe) {
  pipe->rect.x += -10;
  printf("pipe: %d ", pipe->rect.x);
};
