
#include <iostream>

int main()
{
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    int f = 0;
    int t = 0;
    std::cin >> f >> t;
    int max = 0;
    if (t > k)
    {
        max = f - (t - k);
    }
    else {
        max = f;
    }
    int u = 0;
    for (int i = 1;i < n;i++)
    {
        std::cin >> f >> t;
        if (t > k)
        {
            u = f - (t - k);
        }
        else
        {
            u = f;
        }
        if (u > max)
        {
            max = u;
        }
    }
    std::cout << max;
}

