#include <iostream>
#include "hello.h"
#include "extlib.h" // mock thirdparty dependency

// faking automatic test suite detection
void sayHelloTests();
void addTests();
void subTests();

int main()
{
    // mocking a test runner
    std::cout << identity("Runnings tests...") << std::endl; // use mock 3rd party library 'identity' function
    sayHelloTests();
    addTests();
    subTests();
    std::cout << "All tests OK" << std::endl;
    return 0;
}
