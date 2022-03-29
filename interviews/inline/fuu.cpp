#include "fuu.hpp"
#include <iostream>

void fuu() {
    std::cout << "fuu.cpp: inlineVar (addr) = " << &inlineVar << '\n';
    foo();
}