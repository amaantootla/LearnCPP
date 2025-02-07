#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Car
{
    public:
        // Basically just a struct so far
        // prefix with m_
        string m_model {};
        string m_plate {};
        int m_year {};

        // member function aka method
        // do not need to pass any data to the function, it can access all object properties
        void print()
        {
            cout << "Model: " << m_model << " Plate: " << m_plate << " Year: " << m_year << endl;
        }

};

int main()
{
    Car the_whip { "BMW", "111ladfr", 2023};
    the_whip.m_year = 2024;
    the_whip.print();

    return 0;
}