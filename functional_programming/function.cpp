#include <iostream>
#include <functional>
#include <string>

void demo_function()
{
    printf("It's demo function. \n");
}

void function_with_variable(std::string name)
{
    printf("Hello, I'm %s.\n", name.c_str());
}

class functor
{
public:
    void operator()() 
    {
        printf("Operator ().\n");
    }
};

int main()
{
    std::vector<std::function<void()>> function_list;

    function_list.push_back(demo_function);

    functor functor_instance;
    function_list.push_back(functor_instance);

    function_list.push_back(std::bind(&function_with_variable, "AmirSalar"));

    for (const auto& func : function_list)
        func();
}

