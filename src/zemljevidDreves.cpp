#include "include/zemljevidDreves.hpp"
#include <iostream>
using namespace std;

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
    //zemljevid.at(index).risanje();
}

void zemljevidDreves::izrisujDrevesa() {
    for (int i=0;i<zemljevid.size();i++) {
        zemljevid.at(i).risanje();
    }
}

bool zemljevidDreves::preveriKonec() {
    int kolikoMrtvih=0;
    for (int i=0;i<zemljevid.size();i++) {
        if (zemljevid.at(i).zdravje==0)
            kolikoMrtvih++;
    }
    if (kolikoMrtvih>=(zemljevid.size()*0.7))
        return 1;
    return 0;
}