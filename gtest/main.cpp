#include <iostream>
#include "foo.hpp"

int main()
{
    foo::Test t;
    std::cout << t.foo() << '\n';

    t.i_ = 100;
    std::cout << t.foo() << '\n';
    return 0;
}