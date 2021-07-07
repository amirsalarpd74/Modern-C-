#include <iostream>

// In CPP03 type deduction only means for template.

template <typename T>  // template parameters
void print_sth(T t) // parameters type
{
    printf("T: %s \n", t.to_string().c_str());
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
    print_sth<A>(A());

    int ii = 10;
    int jj = 20;
    int& i = ii;
    int& j = jj;

    change<int>(i, j);
    printf("i: %d  j: %d \n", i, j);
}