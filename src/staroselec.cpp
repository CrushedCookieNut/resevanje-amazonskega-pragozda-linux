#include "include/staroselec.hpp"
#include "include/igralec.hpp"
#include "include/sdl-window-and-renderer.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cmath>

staroselec::staroselec() {
    x=rand()%801+150;
    y=rand()%601+150;
    zdravje=1;
    staroselecSurface=IMG_Load("/home/bavconlaura/Desktop/sdl2-game/src/images/indigenousPerson1.png");
    if (!staroselecSurface) {
        std::cout << "Image not loaded!" << std::endl;
    }

    staroselecTexture=SDL_CreateTextureFromSurface(renderer, staroselecSurface);
}

void staroselec::risanje() {
    podlaga={x,y,150,150};
    SDL_RenderCopy(renderer, staroselecTexture, NULL, &podlaga);

    return;
}

void staroselec::premikanje(igralec igralec) {
    int targetX = igralec.getX();
    int targetY = igralec.getY();

    double angle = atan2(targetY - this->y, targetX - this->x);

    double speed = 50;

    this->x += static_cast<int>(speed * cos(angle));
    this->y += static_cast<int>(speed * sin(angle));
}

SDL_Rect staroselec::getRect() {
    return podlaga;
}