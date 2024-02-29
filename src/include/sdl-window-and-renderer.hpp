#ifndef SDL_WINDOW_AND_RENDERER_HPP
#define SDL_WINDOW_AND_RENDERER_HPP

#include <SDL2/SDL.h>

extern const int width;
extern const int height;
extern SDL_Window *window;
extern SDL_Renderer *renderer;
void initializeWindowAndRenderer();

#endif