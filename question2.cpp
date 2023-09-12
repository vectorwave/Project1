#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int number[10][7] = {
    {1, 1, 1, 0, 1, 1, 1},
    {0, 0, 1, 0, 0, 1, 0},
    {1, 0, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {0, 1, 1, 1, 0, 1, 0},
    {1, 1, 0, 1, 0, 1, 1},
    {1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 0}};
int main()
{
    int s;
    int n;

    while (1)
    {

        std::cin >> s >> n;
        if (s == 0 && n == 0)
        {
            break;
        }

        vector<int> digits;
        while (n > 0)
        {
            int digit = n % 10;
            digits.insert(digits.begin(), digit);
            n /= 10;
        }

        std::string hline(s, '-');
        std::string hlineb(s, ' ');
        std::string vline(s, ' ');
        for (int n : digits)
        {
            std::cout << n;
        }
        std::cout << std::endl;
        for (int n : digits)
        {
            std::cout << " " << (number[n][0] ? hline : hlineb) << " "
                      << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < s; i++)
        {
            for (int n : digits)
            {
                std::cout << (number[n][1] ? "|" : " ") << vline << (number[n][2] ? "|" : " ") << " ";
            }
            std::cout << std::endl;
        }

        for (int n : digits)
        {
            std::cout << " " << (number[n][3] ? hline : hlineb) << " "
                      << " ";
        }
        std::cout << std::endl;
        for (int i = 0; i < s; i++)
        {
            for (int n : digits)
            {
                std::cout << (number[n][4] ? "|" : " ") << vline << (number[n][5] ? "|" : " ") << " ";
            }
            std::cout << std::endl;
        }

        for (int n : digits)
        {
            std::cout << " " << (number[n][6] ? hline : hlineb) << " "
                      << " ";
        }
        std::cout << std::endl;
    }
}