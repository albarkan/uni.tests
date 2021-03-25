#include <iostream>
#include <math.h>


void func4()
{
    int n, m;

    std::cin >> m >> n;

    double a[m][n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            std::cin >> a[i][j];

    for (int j = 0; j < n; j++)
    {
        double minn = a[0][j];

        for (int i = 1; i < m; i++)
        {
            if (abs(a[i][j]) < abs(minn) || (abs(a[i][j]) == abs(minn) && a[i][j] < minn))
            {
                minn = a[i][j];
            }
        }

        std::cout << minn << "\n";
    }
}