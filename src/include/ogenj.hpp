#ifndef OGENJ_HPP
#define OGENJ_HPP

#include "vse.hpp"
#include <SDL2/SDL.h>

class ogenj:public vse {
    SDL_Surface *ogenjSurface;
    SDL_Texture *ogenjTexture;
    public:
    SDL_Rect podlaga;
    void risanje();
    ogenj();
    int vrniZdravje();
    void spremeniZdravje();
    int getX();
    int getY(); //for debugging purposes
};

#endif