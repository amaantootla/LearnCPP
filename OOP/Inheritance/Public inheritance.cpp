#include <iostream>
#include <string>

using namespace std;

// Very general
class Person
{   
    public:
        string name {};
        unsigned int age {};

        Person(string name="", unsigned int age={})
        {
            this->name = name;
            this->age = age;
        }
};

// More specific
class SchoolMember : public Person
{
    // SchoolMember will already have a
    // string name
    // unsigned int ag
    // because it inheritied from Person

    public:
        string district_id {};
        unsigned int years_exp {};

        SchoolMember(string district_id="", unsigned int years_exp={})
        {
            this->district_id = district_id;
            this->years_exp = years_exp;
        }

        void print()
        {
            cout << name << ' ' << age
            << ' ' << district_id << ' '
            << years_exp << endl;
        }
};

// When a derived class is created
// all of its parents are constrcuted first 
// i.e. the Class() constructor is called
// in order from parent to child