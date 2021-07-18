
#include <iostream>

template <int N>
struct fiboonachi
{
    enum{
    value = fiboonachi<N-1>::value + fiboonachi<N-2>::value
    };
};

template<>
struct fiboonachi<1>
{
 enum{
      value = 1
    };
};

template<>
struct fiboonachi<0>
{
enum{
      value = 1
    };
};

int main()
{
    std::cout << "fibo 0: " << fiboonachi<0>::value << "\n";
    std::cout << "fibo 1: " << fiboonachi<1>::value << "\n";
    std::cout << "fibo 2: " << fiboonachi<2>::value << "\n";
    std::cout << "fibo 3: " << fiboonachi<3>::value << "\n";
    std::cout << "fibo 4: " << fiboonachi<4>::value << "\n";
    std::cout << "fibo 5: " << fiboonachi<5>::value << "\n";
    std::cout << "fibo 6: " << fiboonachi<6>::value << "\n";
    std::cout << "fibo 11: " << fiboonachi<11>::value << "\n";
    std::cout << "fibo 12: " << fiboonachi<12>::value << "\n";
    std::cout << "fibo 45: " << fiboonachi<45>::value << "\n";
}