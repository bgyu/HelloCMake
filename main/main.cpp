#include <iostream>
#include "calc.h"

int main()
{
    std::cout << "hello from HelloLinux" << std::endl;

    int x = 100;
    int y = 4;    

    std::cout << x << '+' << y << '=' << calc::add(x, y) << std::endl;
    std::cout << x << '-' << y << '=' << calc::sub(x, y) << std::endl;
    std::cout << x << '*' << y << '=' << calc::mul(x, y) << std::endl;
    std::cout << x << '/' << y << '=' << calc::div(x, y) << std::endl;

    return 0;
}
