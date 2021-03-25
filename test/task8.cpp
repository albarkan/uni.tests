#include <fstream>  
#include <algorithm>  
#include <iostream>  

void func8()
{

    std::ifstream file("input");
    char inp;
    long long int cnt = 0, ans;
    file.get(inp);
    while (!file.eof())
    {
        if (inp != '\0')
            ++cnt;
        else {
            ans = std::max(ans, cnt);
            cnt = 0;
        }
        file.get(inp);
    }
    std::cout << cnt;
}