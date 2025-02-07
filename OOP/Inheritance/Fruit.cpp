#include <iostream>

class Fruit
{
    private:
        std::string name {};
        std::string color {};
    
    public:
        Fruit(std::string pname, std::string pcolor)
            : name {pname}, color {pcolor}
        {
        }

        std::string getName() const { return name; }
        std::string getColor() const { return color; }
};

class Apple : public Fruit
{
    private:
        double fiber {};
    
    public:
    Apple(std::string name, std::string color, double fiber)
        : Fruit(name, color)
    {
        this->fiber = fiber;
    }

    double getFiber() const { return fiber; }
};

class Banana : public Fruit
{
    public:
        Banana(std::string name, std::string color)
            : Fruit(name, color)
        {
        }
};

std::ostream& operator<<(std::ostream& out, const Apple& a)
{
    out << "Apple(" << a.getName() << ", "
    << a.getColor() << ", "
    << a.getFiber() << ")";

    return out;
}

std::ostream& operator<<(std::ostream& out, const Banana& b)
{
    out << "Banana(" << b.getName() << ", "
    << b.getColor() << ")";

    return out;
}

int main()
{
	const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';

	return 0;
}