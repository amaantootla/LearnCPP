#include <iostream>
#include <vector>

class Shape
{
  protected:
    virtual std::ostream& print(std::ostream& out) = 0;
    friend std::ostream& operator<<(std::ostream& out, Shape& s)
    {
        return s.print(out);
    };

    public:
        virtual ~Shape() = default;
};

class Point
{
private:
	int m_x{};
	int m_y{};

public:
	Point(int x, int y)
		: m_x{ x }, m_y{ y }
	{

	}

	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		return out << "Point(" << p.m_x << ", " << p.m_y << ')';
	}
};

class Circle : public Shape
{
    private:
        Point p;
        int rad;
    
    public:
        Circle(Point x, int y)
            : p { x }, rad { y }
        {
        }

        std::ostream& print(std::ostream& out) override
        {
            out << "Circle(";
            out << p;
            out << ", radius ";
            out << rad;
            out << ")";
            out << std::endl;
            return out;
        }

        int getRadius() { return rad; }
};

class Triangle : public Shape
{
    private:
        Point p1;
        Point p2;
        Point p3;
    
    public:
        Triangle(Point a, Point b, Point c)
            : p1 {a}, p2 {b}, p3 {c}
        {
        }

        std::ostream& print(std::ostream& out) override
        {
            out << "Triangle(";
            out << p1 << ", " << p2 << ", " << p3;
            out << ")";
            out << std::endl;
            return out;
        }
};

int getLargestRadius(std::vector<Shape*> v)
{
    std::vector<int> maxs {};
    int true_max {};

    for (Shape* s: v)
    {
        auto is_circle = dynamic_cast<Circle*>(s);
        if (is_circle)
        {
            maxs.push_back(is_circle->getRadius());
        }

    }

    auto maxsLength = maxs.size();
    for (int i = 0; i < maxsLength; i++)
    {
        for (int j = 0; j < maxsLength; j++)
        {
            if (i != j)
            {
                if (maxs[i] > maxs[j])
                {
                    true_max = maxs[i];
                }
            }
        }
    }

    return true_max;
}

int main()
{
	std::vector<Shape*> v{
	  new Circle{Point{ 1, 2 }, 7},
	  new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
	  new Circle{Point{ 7, 8 }, 3}
	};

	// print each shape in vector v on its own line here
    for (Shape* s: v)
    {
        std::cout << *s;
    }

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	// delete each element in the vector here
    for (Shape* s: v)
    {
        delete s; // this is okay since a ptr to a base CAN be deleted (safely) if the destructor is vrtual
    }

	return 0;
}