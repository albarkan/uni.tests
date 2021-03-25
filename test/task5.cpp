#include <iostream>
#include <string>

void func5()
{
    string s;

    std::cin >> s;


    int i = 0, cnt = 0;
    s += "\n";

    while (s[i] != '\n')
    {
        if (s[i] == 'h')
            cnt++;

        if (cnt == 2)
            std::cout << i;

        i++;
    }

    if (cnt == 0)
        std::cout << -2;
    if (cnt == 1)
        std::cout << -1;
}