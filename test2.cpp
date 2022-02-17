#include <iostream>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>

int enumerate(std::string number, int min, int max, int& counter)
{
    if (number.empty())
        counter += 1;
    for (int n = 1; n < number.size() ; n++)
    {
        std::cout << number.size() <<number.substr(0, n) << std::endl;
//        if (std::stoi(number.substr(0, n)) >= min && std::stoi(number.substr(0 , n)) <= max)
//            return enumerate(number.substr(0, n), min, max, counter);
    }
    return 1;
}

int main()
{
    std::string number;
    int min, max, counter = 0;
    std::cin >> number;
    std::cin >> min;
    std::cin >> max;

    enumerate(number, min, max, counter);
    std::cout << number;
}