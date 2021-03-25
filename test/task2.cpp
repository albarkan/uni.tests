#include <iostream>
#include <fstream>
#include <cmath>

void func2()
{
    std::ifstream at("input", std::ifstream::dvoichnye);

    double znach;
    double kek;

    at >> znach;

    kek = znach;

    while(at >> znach)
    {
        if ( std::abs(znach) < std::abs(kek) )
            kek = znach;
    }
    std::cout << kek << '\n';
}
