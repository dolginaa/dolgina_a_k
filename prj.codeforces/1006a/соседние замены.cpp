
#include <iostream>
#include <vector>
int main()
{
    int n = 0;
    std::cin >> n;
    std::vector <int> a;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    int max = a[1];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max) max = a[i];
    }
    int k = 2;
    while (k <= max)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] = k)
            {
                a[i] = k - 1;
            }

        }
        k = k + 2;
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i];
    }
}