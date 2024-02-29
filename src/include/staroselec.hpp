#ifndef STAROSELEC_HPP
#define STAROSELEC_HPP

#include "ljudje.hpp"
#include "igralec.hpp"
#include <SDL2/SDL.h>

class staroselec:public ljudje {
    SDL_Surface *staroselecSurface;
    SDL_Texture *staroselecTexture;
    SDL_Rect podlaga;
    friend class seznamStaroselcev;
    public:
    SDL_Rect getRect();
    staroselec();
    void risanje();
    void premikanje(igralec);
};

#endif