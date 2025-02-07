#include <iostream>
#include <string>

using namespace std;

class Car
{
    private:
        string m_model {};
        string m_plate {};
        int m_year {};
    
    public:
        void setCar(string model, string plate, int year)
        {
            m_model = model;
            m_plate = plate;
            m_year = year;
        }

        void print()
        {
            cout << "Model: " << m_model << " Plate: " << m_plate << " Year: " << m_year << endl;
        }

        void copyCar(Car& another_car)
        {
            // this function takes in a object (in this case a class)
            // as a reference and can read all its private members
            m_model = another_car.m_model;
            m_plate = another_car.m_plate;
            m_year = another_car.m_year;
        }
};

// Public members can be accesed by anyone 
// i.e. any function or variable declaration outside the class
// where Private members can only be seen by other class members
// i.e. member functions

// member variables should be PRIVATE
// member functions should be PUBLIC