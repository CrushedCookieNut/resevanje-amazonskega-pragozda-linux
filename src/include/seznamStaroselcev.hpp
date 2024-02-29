#ifndef SEZNAMSTAROSELCEV_HPP
#define SEZNAMSTAROSELCEV_HPP

#include "staroselec.hpp"
#include <vector>

class seznamStaroselcev {
    public:
    std::vector<staroselec> seznam;
    seznamStaroselcev():seznam(3) {}
    void ustvariSeznamStaroselcev();
    void izrisiSeznamStaroselcev();
};

#endif