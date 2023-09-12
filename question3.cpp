#include <iostream>
int reverse(int n)
{
    int result = 0;
    while (n > 0)
    {
        result = result * 10 + n % 10;
        n /= 10;
    }
    return result;
}
int main()
{
    int lines;
    std::cin >> lines;
    int n;
    for (; lines > 0; --lines)
    {

        std::cin >> n;
        int times = 0;
        while (1)
        {
            int r = reverse(n);
            if (r == n)
            {
                break;
            }
            else
            {
                n += r;
                ++times;
            }
        }
        std::cout << times << " " << n << std::endl;
    }
    return 0;
}
