#include "display.h"

SDL_Window *display(int WINDOW_HEIGHT, int WINDOW_WIDTH) {
  return SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT,
                          SDL_WINDOW_SHOWN);
}
