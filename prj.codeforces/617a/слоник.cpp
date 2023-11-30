
#include <iostream>

int main()
{
    int a;
    std::cin >> a;
    int n = 0;
    n = (a / 5);
    if (a % 5 != 0)
    {
        n = n + 1;
    }
    std::cout << n;
}
