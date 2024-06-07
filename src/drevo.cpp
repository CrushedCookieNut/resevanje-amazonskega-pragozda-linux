#include "include/drevo.hpp"
#include "include/sdl-window-and-renderer.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <iostream>
using namespace std;

void drevo::risanje() {
    if (zdravje==1)
        SDL_SetRenderDrawColor(renderer, 50, 168, 82, 255);
    else if (zdravje==0) {
        SDL_SetRenderDrawColor(renderer, 198, 94, 33, 255);
    }
    kvadrat={x, y, 100, 100};
    SDL_RenderDrawRect(renderer, &kvadrat);
    SDL_RenderFillRect(renderer, &kvadrat);
}

drevo::drevo(int x, int y) {
    zdravje=1;
    this->x=x;
    this->y=y;
    dotaknilSovraznik=0;
}

/* SDL_Rect drevo::getRect() {
    return kvadrat;
} */

void drevo::dotaknilSeJeSovraznik() {
    dotaknilSovraznik++;
}

bool drevo::preveriCeMrtvo() {
    if (dotaknilSovraznik>=10)
        return 1;
    return 0;
}