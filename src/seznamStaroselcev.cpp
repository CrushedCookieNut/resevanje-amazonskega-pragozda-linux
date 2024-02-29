#include "include/seznamStaroselcev.hpp"

void seznamStaroselcev::ustvariSeznamStaroselcev() {
    for (int i=0;i<seznam.size();i++) {
        staroselec tmp;
        seznam.at(i)=tmp;
        seznam.at(i).risanje();
    }
}

void seznamStaroselcev::izrisiSeznamStaroselcev() {
    for (int i=0;i<seznam.size();i++) {
        seznam.at(i).risanje();
    }
}