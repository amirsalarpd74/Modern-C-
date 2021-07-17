#include <iostream>

auto incrementer = [](int initial_value, int add_by)
{
    int increment = initial_value;
    return [increment, add_by]() mutable{
        return increment += add_by;
    }; 
};


int main()
{
    auto in = incrementer(100, 10);

    std::cout << "Increment when call it: "<< in() << std::endl;
    std::cout << "Increment when call it: "<< in() << std::endl;
    std::cout << "Increment when call it: "<< in() << std::endl;
    std::cout << "Increment when call it: "<< in() << std::endl;
    std::cout << "Increment when call it: "<< in() << std::endl;
    std::cout << "Increment when call it: "<< in() << std::endl;
}