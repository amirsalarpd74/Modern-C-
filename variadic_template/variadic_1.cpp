#include <iostream>
#include <map>

template <typename N>
auto summer(N n)
{
    return n;
}

template <typename N, typename... Args>
auto summer(N n, Args... args)
{
    return n + summer(args...);
}

int main()
{
    std::cout<<"add: "<< summer(4, 34.1, 13, 14, 15, 20) << std::endl;
    std::cout<<"add: "<< summer(4, 34, 13, 14, 15, 20) << std::endl;
}
