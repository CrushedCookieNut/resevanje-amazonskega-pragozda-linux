#include <iostream>
#include <vector>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "include/sdl-window-and-renderer.hpp"
#include "include/ogenj.hpp"
#include "include/verigaOgnjev.hpp"
#include "include/drevo.hpp"
#include "include/zemljevidDreves.hpp"
#include "include/igralec.hpp"
#include "include/sovraznik.hpp"
#include "include/seznamSovraznikov.hpp"
#include "include/staroselec.hpp"
#include "include/seznamStaroselcev.hpp"
using namespace std;

void spawnajOgenj(verigaOgnjev& veriga) {
    ogenj novOgenj;
    veriga.veriga.push_back(novOgenj);
}

void preveriTrk(igralec &a, verigaOgnjev &b, seznamSovraznikov &c, seznamStaroselcev &d, zemljevidDreves &e) { //preverjanje trkov med ognjem in igralcem, ostalo še potrbno dodati
    bool trkZOgnjem, trkSSovraznikom, trkMedOgnjemInStaroselcem,trkMedSovraznikomInDrevesom;
    for (int i=0;i<b.veriga.size();i++) { //gre čez cel vektor ognjev
        trkZOgnjem = SDL_HasIntersection(&a.podlaga, &b.veriga.at(i).podlaga);
        if (trkZOgnjem==SDL_TRUE) {
            //cout << "Trk!"; //za debugging večinoma
            b.izbrisiOgenj(i);
        }
    }
    for (int i=0;i<c.seznam.size();i++) {
        trkSSovraznikom=SDL_HasIntersection(&a.podlaga,&c.seznam.at(i).podlaga);
        if (trkSSovraznikom==SDL_TRUE) {
            //cout << "Trk!";
            c.izbrisiSovraznika(i);
        }
    }
    for (int i=0;i<d.seznam.size();i++) {
        for (int j=0;j<b.veriga.size();j++) {
            trkMedOgnjemInStaroselcem=SDL_HasIntersection(&b.veriga.at(j).podlaga,&d.seznam.at(i).podlaga);
            if (trkMedOgnjemInStaroselcem==SDL_TRUE) {
                //cout << "Trk!";
                b.izbrisiOgenj(j);
            }
        }
    }
    for (int i=0;i<c.seznam.size();i++) {
        for (int j=0;j<e.zemljevid.size();j++) {
            trkMedSovraznikomInDrevesom=SDL_HasIntersection(&c.seznam.at(i).podlaga,&e.zemljevid.at(j).kvadrat);
            if (trkMedSovraznikomInDrevesom==SDL_TRUE) {
                e.zemljevid.at(j).dotaknilSeJeSovraznik();
                if (e.zemljevid.at(j).preveriCeMrtvo()) {
                    e.uniciDrevo(j);
                } 
            }
        }
    }

}

void osvezevanje(zemljevidDreves &igralenZemljevid, verigaOgnjev &x, seznamSovraznikov &a, igralec &b, seznamStaroselcev &c) {
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    //SDL_RenderClear(renderer); //funkcija da se ponovno izrisuje use vedno
    for (int i=0;i<a.seznam.size();i++) {
        a.seznam.at(i).premikanje();
    }
    for (int i=0;i<c.seznam.size();i++) {
        c.seznam.at(i).premikanje(x);
    }
    igralenZemljevid.izrisujDrevesa();
    x.izrisiVerigoOgnjev();
    a.izrisiSeznamSovraznikov();
    c.izrisiSeznamStaroselcev();
    b.preveriDotikanjeRoba();
    b.risanje();
    preveriTrk(b,x,a,c, igralenZemljevid); //to je na koncu in tehnično deluje ampak ne  vem zakaj?
    SDL_RenderPresent(renderer);
}

int main() {
    srand(time(NULL));
    SDL_Init(SDL_INIT_EVERYTHING);
    initializeWindowAndRenderer();
    int flags=IMG_INIT_PNG;
    int initStatus=IMG_Init(flags);
    if ((initStatus&flags)!=flags) {
        cout << "SDL2_Image format not available!" << endl;
    }
    const int fps=60;
    const int frameDelay=1000/fps;
    Uint32 frameStart;
    int frameTime;

    //ustvarjanje usega
    zemljevidDreves igralenZemljevid;
    igralenZemljevid.ustvariZemljevidDreves();
    verigaOgnjev x;
    x.ustvariVerigoOgnjev();
    seznamSovraznikov a;
    a.ustvariSeznamSovraznikov();
    seznamStaroselcev b;
    b.ustvariSeznamStaroselcev();
    igralec igralec;
    osvezevanje(igralenZemljevid,x,a,igralec,b);

    //za spawnanje ognjev
    int spawnFrequency=120;
    int framesSinceLastSpawn=0;

    SDL_Event windowEvent, premikanje;

    //glavn loop igrice
    while (true) {
        frameStart=SDL_GetTicks();
        ++framesSinceLastSpawn;

        if (SDL_PollEvent(&windowEvent)) {
            if (SDL_QUIT==windowEvent.type) {
                break;
            }
        } else if (SDL_PollEvent(&premikanje)) {
            if (premikanje.type==SDL_KEYDOWN) {
                igralec.premikanje();
                osvezevanje(igralenZemljevid,x,a,igralec,b);
            }
        } else {
            osvezevanje(igralenZemljevid,x,a,igralec,b);
        }
        
        frameTime=SDL_GetTicks()-frameStart;
        if (frameDelay>frameTime) {
            SDL_Delay(frameDelay-frameTime);
        }

        if (x.preveriKonec()&&a.preveriKonec()) {
            cout << "Zmagal si!";
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
            SDL_Delay(5000);
            break;
        }

        if (framesSinceLastSpawn>=spawnFrequency) {
            spawnajOgenj(x);
            framesSinceLastSpawn=0;
        }

        if (igralenZemljevid.preveriKonec()) {
            cout << "Izgubil si!";
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
            SDL_Delay(5000);
            break;
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;

    return 0;
}
