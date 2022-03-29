#include <iostream>

/**
 * @brief Notice that we do not include api.hpp
 * 
 */
extern "C"
{
void api_function1()
{
    std::cout << "Platform 1 IMPL: " << __FUNCTION__ << '\n';
}

void api_function2()
{
    std::cout << "Platform 1 IMPL: " << __FUNCTION__ << '\n';
}
} // extern "C"