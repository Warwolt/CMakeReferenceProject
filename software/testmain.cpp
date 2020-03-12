#include <iostream>
#include "hello.h"
#include "extlib.h" // mock thirdparty dependency

void sayHelloTests(); // faking automatic test suite detection

int main()
{
    // mocking a test runner
    std::cout << identity("Runnings tests...") << std::endl; // use mock 3rd party library 'identity' function
    sayHelloTests();
    std::cout << "All tests OK" << std::endl;
    return 0;
}