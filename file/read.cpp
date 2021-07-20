#include <iostream>
#include <fstream>
#include <ranges>
#include <algorithm>
#include <vector>

auto join_character_in_each_subranges = [](auto &&rng) { return std::string_view(&*rng.begin(), std::ranges::distance(rng)); };
auto trimming = std::ranges::views::filter([](auto&& character){ return !std::isspace(character);});

typedef std::vector<double> LineList;
typedef std::vector<LineList> List;

int main () {
    std::ifstream myfile; 
    std::string myline;
    List list;

    myfile.open("data.txt");
    
    while (std::getline(myfile, myline))
    {
        LineList line_list;
        for (auto words : myline 
                | std::ranges::views::split(',') 
                | std::ranges::views::transform(join_character_in_each_subranges))
        {
            auto words_trimming = words | trimming;
            std::string clean_numbers;
            std::ranges::for_each(words_trimming, [&](auto character){ clean_numbers += character;});
                        
            line_list.push_back(atof(clean_numbers.c_str()));
        }

        list.push_back(line_list);
    }
}