#include "include/sdl-window-and-renderer.hpp"
#include <SDL2/SDL.h>

const int width = 1000;
const int height = 800;
SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;

void initializeWindowAndRenderer() {
    window = SDL_CreateWindow("Amazon Rainforest Rescue", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_ALLOW_HIGHDPI);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}