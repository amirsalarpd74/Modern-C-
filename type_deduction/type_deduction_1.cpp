#include <iostream>

// In CPP03 type deduction only means for template.

template <typename T, int count>  // template parameters
void print_sth(T t) // parameters type
{
    printf("T: %s %d\n", t.to_string().c_str(), count);
}

template <typename T> // template parameters: int
void change(T& t, T tt) // int& t, int tt
{
    t += 100;
    tt += 100;
}

struct A
{
    std::string to_string()
    {
        return "Hello World D:";
    }
};

int main()
{
    print_sth<A, 4>(A());

    int ii = 20;
    int jj = 20;
    int& i = ii;
    int& j = jj;

    change<int&>(i, j); // I deduce the type int& -> int& i, int& j
    printf("i: %d  j: %d \n", i, j); // i: 110  j: 120

    change(i, j);  // deduce type with compiler -> int& i, int j
    printf("i: %d  j: %d \n", i, j); // i: 210  j: 120
}