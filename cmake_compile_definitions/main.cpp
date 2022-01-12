#include <iostream>

int main()
{
#ifdef TEST_EN
    std::cout << "ENABLED: " << TEST_EN << "\n";
#else
    std::cout << "DISABLED\n";
#endif
}