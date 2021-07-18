#include <iostream>
#include <boost/hana.hpp>

struct Car
{
    std::string name;
};

struct Motor
{
    std::string name;
};

struct Truck
{
    std::string name;
    int length;
};

int main()
{
    auto vehicles = boost::hana::make_tuple(Car{"Pride"}, Truck{"Volvo", 120}, Motor{"Kavir"});

    auto has_length = boost::hana::is_valid([](auto &&x) -> decltype((void) x.length ){});

    auto trucks = boost::hana::filter(vehicles, has_length);

    auto non_trucks = boost::hana::filter(vehicles, boost::hana::compose(boost::hana::not_, has_length));

    boost::hana::for_each(trucks, [](auto& vehicle)
        {
            std::cout << " trucks: " << vehicle.name << "bed len: "<< vehicle.length << "\n";
        });

    boost::hana::for_each(non_trucks, [](auto& vehicle)
        {
            std::cout << " non trucks: " << vehicle.name << "\n";
        });
}