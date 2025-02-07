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
        Car(string model, string plate, unsigned int year)
        {
            this->model = model;
            this->plate = plate;
            this->year = year;
        }

        friend ostream& operator<<(ostream& out, Car& car);
        friend ifstream& operator>>(ifstream& in, Car& car);
};

ostream& operator<< (ostream& out, Car& car)
{
    out << car.model << ' ' << car.plate << ' ' << car.year << endl;
    return out;
}

#if 0 
ifstream& operator>> (ifstream& in, Car& car)
{
    in >> car.model;
    in >> car.plate;
    in >> car.year;

    return in;
}
#endif

int main()
{
    Car whip {"BMW", "EXEMPT", 100};
    cout << whip;
}