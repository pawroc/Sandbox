#pragma once

#include <iostream>

/**
 * @brief The variable can be defined multiple times but there is only one
 * instance of the variable in the program (since C++17).
 */
inline int inlineVar = 100;

/**
 * @brief The function can be included in multiple places as long as its
 * definition doesn't change (similarily to the statci keyword which makes
 * the function's linkage internal).
 */
inline void foo() {
    std::cout << "foo: " << inlineVar << ", (addr) = " << &inlineVar << '\n';
}