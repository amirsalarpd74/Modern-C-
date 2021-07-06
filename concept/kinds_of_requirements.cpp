#include <iostream>
#include <concepts>
#include <type_traits>
#include <string>
#include <functional>

// Add one step more
template<typename T>
concept Integral =  requires (T t, int a)
{
   // std::is_integral<T>::value;
    { t + a };  // { value expression } in this model, type T must has operator+
    { t.add(a) };  // type T must have function with name add and single integer argument
    { t() } -> std::same_as<std::string>; // { value expression } -> type or concept
    { t + a } -> std::same_as<T>;
};

struct A
{
    A()
    : number(10)
    , name("Amir Salar")
    {
    }

    A operator+(int b)
    {
        this->number += b;
        return *this;
    }

    std::string operator()()
    {
        return name;
    }

    void add(int b)
    {
        this->number += b;
    }

    const std::string& get_name()
    {
        return name;
    } 

    private:
        int number = 0;
        std::string name;
};

template<typename T>
requires Integral<T> // requires clause -- compile time -- const expression
void check(T t)
{
    printf("Hello \n\t%s !!! :)) \n", t.get_name().c_str());
}

int main()
{
    A a;
    check(a);
    return 0;
    
}