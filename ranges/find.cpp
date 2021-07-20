#include <iostream>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <unistd.h>
#include "type_name.cpp"

auto print = [](auto& stream){ std::cout << stream << std::endl; };
auto even = [](auto& val){ return val % 2 == 0; };

std::string gen_random(const int len) {
    
    std::string tmp_s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    
    srand( (unsigned) time(NULL) * getpid());

    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) 
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    
    
    return tmp_s;
}

int main()
{
    //auto x = gen_random(10);
    std::vector<std::string> name_list = {"Ali", "Salar", "Ahmad"};
    //  it = std::ranges::find(name_list | std::ranges::views::join , 'A');
    std::cout << type_name<decltype(name_list | std::ranges::views::join)>() << "\n";

    // std::cout << *it << std::endl;
}