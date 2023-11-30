
#include <iostream>

int main()
{
    int n, d;
    std::cin >> n >> d;
    int x1;
    std::cin >> x1;
    int k = 2;
    for (int i = 1;i < n;i++)
    {
        int x2;
        std::cin >> x2;
        if ((x2 - x1) == 2*d) k++;
        if ((x2 - x1) > 2 * d) k += 2;
        x1 = x2;
    }
    std::cout << k;
}

