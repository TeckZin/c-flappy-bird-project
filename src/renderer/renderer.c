#include "renderer.h"
#include "../../include/SDL_image/SDL_image.h"

SDL_Renderer *generateDisplayRender(SDL_Window *window) {
  SDL_Renderer *renderer = NULL;
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL) {
    printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    return NULL;
  }
  return renderer;
};

SDL_Texture *loadTexture(SDL_Renderer *renderer, char *filename) {
  SDL_Texture *texture;

  SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
                 "Loading %s", filename);

  texture = IMG_LoadTexture(renderer, filename);

  return texture;
}
