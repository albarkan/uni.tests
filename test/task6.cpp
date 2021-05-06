#include <iostream>
#include <fstream>

static const size_t INF = 1000000000000000000;

int main()
{
    std::fstream file("input");
    
    size_t k = 0, q = 4, pos = INF, neg = INF;
    for (int32_t i = 0, tmp; !file.eof(); ++i){
        ++k;
        file.read(reinterpret_cast<char*>(&tmp), q);
        std::cout << tmp << '\n';
        if (tmp < 0)
            neg = i;
        if (pos == INF && tmp > 0)
            pos = i;
    }
    
    file.close();
    
    
    file.open("input");
    int32_t posVal, negVal;
    
    file.seekg(q * pos, std::fstream::beg);
    file.read(reinterpret_cast<char*>(&posVal), q);
    file.seekg(q * neg, std::fstream::beg);
    file.read(reinterpret_cast<char*>(&negVal), q);
    
    file.seekg(q * pos, std::fstream::beg);
    file.write(reinterpret_cast<char*>(&negVal), q);
    file.seekg(q * neg, std::fstream::beg);
    file.write(reinterpret_cast<char*>(&posVal), q);   

    file.close();
}
