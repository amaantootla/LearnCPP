#include <iostream>
#include <string>

using namespace std;

struct car
{
    string model;
    string brand;
    int year;
};

int main()
{
    car my_car;
    my_car.model = "GSX";
    my_car.brand = "BWM";
    my_car.year = 2023;
    cout << my_car.model << '\n' << my_car.brand << '\n' << my_car.year << '\n';

}

// C-style