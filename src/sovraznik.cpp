#include "include/sovraznik.hpp"
#include "include/sdl-window-and-renderer.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include <iostream>

sovraznik::sovraznik() {
    x=rand()%851+100;
    y=rand()%651+100;
    zdravje=1;
    sovraznikSurface=IMG_Load("/home/bavconlaura/Desktop/sdl2-game/src/images/badGuy.png");
    if (!sovraznikSurface) {
        std::cout << "Image not loaded!" << std::endl;
    }

    sovraznikTexture=SDL_CreateTextureFromSurface(renderer, sovraznikSurface);
    velocity_x=50;
    velocity_y=50;
    damping=1.5;
}

void sovraznik::risanje() {
    podlaga={int(x),int(y),100,100};
    //SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, sovraznikTexture, NULL, &podlaga);

    return;
}

void sovraznik::premikanje() {
    double accelaration_x=(std::rand()%501-250)/100.0;
    double acceleration_y=(std::rand()%501-250)/100.0;
    velocity_x+=accelaration_x;
    velocity_y+=acceleration_y;
    velocity_x*=damping;
    velocity_y*=damping;
    x+=velocity_x;
    y+=velocity_y;
}

//void sovraznik::unicevanjeDreves()