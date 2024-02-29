#include "include/verigaOgnjev.hpp"

#include <time.h>
#include <iostream>

void verigaOgnjev::ustvariVerigoOgnjev() {
    int dolzinaVerige=rand()%8+7;
    for (int i=0;i<dolzinaVerige;i++) {
        ogenj tmp;
        veriga.push_back(tmp);
    }
    izrisiVerigoOgnjev();
}

void verigaOgnjev::izrisiVerigoOgnjev() {
    for (int i=0;i<veriga.size();i++) {
        veriga.at(i).risanje();
    }
}

void verigaOgnjev::izbrisiOgenj(int index) {
    veriga.erase(veriga.begin()+index);
}