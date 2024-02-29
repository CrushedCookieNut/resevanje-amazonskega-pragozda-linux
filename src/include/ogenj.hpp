#ifndef OGENJ_HPP
#define OGENJ_HPP

#include "vse.hpp"
#include <SDL2/SDL.h>

class ogenj:public vse {
    SDL_Surface *ogenjSurface;
    SDL_Texture *ogenjTexture;
    SDL_Rect podlaga;
    public:
    SDL_Rect getRect();
    void risanje();
    ogenj();
};

#endif