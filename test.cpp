#include <iostream>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>
int main()
{
    std::string str;
    std::cin >> str;
    std::map<int, int> mapping;
    std::string final;
    while(1) {
        mapping.clear();
        for (auto ch : str)
            mapping[static_cast<int>(ch) - 48]++;

        std::string number = "";
        std::string pre = "";
        for (auto value : mapping) {
            if (value.second > 1)
                pre += std::to_string(value.second);
            number += std::to_string(value.first);
        }
        final = number + pre;

        if (final == str)
            break;
        str = number + pre;

    }
    std::vector<char> list;

    for (auto x : final)
        list.push_back(x);
    std::sort(list.begin(), list.end());
    for (auto x : list)
        std::cout << x;
    std::cout << std::endl;
}