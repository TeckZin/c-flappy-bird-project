#include "game.h"

#include "../display/display.h"
#include "../renderer/renderer.h"
#include "bird/bird.h"
#include "pipe/pipe.h"
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

  game->birdObject->rect.x = 50;  // Starting X position
  game->birdObject->rect.y = 100; // Starting Y position
  game->birdObject->rect.w = 50;  // Bird width
  game->birdObject->rect.h = 50;  // Bird height
  game->birdObject->deltaY = 0.0;

  game->windowHeight = WINDOW_HEIGHT;
  game->windowWidth = WINDOW_WIDTH;

  game->pipeObjects = malloc(sizeof(struct Pipe *) * 10);
  game->pipeCount = 0;

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
  int tick = 0;

  // Event handler
  SDL_Event e;

  // While application is running
  while (!quit) {
    // Handle events on queue
    while (SDL_PollEvent(&e) != 0) {
      // User requests quit
      if (e.type == SDL_QUIT) {
        quit = 1;
      } else if (e.type == SDL_KEYUP || e.type == SDLK_SPACE) {
        handleBirdInput(game->birdObject);
        printf("jump\n");
      }
    }

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
    if (tick == 500) {
      struct Pipe **pipes = generatePipe(game->windowHeight, game->windowWidth);
      appendPipes(game, pipes);
      printf("pipeCount: %d\n", game->pipeCount);
      tick = 0;
    }

    if (tick % 10 == 0) {
      for (int i = 0; i < game->pipeCount; i++) {
        pipeUpdate(game->pipeObjects[i]);
      }
      printf("\n");
    }
    // Render bird with texture
    if (!birdUpdate(game->birdObject, game->windowHeight)) {
      quit = 1;
    };
    for (int i = 0; i < game->pipeCount; i++) {
      renderPipeTexture(game->pipeObjects[i], renderer);

      SDL_RenderCopy(renderer, game->pipeObjects[i]->texture, NULL,
                     &(game->pipeObjects[i]->rect));
    }
    SDL_RenderCopy(renderer, game->birdObject->texture, NULL,
                   &(game->birdObject->rect));

    // Update screen
    SDL_RenderPresent(renderer);
    tick++;
  }
}

void cleanUpGame(struct Game *game) {
  for (int i = 0; i < game->pipeCount; i++) {
    free(game->pipeObjects[i]);
  }
  free(game->pipeObjects);
  free(game->birdObject);
  free(game);
}

void appendPipes(struct Game *game, struct Pipe **pipes) {
  if (game->pipeCount + 2 > 10) {
    free(game->pipeObjects[0]);
    free(game->pipeObjects[1]);
    for (int i = 0; i < game->pipeCount - 2; i++) {
      game->pipeObjects[i] = game->pipeObjects[i + 2];
    }
    game->pipeCount -= 2;
  };
  // Append the new pipes
  game->pipeObjects[game->pipeCount++] = pipes[0];
  game->pipeObjects[game->pipeCount++] = pipes[1];

  // Free the temporary array (but not the Pipe structs it points to)
  free(pipes);
};
