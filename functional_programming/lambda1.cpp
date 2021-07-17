#include <iostream>

auto add = [](int a){
    return [a](int b){
        return [a, b](int c){
            return a + b + c;
        };
    };
};

auto incrementer = []()
{
    int increment = 0;
    return [increment]() mutable{
        return ++increment;
    };
};


int main()
{
    auto add1 = add(1)(2);
    std::cout << add1(3) << std::endl;

    auto in = incrementer();

    std::cout << "Increment when call it: "<< in() << std::endl;
    std::cout << "Increment when call it: "<< in() << std::endl;
    std::cout << "Increment when call it: "<< in() << std::endl;
    std::cout << "Increment when call it: "<< in() << std::endl;
    std::cout << "Increment when call it: "<< in() << std::endl;
    std::cout << "Increment when call it: "<< in() << std::endl;
}