#include "include/drevo.hpp"
#include "include/sdl-window-and-renderer.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>

void drevo::risanje() {
    if (zdravje==1)
        SDL_SetRenderDrawColor(renderer, 50, 168, 82, 255);
    else if (zdravje==0)
        SDL_SetRenderDrawColor(renderer, 198, 94, 33, 255);
    SDL_Rect kvadrat={x, y, 100, 100};
    SDL_RenderDrawRect(renderer, &kvadrat);
    SDL_RenderFillRect(renderer, &kvadrat);
    SDL_SetRenderDrawColor(renderer, 50, 168, 82, 255);
}

drevo::drevo(int x, int y) {
    zdravje=1;
    this->x=x;
    this->y=y;
}

/* SDL_Rect drevo::getRect() {
    return kvadrat;
} */