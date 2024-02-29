#ifndef SOVRAZNIK_HPP
#define SOVRAZNIK_HPP

#include "ljudje.hpp"
#include <SDL2/SDL.h>

class sovraznik:public ljudje {
    SDL_Surface *sovraznikSurface;
    SDL_Texture *sovraznikTexture;
    SDL_Rect podlaga;
    double x,y,velocity_x,velocity_y,damping;
    friend class seznamSovraznikov;
    public:
    SDL_Rect getRect();
    void risanje();
    void premikanje();
    void unicevanjeDreves();
    sovraznik();
};

#endif