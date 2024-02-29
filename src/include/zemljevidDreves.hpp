#ifndef ZEMLJEVIDDREVES_HPP
#define ZEMLJEVIDDREVES_HPP

#include "drevo.hpp"
#include <vector>

class zemljevidDreves {
    public:
    std::vector<drevo> zemljevid;
    zemljevidDreves():zemljevid(80) {}
    void ustvariZemljevidDreves();
    void uniciDrevo(int);
};

#endif