#include <iostream>

class Shape
{
  protected:
    virtual std::ostream& print(std::ostream& out) = 0;
    friend std::ostream& operator<<(std::ostream& out, Shape& s)
    {
        return s.print(out);
    };
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

int main()
{
    Circle c{ Point{ 1, 2 }, 7 };
    std::cout << c << '\n';

    Triangle t{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }};
    std::cout << t << '\n';

    return 0;
}