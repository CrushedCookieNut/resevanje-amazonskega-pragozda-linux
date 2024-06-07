#ifndef SEZNAMSOVRAZNIKOV_HPP
#define SEZNAMSOVRAZNIKOV_HPP

#include "sovraznik.hpp"
#include <vector>

class seznamSovraznikov {
    public:
    std::vector<sovraznik> seznam;
    seznamSovraznikov():seznam(5) {}
    void izrisiSeznamSovraznikov();
    void ustvariSeznamSovraznikov();
    void izbrisiSovraznika(int);
    bool preveriKonec();
};

#endif