#include <iostream>
#include <string>
int main()
{
    std::string input;
    std::string qwerty = "`1234567890-=~!@#$%^&*()_+QWERTYUIOP[]\\{}|ASDFGHJKL;':\"ZXCVBNM,./<>?";
    while (std::getline(std::cin, input))
    {
        for (char &c : input)
        {
            if (c != ' ')
            {
                c = qwerty[qwerty.find(c) - 1];
            }
        }
        std::cout << input << std::endl;
    };
    return 0;
}