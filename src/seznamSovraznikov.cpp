#include "include/seznamSovraznikov.hpp"

void seznamSovraznikov::ustvariSeznamSovraznikov() {
    for (int i=0;i<seznam.size();i++) {
        sovraznik tmp;
        seznam.at(i)=tmp;
        seznam.at(i).risanje();
    }
}

void seznamSovraznikov::izrisiSeznamSovraznikov() {
    for (int i=0;i<seznam.size();i++) {
        seznam.at(i).risanje();
    }
}

void seznamSovraznikov::izbrisiSovraznika(int index) {
    seznam.erase(seznam.begin()+index);
}