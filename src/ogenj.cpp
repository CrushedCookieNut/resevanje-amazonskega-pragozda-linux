#include "include/ogenj.hpp"
#include "include/sdl-window-and-renderer.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

ogenj::ogenj() {
    x=rand()%901+50;
    y=rand()%701+50;
    zdravje=1;
    ogenjSurface=IMG_Load("/home/bavconlaura/Desktop/sdl2-game/src/images/fire.png");
    if (!ogenjSurface) {
        std::cout << "Image not loaded!" << std::endl;
    }

    ogenjTexture=SDL_CreateTextureFromSurface(renderer, ogenjSurface);
}

void ogenj::risanje() {
    podlaga={x,y,50,50};
    //SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, ogenjTexture, NULL, &podlaga);
}

int ogenj::vrniZdravje() {
    return zdravje;
}

void ogenj::spremeniZdravje() {
    zdravje=0;
}

int ogenj::getX() {
    return x;
}

int ogenj::getY() {
    return y;
}