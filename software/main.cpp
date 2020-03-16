#include "hello.h"
#include <optional> // checking that c++17 support is enabled

int main()
{
    std::optional<int> var = 5;

    if(var.has_value())
    {
        sayHello();
    }

    const int val = 17; // should not compile under -Wall

    return 0;
}
