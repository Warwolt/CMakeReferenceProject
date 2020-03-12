#include <iostream>
#include "hello.h"
#include "extlib/extlib.h" // mock thirdparty dependency

int main()
{
    // mocking a test runner
    std::cout << identity("Runnings tests...") << std::endl; // use mock 3rd party library 'identity' function
    sayHello();
    std::cout << "All tests OK" << std::endl;
    return 0;
}