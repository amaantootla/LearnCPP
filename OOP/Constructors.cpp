#include <iostream>
#include <string>

using namespace std;

class Car
{
    private:
        string m_model;
        string m_plate;
        int m_year;

    public:
        /* Car() // sets default values
        {
            m_model = "BMW";
            m_year = 2000;
            m_plate = "DMV EXEMPT";
        } */

        Car(string model="BMW", int year=2000, string plate="DMW EXEMPT") // argument constructor 
                                                               // (overloaded function)
                                                               // default values serves as
                                                               // default constrcutor too
        {
            m_model = model;
            m_year = year;
            m_plate = plate;
        }

        string getModel() { return m_model; }
        string getPlate() { return m_plate; }
        int getYear() { return m_year; }
};

int main()
{
    Car whip {}; // {} will invoke the default constructor
    Car whip2 { "TOYOTA", 1999, "91728LAJ"}; // argument constrcutor 
    cout << whip.getModel() << whip.getPlate() << whip.getYear() << endl;
}

// use {} for the default constructor, although not technically required