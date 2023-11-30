
#include <iostream>

int main()
{
    int g=0;
    std::cin >> g;
    for (int i = g+1; i < 9999; i++)
    {
        int a = i / 1000;
        int b = i / 100 % 10;
        int c = i % 100 / 10;
        int d = i % 10;
        if (a != b && a != c && a != d && b != c && b != d && c != d)
        {
            std::cout << i;
            break;
        }
    }
}

