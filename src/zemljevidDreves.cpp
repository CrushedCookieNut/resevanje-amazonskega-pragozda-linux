#include "include/zemljevidDreves.hpp"

void zemljevidDreves::ustvariZemljevidDreves() {
    int i=0;
    for (int y=0;y<800;y+=100) {
        for (int x=0;x<1000;x+=100) {
            drevo tmp(x,y);
            zemljevid.at(i)=tmp;
            zemljevid[i].risanje();
            i++;
        }
    }
    /* for (int j=0;j<zemljevid.size();j++) {
        zemljevid[j].risanje();
    } */
}

void zemljevidDreves::uniciDrevo(int index) {
    zemljevid.at(index).zdravje=0;
    zemljevid.at(index).risanje();
}