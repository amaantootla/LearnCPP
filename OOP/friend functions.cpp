#include <iostream>
#include <string>

using namespace std;

// Forward declaration
class Plane;

class Car
{
    private:
        string model;
        string plate;
        unsigned int year;
    
    public:
        void setModel (string model) { this->model = model; }
        string getModel () { return model; }

        void setPlate(string plate) { this->plate = plate; }
        string getPlate() { return plate; }

        void setYear(unsigned int year) { this->year = year; }
        unsigned int getYear() { return year; }

        // printYear() can now access the private members of this class
        friend void printYear(Car& car, Plane& plane);

        // every member of class Collection can view private members
        // of this class
        // TIP: also serves as a forward declaration for the class!
        friend class Collection;
};

class Plane
{
    private:
        string model;
        unsigned int year;
    
    public:
        // since printYear() also accesses the private members of this class
        // it must also be declared a friend here
        friend void printYear(Car& car, Plane& plane);

        friend class Collection;
};

class Collection
{
    public:
        void SeeCollection(Car& car, Plane& plane)
        {
            cout << car.model << ' ' << car.plate << ' ' << car.year << endl;
            cout << plane.model << ' ' << plane.year << ' ' << endl; 
        }
};

void printYear(Car& car, Plane& plane)
{
    cout << car.year << endl;
    cout << plane.year << endl;
};