#include <iostream>
#include <fstream>

void func1()
{
    std::ifstream in( "input" , std::ifstream::binary);
    if (!in.is_open()){
        std::cerr << "ERROR\n";
        return ;
    }
    int n = 0;
    double val;
    while ( in >> val ){
        if (val > 100){
            ++n; 
        }
    }
    in.close();
    std::cout << n << '\n';
}
