#include "include/staroselec.hpp"
#include "include/igralec.hpp"
#include "include/sdl-window-and-renderer.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cmath>

staroselec::staroselec() {
    x=rand()%801+150;
    y=rand()%601+150;
    zdravje=1;
    staroselecSurface=IMG_Load("/home/bavconlaura/Desktop/sdl2-game/src/images/indigenousPerson1.png");
    if (!staroselecSurface) {
        std::cout << "Image not loaded!" << std::endl;
    }

    staroselecTexture=SDL_CreateTextureFromSurface(renderer, staroselecSurface);
}

void staroselec::risanje() {
    podlaga={x,y,150,150};
    SDL_RenderCopy(renderer, staroselecTexture, NULL, &podlaga);

    return;
}

/*void staroselec::premikanje(igralec igralec) {
    int targetX = igralec.getX();
    int targetY = igralec.getY();

    double angle = atan2(targetY - this->y, targetX - this->x);

    double distance = sqrt(pow(targetX - this->x, 2) + pow(targetY - this->y, 2));

    double baseSpeed = 10;
    double scalingFactor = 0.025;

    double speed = std::min(baseSpeed, distance * scalingFactor);

    int newX = this->x + static_cast<int>(speed * cos(angle));
    int newY = this->y + static_cast<int>(speed * sin(angle));

    this->x = newX;
    this->y = newY;
} */



void staroselec::premikanje(verigaOgnjev& veriga) {
    std::vector<ogenj>& allOgnji = veriga.veriga;

    if (allOgnji.empty()) return;

    // Find the nearest ogenj
    ogenj* nearestOgnji = nullptr;
    double minDistance = std::numeric_limits<double>::max();

    for (size_t i = 0; i < allOgnji.size(); ++i) {
        if (allOgnji[i].vrniZdravje() > 0) { // Only consider active ogenj objects
            double distance = sqrt(pow(allOgnji[i].getX() - this->x, 2) + pow(allOgnji[i].getY() - this->y, 2));
            if (distance < minDistance) {
                minDistance = distance;
                nearestOgnji = &allOgnji[i];
            }
        }
    }

    if (nearestOgnji) {
        int targetX = nearestOgnji->getX();
        int targetY = nearestOgnji->getY();

        double angle = atan2(targetY - this->y, targetX - this->x);

        double distance = sqrt(pow(targetX - this->x, 2) + pow(targetY - this->y, 2));

        double baseSpeed = 10;
        double scalingFactor = 0.025;

        double speed = std::min(baseSpeed, distance * scalingFactor);

        int newX = this->x + static_cast<int>(speed * cos(angle));
        int newY = this->y + static_cast<int>(speed * sin(angle));

        this->x = newX;
        this->y = newY;
    }
}
