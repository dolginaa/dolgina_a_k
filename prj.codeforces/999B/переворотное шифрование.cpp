
#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    char s[]="thisisexamplefor";
    std::cin >> s;
    for (int i = 1; i <= (n / 2); i++)
    {
        if (n % i == 0)
        {
            for (int j = 0; j <= (i - 1) / 2; j++)
            {
                char f = s[i - j - 1];
                s[i - j - 1] = s[j];
                s[j] = f;
            }
        }
    }
    for (int j = 0; j <= (n - 1) / 2; j++)
    {
        char f = s[n - j - 1];
        s[n - j - 1] = s[j];
        s[j] = f;
    }
    std::cout << s;
}

