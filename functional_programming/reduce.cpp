#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <ranges>
#include <numeric>

using namespace std;

int main()
{
    auto render = [](auto collection)
    {
        for (const auto& val : collection)
            std::cout << val << std::endl;
    };

    vector<int> in_collection{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int result = 0;

    // No side effect
    result = std::accumulate(in_collection.begin(), in_collection.end(), 0, [](int total, int val){ return total + val; });

    printf("result: %d \n", result);
}