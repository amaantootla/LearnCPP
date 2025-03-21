#include <iostream>
#include <string>

class IntPair
{
  private:
    int first;
    int second;

  public:
    explicit IntPair(int first = 0,
                     int second = 0) // do not let any call to a {int, int} be converted to a IntPair() object
    {
        this->first = first;
        this->second = second;
    }

    void print() const // we do not modify the class (thus sutiable to call this method on const instances)
    {
        std::cout << "Pair( " << first << " , : " << second << ")" << std::endl;
    }

    void print()
    { // overload on const-ness
        std::cout << "YOU WILL NEVER CHANGE THESE VALUES HAHAHAH " << "Pair( " << first << " , : " << second << ")"
                  << std::endl;
    }

    bool isEqual(const IntPair &rhs) const
    {
        if (first != rhs.first || second != rhs.second)
            return false;
        return true;
    }

    void reset()
    {
        *this = IntPair{}; // little trick
    }
};

class Ball
{
  private:
    std::string m_color;
    double m_radius;

    void print() const
    {
        std::cout << "Ball(" << m_color << ", " << m_radius << ")" << std::endl;
    }

  public:
    explicit Ball(std::string_view color = "black", double radius = 10.0)
    {
        m_color = color;
        m_radius = radius;
        print();
    }

    explicit Ball(double radius) : Ball("black", radius) // delagate to the two parameter constructor
    {
    }
};

template <typename T, typename U, typename V> class Triad
{
  private:
    T m_first;
    U m_second;
    V m_third;

  public:
    explicit Triad(T first = T{}, U second = U{}, V third = V{}) : m_first{first}, m_second{second}, m_third{third}
    {
    }

    const T &first() const
    {
        return m_first;
    }

    const T &second() const
    {
        return m_second;
    }

    const T &third() const
    {
        return m_third;
    }

    void print() const;
};

// talk about bad syntax
template <typename T, typename U, typename V> void Triad<T, U, V>::print() const
{
    std::cout << "[" << m_first << ", " << m_second << ", " << m_third << "]" << std::endl;
}

// needed to make Vector3d befriending moveByVector be okay
class Vector3d;

class Point3d
{
  private:
    double m_x{};
    double m_y{};
    double m_z{};

  public:
    Point3d(double x, double y, double z) : m_x{x}, m_y{y}, m_z{z}
    {
    }

    void print() const
    {
        std::cout << "Point(" << m_x << ", " << m_y << ", " << m_z << ")\n";
    }

    void moveByVector(const Vector3d &v);
};

class Vector3d
{
  private:
    double m_x{};
    double m_y{};
    double m_z{};

    friend void Point3d::moveByVector(const Vector3d &v);

  public:
    Vector3d(double x, double y, double z) : m_x{x}, m_y{y}, m_z{z}
    {
    }

    void print() const
    {
        std::cout << "Vector(" << m_x << ", " << m_y << ", " << m_z << ")\n";
    }
};

void Point3d::moveByVector(const Vector3d &v)
{
    m_x += v.m_x;
    m_y += v.m_y;
    m_z += v.m_z;
}

int main()
{
    IntPair p1{1, 2};
    IntPair p2{3, 4};

    std::cout << "p1: ";
    p1.print();

    std::cout << "p2: ";
    p2.print();

    std::cout << "p1 and p1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
    std::cout << "p1 and p2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");

    Ball def{};
    Ball blue{"blue"};
    Ball twenty{20.0};
    Ball blueTwenty{"blue", 20.0};

    Triad<int, int, int> t1{1, 2, 3};
    t1.print();
    std::cout << '\n';
    std::cout << t1.first() << '\n';

    using namespace std::literals::string_literals;
    const Triad t2{1, 2.3, "Hello"s};
    t2.print();
    std::cout << '\n';

    // access even without the class object
    // and shared across all instances, as all statics are
    // use it for ID'ing a specific class
    // or to just share a large structure in a memory respecting way

    // make a static function to access static variables ONLY

    Point3d p{1.0, 2.0, 3.0};
    Vector3d v{2.0, 2.0, -3.0};

    p.print();
    p.moveByVector(v);
    p.print();

    return 0;
}
