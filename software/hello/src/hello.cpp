#include <iostream>
#include "add.h" // testing cross-module includes

void sayHello()
{
    std::cout << "Hello CMake!" << std::endl;
}

void sayCalculation()
{
    std::cout << "2 + 3 = " << add(2, 3) << std::endl;
}
