#include <iostream>
#include <vector>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
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
#include "include/leaderboard.hpp"
using namespace std;

void spawnajOgenj(verigaOgnjev& veriga) {
    ogenj novOgenj;
    veriga.veriga.push_back(novOgenj);
}

void preveriTrk(igralec &a, verigaOgnjev &b, seznamSovraznikov &c, seznamStaroselcev &d, zemljevidDreves &e, int &tocke) { //preverjanje trkov med ognjem in igralcem, ostalo še potrbno dodati
    bool trkZOgnjem, trkSSovraznikom, trkMedOgnjemInStaroselcem,trkMedSovraznikomInDrevesom;
    for (int i=0;i<b.veriga.size();i++) { //gre čez cel vektor ognjev
        trkZOgnjem = SDL_HasIntersection(&a.podlaga, &b.veriga.at(i).podlaga);
        if (trkZOgnjem==SDL_TRUE) {
            //cout << "Trk!"; //za debugging večinoma
            b.izbrisiOgenj(i);
            tocke+=10;
        }
    }
    for (int i=0;i<c.seznam.size();i++) {
        trkSSovraznikom=SDL_HasIntersection(&a.podlaga,&c.seznam.at(i).podlaga);
        if (trkSSovraznikom==SDL_TRUE) {
            //cout << "Trk!";
            c.izbrisiSovraznika(i);
            tocke+=10;
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
                    tocke-=10;
                } 
            }
        }
    }

}

void osvezevanje(zemljevidDreves &igralenZemljevid, verigaOgnjev &x, seznamSovraznikov &a, igralec &b, seznamStaroselcev &c, int &tocke) {
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
    preveriTrk(b,x,a,c, igralenZemljevid, tocke); //to je na koncu in tehnično deluje ampak ne  vem zakaj?
    SDL_RenderPresent(renderer);
}

int main() {
    srand(time(NULL));
    SDL_Init(SDL_INIT_EVERYTHING);

    if (TTF_Init() != 0) {
        printf("TTF_Init Error: %s\n", TTF_GetError());
        SDL_Quit();
        return 1;
    }
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

    //ustvarjanje vsega
    zemljevidDreves igralenZemljevid;
    igralenZemljevid.ustvariZemljevidDreves();
    verigaOgnjev x;
    x.ustvariVerigoOgnjev();
    seznamSovraznikov a;
    a.ustvariSeznamSovraznikov();
    seznamStaroselcev b;
    b.ustvariSeznamStaroselcev();
    igralec igralec;
    int tocke=0;
    osvezevanje(igralenZemljevid,x,a,igralec,b,tocke);
    ldb imeLestvice;    

    int stopnja=1;
    int lastSinceCheckTocke=0;
    int odstejTocke=120;

    TTF_Font *font = TTF_OpenFont("/home/bavconlaura/Documents/cutie-pie-cafe/font/VaguelyRetroRegular-3zAqM.ttf", 30);
        if (font == NULL) {
        printf("TTF_OpenFont Error: %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    //za spawnanje ognjev
    int spawnFrequency=120;
    int framesSinceLastSpawn=0;

    SDL_Event windowEvent, premikanje;

    //glavn loop igrice
    while (true) {
        frameStart=SDL_GetTicks();
        ++framesSinceLastSpawn;
        ++lastSinceCheckTocke;

        if (SDL_PollEvent(&windowEvent)) {
            if (SDL_QUIT==windowEvent.type) {
                break;
            }
        } else if (SDL_PollEvent(&premikanje)) {
            if (premikanje.type==SDL_KEYDOWN) {
                igralec.premikanje();
                osvezevanje(igralenZemljevid,x,a,igralec,b, tocke);
            }
        } else {
            osvezevanje(igralenZemljevid,x,a,igralec,b, tocke);
        }
        
        frameTime=SDL_GetTicks()-frameStart;
        if (frameDelay>frameTime) {
            SDL_Delay(frameDelay-frameTime);
        }

        if (x.preveriKonec()&&a.preveriKonec()&&stopnja==2) {
            SDL_Color color = {255, 255, 255, 255};
            SDL_Surface *surf = TTF_RenderText_Solid(font, "ZMAGAL SI!", color);
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
            SDL_FreeSurface(surf);
            int texW = 0;
            int texH = 0;
            SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
            SDL_Rect dstrect = {400, 300, texW, texH};

            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, texture, NULL, &dstrect);
            SDL_RenderPresent(renderer);

            cout << "Zmagal si!" << endl;
            char ime[100];
            fgets(ime,100,stdin);
            imeLestvice.vpisiPodatke(ime, tocke);
            imeLestvice.pridobiPodatke();
            cout << "Zelis igrati ponovno?" << endl;
            bool ans;
            cin >> ans;
            if (ans==0) {
                SDL_Delay(5000);
                break;
            } else {
                stopnja=1;
                igralenZemljevid.ustvariZemljevidDreves();
                x.ustvariVerigoOgnjev();
                a.ustvariSeznamSovraznikov();
                b.ustvariSeznamStaroselcev();
                igralec.zacetnaPozicija();
                igralec.risanje();
                spawnFrequency=120;
                continue;
            }
        } else if (x.preveriKonec()&&a.preveriKonec()&&stopnja==1) {
            SDL_Color color = {255, 255, 255, 255};
            SDL_Surface *surf = TTF_RenderText_Solid(font, "NASLEDNJA STOPNJA", color);
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
            SDL_FreeSurface(surf);
            int texW = 0;
            int texH = 0;
            SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
            SDL_Rect dstrect = {400, 300, texW, texH};

            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, texture, NULL, &dstrect);
            SDL_RenderPresent(renderer);
            spawnFrequency=60;
            SDL_Delay(2500);
            igralenZemljevid.ustvariZemljevidDreves();
            x.ustvariVerigoOgnjev();
            a.ustvariSeznamSovraznikov();
            b.ustvariSeznamStaroselcev();
            igralec.zacetnaPozicija();
            igralec.risanje();
            stopnja++;
        }

        if (framesSinceLastSpawn>=spawnFrequency) {
            spawnajOgenj(x);
            framesSinceLastSpawn=0;
        }

        if (lastSinceCheckTocke>=odstejTocke) {
            tocke-=10;
        }

        if (igralenZemljevid.preveriKonec()) {
            SDL_Color color = {255, 255, 255, 255};
            SDL_Surface *surf = TTF_RenderText_Solid(font, "IZGUBIL SI :(", color);
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
            SDL_FreeSurface(surf);
            int texW = 0;
            int texH = 0;
            SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
            SDL_Rect dstrect = {400, 300, texW, texH};

            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, texture, NULL, &dstrect);
            SDL_RenderPresent(renderer);

            cout << "Izgubil si!";
            char ime[100];
            fgets(ime,100,stdin);
            imeLestvice.vpisiPodatke(ime, tocke);
            imeLestvice.pridobiPodatke();
            SDL_Delay(5000);
            cout << "Zelis igrati ponovno?" << endl;
            bool ans;
            cin >> ans;
            if (ans==0) {
                SDL_Delay(5000);
                break;
            } else {
                stopnja=1;
                igralenZemljevid.ustvariZemljevidDreves();
                x.ustvariVerigoOgnjev();
                a.ustvariSeznamSovraznikov();
                b.ustvariSeznamStaroselcev();
                igralec.zacetnaPozicija();
                igralec.risanje();
                spawnFrequency=120;
                continue;
            }
        }

        if (tocke<0)
            tocke=0;
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;

    return 0;
}
