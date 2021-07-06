#include <iostream>
#include <concepts>
#include <type_traits>

// Add one step more
template<typename T>
concept Integral =  std::is_integral<T>::value;

template<typename T>
requires Integral<T> // requires clause -- compile time -- const expression
void check(T t)
{
    printf("Hello world!! :)) \n");
}

int main()
{
    int a;
    check(a);
    return 0;
    
}