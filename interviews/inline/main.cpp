#include "foo.hpp"
#include "fuu.hpp"
#include <iostream>

int main() {
    std::cout << "main.cpp: inlineVar (addr) = " << &inlineVar << '\n';
    fuu();
    foo();
}