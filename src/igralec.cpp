#include "include/igralec.hpp"
#include "include/verigaOgnjev.hpp"
#include "include/sdl-window-and-renderer.hpp"
#include <SDL2/SDL.h>
#include <iostream>

igralec::igralec() {
    zdravje=1;
    zacetnaPozicija();
    igralecSurface=IMG_Load("/home/bavconlaura/Desktop/sdl2-game/src/images/super-mario.png");
    if (!igralecSurface) {
        std::cout << "Image not loaded!" << std::endl;
    }

    igralecTexture=SDL_CreateTextureFromSurface(renderer, igralecSurface);
}

void igralec::risanje() {
    podlaga={x,y,100,100};
    //SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, igralecTexture, NULL, &podlaga);

    return;
}

void igralec::premikanje() {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    int hitrost=20;

    if (currentKeyStates[SDL_SCANCODE_W]) {
        y-=hitrost;
    }
    if (currentKeyStates[SDL_SCANCODE_A]) {
        x-=hitrost;
    }
    if (currentKeyStates[SDL_SCANCODE_S]) {
        y+=hitrost;
    }
    if (currentKeyStates[SDL_SCANCODE_D]) {
        x+=hitrost;
    }
    //SDL_Delay(20);
}

void igralec::zacetnaPozicija() {
    x=0;
    y=0;
}

void igralec::preveriDotikanjeRoba() {
    if (x>900)
        x=900;
    if (x<0)
        x=0;
    if (y<0)
        y=0;
    if (y>700)
        y=700;
}

int igralec::getX() {
    return x;
}

int igralec::getY() {
    return y;
}