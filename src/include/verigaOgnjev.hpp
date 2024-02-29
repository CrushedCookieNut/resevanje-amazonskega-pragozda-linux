#ifndef VERIGAOGNJEV_HPP
#define VERIGAOGNJEV_HPP

#include "ogenj.hpp"
#include <vector>

class verigaOgnjev {
    public:
    std::vector<ogenj> veriga;
    void ustvariVerigoOgnjev();
    void izbrisiOgenj(int);
    void izrisiVerigoOgnjev();
};

#endif