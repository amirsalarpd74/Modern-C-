#include <iostream>
#include <ranges>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include "type_name.cpp"

auto print = [](auto& stream){ std::cout << stream << std::endl; };
auto square = [](auto& val){ return val * val; };

int main()
{
    std::vector<int> input_list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> output_list_1;

   // Map
    auto j = std::ranges::transform(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, square);
    print(j);
}