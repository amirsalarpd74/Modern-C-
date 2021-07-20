#include <iostream>
#include <ranges>
#include <vector>

int main()
{
    auto render = [](auto&& container)
    {
        for (auto& i : container)
            std::cout << "i: " << i << std::endl;
    };

    std::vector<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto odds = std::ranges::filter_view(list, [](int i){ return i % 2 == 1;});

    std::ranges::filter_view evens{list, [](int i){ return i % 2 == 0;}};
    
    auto three = list | std::ranges::views::filter([](int i) { return i % 3 == 0; });

    printf("odds \n");
    render(odds);

    printf("evens \n");
    render(evens);

    printf("three \n");
    render(three);
}