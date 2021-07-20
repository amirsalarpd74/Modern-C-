#include <iostream>
#include <ranges>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

auto print = [](auto& stream){ std::cout << stream << std::endl; };
auto even = [](auto& val){ return val % 2 == 0; };


struct Student
{
    std::string name;
    uint32_t score;

    friend std::ostream &operator<<( std::ostream &output, const Student &student)
    {
            output << "Name: " << student.name << " Score: " << std::to_string(student.score);
            return output;
    }
};

int main()
{
    std::vector<int> input_list = {6, 7, 4, 5, 8, 9, 10, 1, 2, 3};
    std::vector<int> output_list_1;

    // Seperate event elements
    std::ranges::copy_if(input_list, std::back_inserter(output_list_1), even);
    std::ranges::for_each(output_list_1, print);

    std::ranges::sort(output_list_1);
    std::ranges::for_each(output_list_1, print);

    // Sort with projection
    printf("sort with projection. \n");
    std::vector<Student> input_list_2 = {{"Amir", 10}, {"Salar", 8}, {"Pouya", 14}, {"AmirSalar", 18}, {"Ehsan", 17}};

    std::ranges::sort(input_list_2, std::less<>{}, [](auto& student){ return student.score; });
    std::ranges::for_each(input_list_2, print);
}