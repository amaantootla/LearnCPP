#include <iostream>
#include <string>

using namespace std;

class Car
{
    private:
        string model;
        string plate;
        unsigned int year;
    
    public:
        Car(string model="GENERIC", string plate="EXEMPT", unsigned int year=0)
        {
            this->model = model;
            this->plate = plate;
            this->year = year;
        }

        void setModel (string model) { this->model = model; }
        string getModel () { return model; }

        void setPlate(string plate) { this->plate = plate; }
        string getPlate() { return plate; }

        void setYear(unsigned int year) { this->year = year; }
        unsigned int getYear() { return year; }

        Car& operator= (const Car& car);
};

ostream& operator<< (ostream& out, Car& car)
{
    out << "Model: " << car.getModel() << '\n'
    << "Plate: " << car.getPlate() << '\n'
    << "Year: " << car.getPlate() << endl;

    return out;
}

Car& Car::operator= (const Car& car)
{
    // self-assignment gaurd
    // this is the ADDRESS of the CURRENT object
    // &car is the ADDRESS of the object passed in
    if (this == &car)
        // return the ACTUAL object via derefrencing the ADDRESS
        return *this;

    // copy over all the data from the passed in object
    // to our current object
    this->model = car.model;
    this->plate = car.plate;
    this->year = car.year;

    return *this;
}

int main()
{
    Car my_whip {"BMW", "09LAJI", 2024};

    // Copy init, works as expected
    Car other_whip = Car("BENZ", "1735AFTW", 2020);

    cout << my_whip;
    cout << other_whip;
}