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
        string getModel() { return m_model; }
        void setModel(string model) { m_model = model; }

        string getPlate() { return m_plate; }
        void setPlate(string plate) { m_plate = plate; }

        int getYear() { return m_year; }
        void setYear(int year) { m_year = year; }

};

int main()
{
    Car whip;
    whip.setModel("BMW");
    whip.setPlate("8291dlj");
    whip.setYear(2024);

    cout << whip.getModel() << whip.getPlate() << whip.getYear() << endl;
}

// Ensure getters return read-only data
// i.e. value OR const referneces