#include <iostream>
#include <map>
#include <ranges>
#include <string>

int main()
{
    auto render = [](const auto& container)
        {
            for (auto& [name, val] : container)
                std::cout << "name: " << name << " value: " << val << std::endl;
        };

    std::map<std::string, int> map;

    map["Hello"] = 100;

    map["World"] = 200;

    render(map);
    std::cout << "Reverse \n";
    render(std::ranges::reverse_view(map));    

}