#include <iostream>

template <int N>
int factorial()
{
    return N * factorial<N-1>();
}

template <>
int factorial<1>()
{
    return 1;
}

int main()
{
    std::cout << factorial<5>() << std::endl;
}