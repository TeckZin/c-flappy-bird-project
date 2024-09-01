#include "game.h"

#include "../display/display.h"
#include "../renderer/renderer.h"
#include "bird/bird.h"
#include <stdlib.h>

struct Game *initGame(int WINDOW_HEIGHT, int WINDOW_WIDTH) {
  struct Game *game = malloc(sizeof(struct Game));
  if (game == NULL) {
    return NULL;
  }
  game->birdObject = malloc(sizeof(struct Bird));
  if (game->birdObject == NULL) {
    free(game);
    return NULL;
  }

  game->birdObject->rect.x = 50;                // Starting X position
  game->birdObject->rect.y = WINDOW_HEIGHT / 2; // Starting Y position
  game->birdObject->rect.w = 50;                // Bird width
  game->birdObject->rect.h = 50;                // Bird height
  game->birdObject->deltaY = 0;

  game->birdObject->posX = 0;
  game->birdObject->posY = 0;
  game->windowHeight = WINDOW_HEIGHT;
  game->windowWidth = WINDOW_WIDTH;

  return game;
}

int StartGame(struct Game *g) {
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;

  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }
  printf("%d, %d", g->windowWidth, g->windowHeight);

  window = display(g->windowHeight, g->windowWidth);

  // Create window
  if (window == NULL) {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  // Create renderer
  renderer = generateDisplayRender(window);
  if (renderer == NULL) {
    printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }
  renderBirdTexture(g->birdObject, renderer);

  update(g, renderer);

  // Destroy window
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  // Quit SDL subsystems
  SDL_Quit();
  return 0;
}

void update(struct Game *game, SDL_Renderer *renderer) {
  // Main loop flag
  int quit = 0;

  // Event handler
  SDL_Event e;

  // While application is running
  while (!quit) {
    // Handle events on queue
    while (SDL_PollEvent(&e) != 0) {
      // User requests quit
      if (e.type == SDL_QUIT) {
        quit = 1;
      }
    }
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);

    SDL_Rect rect;
    rect.x = 50;
    rect.y = 50;
    rect.w = 50;
    rect.h = 50;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
    // Clear screen

    // Render bird with texture
    SDL_RenderCopy(renderer, game->birdObject->texture, NULL,
                   &(game->birdObject->rect));

    // Update screen
    SDL_RenderPresent(renderer);
  }
}
