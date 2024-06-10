#ifndef SEZNAMSOVRAZNIKOV_HPP
#define SEZNAMSOVRAZNIKOV_HPP

#include "sovraznik.hpp"
#include <vector>

class seznamSovraznikov {
    int stSOvraznikov=5;
    public:
    std::vector<sovraznik> seznam;
    seznamSovraznikov():seznam(stSOvraznikov) {}
    void izrisiSeznamSovraznikov();
    void ustvariSeznamSovraznikov();
    void izbrisiSovraznika(int);
    bool preveriKonec();
};

#endif