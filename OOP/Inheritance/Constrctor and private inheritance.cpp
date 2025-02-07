#include <iostream>
#include <string>

using namespace std;

class Person
{   
    private:
        string name {};
        unsigned int age {};

    public:
        Person()
            : name {}, age {}
        {
        }

        Person(string name, unsigned int age)
        {
            this->name = name;
            this->age = age;
        }

        string getName() { return name; }
        unsigned int getAge() { return age; }
};

class SchoolMember : public Person
{
    private:
        string district_id {};
        unsigned int years_exp {};

    public:
        // choose constrctor of Base class
        // in the initilization list of child (SchoolMember)
        // CANNOT be in body
        SchoolMember(string name="", unsigned int age={}, string district_id="", unsigned int years_exp={})
            : Person(name, age)
        {
            this->district_id = district_id;
            this->years_exp = years_exp;
        }

        void print()
        {
            // must use PUBLIC access functions
            cout << getName() << ' ' << getAge()
            << ' ' << district_id << ' '
            << years_exp << endl;
        }
};

int main()
{
    SchoolMember me {"emaan", 18, "001", 4};
    me.print();
}

// child classes CANNOT access the private
// members of the parent class

// TIP: make sure your most derived class
// is ready to feed all base classes above it
// with the proper initilization list