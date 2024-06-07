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
        if (veriga.at(i).vrniZdravje()==1)
            veriga.at(i).risanje();
    }
}

void verigaOgnjev::izbrisiOgenj(int index) {
    veriga.at(index).spremeniZdravje();
    //std::cout << "Ogenj izbrisan na mestu: " << index << std::endl;
}

bool verigaOgnjev::preveriKonec() {
    int x=0;
    for (int i=0;i<this->veriga.size();i++) {
        if (veriga.at(i).vrniZdravje()==0)
            x++;
    }
    if (x==veriga.size()) {
        return 1;
    }
    return 0;
}