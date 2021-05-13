#include <stdexcept>
#include <iostream>
#include <string>
#include <cstdint>


//#include "integer.h"
#include "integer.cpp" 

int main()
{
    Integer test;
    test.set_num(999999999);
    ++test;
    std::string lol("6999587688789096");
    Integer next(lol);
    //std::cin >> next;
    //next--;
    next = next + test;
    int bool; 
    std::cout << "################################\n\n";
    std::cout << next << " = next\n";
    std::cout << "\n################################\n\n";
    std::cout << test << " = test\n";

    //std::cout << "################################\n";
    //std::cout << "test = " << (number) << '\n';
    /*
    int64_t a = 120, b = 7, c = 1;
    c = a + b;
    std::cout << "a + b = " << c << '\n';
    c = a - b;
    std::cout << "a - b = " << c << '\n';
    c = a * b;
    std::cout << "a * b = " << c << '\n';
    c = a % b;
    std::cout << "a % b = " << c << '\n';
    c = a / b;
    std::cout << "a / b = " << c << '\n';
    */

}