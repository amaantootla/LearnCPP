#include <iostream>
#include <string>

using namespace std;

class Car
{
    private:
        string m_model;
        string m_plate;
        const int m_year;
    
    public:
        Car(string model="BMW", string plate="EXEMPT", int year=2000)
            : m_model { model }, m_plate { plate }, m_year { year }
        {
        }
};

// initializer list > assignment
// can set the value of const variables this way
// CLASS_NAME(args) : m_var1 { var1 }, m_var2 { var2 }, m_var3 { var3 }