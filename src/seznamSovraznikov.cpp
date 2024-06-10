#include "include/seznamSovraznikov.hpp"

void seznamSovraznikov::ustvariSeznamSovraznikov() {
    if (seznam.size()==0) {
        for (int i=0;i<stSOvraznikov;i++) {
            sovraznik tmp;
            seznam.push_back(tmp);
            seznam.at(i).risanje();
        }
    } else {
        for (int i=0;i<seznam.size();i++) {
            sovraznik tmp;
            seznam.at(i)=tmp;
            seznam.at(i).risanje();
        }
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

bool seznamSovraznikov::preveriKonec() {
    if (this->seznam.size()<=0)
        return 1;
    return 0;
}