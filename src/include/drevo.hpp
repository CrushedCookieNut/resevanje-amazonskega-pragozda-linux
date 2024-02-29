#ifndef DREVO_HPP
#define DREVO_HPP

#include "vse.hpp"

class drevo:public vse {
    //SDL_Rect kvadrat;
    friend class zemljevidDreves;
    public:
    void risanje();
    drevo() {}
    drevo(int x, int y);
    //SDL_Rect getRect();
};

#endif