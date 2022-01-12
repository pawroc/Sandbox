#include "lib.hpp"
#include <iostream>

namespace library
{
void foo(std::optional<std::string> arg) {
    if (arg) {
        std::cout << "Hello " << *arg << " from lib!\n";
    }
    else {
        std::cout << "Hello from lib!\n";
    }
}
} // namespace library