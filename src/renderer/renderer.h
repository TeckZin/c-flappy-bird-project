#ifndef RENDERER_H
#define RENDERER_H
#include "../../include/SDL2/SDL.h"

SDL_Renderer *generateDisplayRender(SDL_Window *);

SDL_Texture *loadTexture(SDL_Renderer *, char *);

#endif
