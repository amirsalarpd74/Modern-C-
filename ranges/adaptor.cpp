#include <iostream>
#include <ranges>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include "type_name.cpp"

auto print = [](auto& stream){ std::cout << stream << std::endl; };
auto even = [](auto& val){ return val % 2 == 0; };
auto square = [](auto& val){ return val * val; };

int main()
{
    std::vector<int> input_list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> output_list_1;

    printf("Map functional programming. \n");
   // Map
   for (auto&& i : input_list | std::ranges::views::transform(square))
        print(i);

    // Map equvalence
    if (std::ranges::equal(
            input_list | std::ranges::views::transform(square), 
            std::ranges::views::transform(input_list, square)))
        print("Is Equal. \n");
        
    printf("Filter functional programming. \n");

    // Filter
     for (auto&& i : input_list | std::ranges::views::filter(even))
        print(i);

    // Filter equvalence
    if (std::ranges::equal(
            input_list | std::ranges::views::filter(even), 
            std::ranges::views::filter(input_list, even)))
        print("Is Equal. \n");

    std::cout << type_name<decltype(input_list | std::ranges::views::filter(even))>() << "\n";
}