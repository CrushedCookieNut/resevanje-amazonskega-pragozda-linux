#ifndef IGRALEC_HPP
#define IGRALEC_HPP

#include "ljudje.hpp"
#include "verigaOgnjev.hpp"
#include "sdl-window-and-renderer.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class igralec:public ljudje {
    SDL_Surface *igralecSurface;
    SDL_Texture *igralecTexture;
    public:
    SDL_Rect podlaga;
    igralec();
    void smrt();
    void premikanje();
    void zacetnaPozicija();
    void risanje();
    void preveriDotikanjeRoba();
    int getX();
    int getY();
    int dotikanjeOgnja(const verigaOgnjev&);
};

#endif