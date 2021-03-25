#include <iostream>

void func3()
{
    int m, n;

    std::cin >> m >> n;

    int a[m][n];

    a[0][n - 1] = 2;
    for (int i = n - 2; i >= 0; i--)
        a[0][i] = 2 * a[0][i + 1];

    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            a[i][j] = a[i - 1][j + 1];
        }
        a[i][n - 1] = a[i - 1][n - 1] * 2;
    }


    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }
}