#include <iostream>

extern "C"
{
void api_function1()
{
    std::cout << "Platform 2 IMPL: " << __FUNCTION__ << '\n';
}

void api_function2()
{
    std::cout << "Platform 2 IMPL: " << __FUNCTION__ << '\n';
}
} // extern "C"