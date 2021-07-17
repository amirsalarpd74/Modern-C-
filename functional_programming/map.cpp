#include <iostream>
#include <vector>
#include <functional>
#include <ranges>

using namespace std;

int main()
{
    auto render = [](auto collection)
    {
        for (const auto& val : collection)
            std::cout << val << std::endl;
    };

    vector<int> in_collection{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> out_collection;

    std::transform(in_collection.begin(), in_collection.end(), back_inserter(out_collection), 
         [](const int& val){ return val * 3;});

    render(out_collection);
}