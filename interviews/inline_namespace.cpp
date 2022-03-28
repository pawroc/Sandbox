#include <iostream>

/**
 * @brief Inline namespaces can be used for library versioning.
 *        It is possible to have multiple definitions of the same
 *        function. 
 */

namespace Lib
{
inline namespace v1
{
    void foo() {
        std::cout << "v1\n";
    }
} // inline namespace v1

inline namespace v2
{
    void foo() {
        std::cout << "v2\n";
    }
} // inline namespace v2

void fuu() {
    v1::foo();
    v2::foo();
}
} // namespace Lib


int main()
{
    // Use of the version 1 of the library
    {
        using namespace Lib::v1;
        foo();
    }
    // Use of the version 2 of the library
    {
        using namespace Lib::v2;
        foo();
    }
    // Multiple definition error
    // {
    //     using namespace Lib;
    //     foo();
    // }

    Lib::fuu();
}