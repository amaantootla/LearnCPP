#include <iostream>
#include <string>

class Car
{
    public:
        std::string name;
        int year;

        Car()
            : name {}, year {}
        {
        }

        Car(std::string name, int year)
        {
            this->name = name;
            this->year = year;
        }

        void whoAmI() { std::cout << "I am a car" << std::endl; }

    protected:
        bool is_lux;
};

class Benz : public Car
{
    public:
        Benz()
            : Car()
        {
            is_lux = true;
        }

        Benz(std::string name, int year)
            : Car(name, year)
        {
            is_lux = true;
        }

        void whoAmI()
        {
            // Use base class version
            Car::whoAmI();

            // plus our own funcinality
            if (is_lux)
            {
                std::cout << "I am luxary" << std::endl;
            }

            std::cout << "I am a Benz!" << std::endl;
        }
};

int main()
{
    Car my_whip { "BMW", 2024 };
    my_whip.whoAmI();

    Benz other_whip {};
    other_whip.whoAmI();
}