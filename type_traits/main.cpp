#include <iostream>
#include "has_function.hpp"
#include "has_constructor.hpp"


struct Test
{
    Test() = default;
    // Test(const Test&) = default;
    Test(const Test&) = delete;
    // Test& operator=(const Test&) = default;
    // Test& operator=(const Test&) = delete;
};


#include <utility>
#include <iostream>
 
struct Default { int foo() const { return 1; } };
 
struct NonDefault
{
    NonDefault() = delete;
    int foo() const { return 1; }
};

int main()
{
    std::cout << is_constructable<Test>::value << '\n';
    std::cout << is_copy_constructable<Test>::value << '\n';
}