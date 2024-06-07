#ifndef DREVO_HPP
#define DREVO_HPP

#include "vse.hpp"
#include <SDL2/SDL.h>

class drevo:public vse {
    //SDL_Rect kvadrat;
    int dotaknilSovraznik;
    friend class zemljevidDreves;
    public:
    SDL_Rect kvadrat;
    void risanje();
    drevo() {}
    drevo(int x, int y);
    void dotaknilSeJeSovraznik();
    bool preveriCeMrtvo();
    //SDL_Rect getRect();
};

#endif