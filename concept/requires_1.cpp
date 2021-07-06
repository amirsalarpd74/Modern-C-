#include <iostream>
#include <concepts>
#include <type_traits>

template<typename T>
requires std::is_integral<T>::value
void check(T t)
{
    printf("Hello world! :)) \n");
}

int main()
{
    int a;
    check(a);
    return 0;
    
}