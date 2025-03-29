#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

class Fraction
{
  private:
    int m_numerator{};
    int m_denominator{};

  public:
    explicit Fraction(int numerator = 0, int denominator = 1) : m_numerator(numerator), m_denominator(denominator)
    {
        reduce();
    }

    void print() const;
    void reduce();

    friend Fraction operator*(const Fraction &lhs, const Fraction &rhs);
    friend Fraction operator*(const Fraction &lhs, int rhs);
    friend Fraction operator*(int lhs, const Fraction &rhs);

    friend std::ostream &operator<<(std::ostream &out, const Fraction &rhs);
    friend std::istream &operator>>(std::istream &in, Fraction &rhs);

    friend bool operator==(const Fraction &lhs, const Fraction &rhs);
    friend bool operator!=(const Fraction &lhs, const Fraction &rhs);
    friend bool operator<(const Fraction &lhs, const Fraction &rhs);
    friend bool operator>(const Fraction &lhs, const Fraction &rhs);
    friend bool operator<=(const Fraction &lhs, const Fraction &rhs);
    friend bool operator>=(const Fraction &lhs, const Fraction &rhs);
};

void Fraction::print() const
{
    std::cout << m_numerator << "/" << m_denominator << "\n";
}

void Fraction::reduce()
{
    int gcd{std::gcd(m_numerator, m_denominator)};
    m_numerator /= gcd;
    m_denominator /= gcd;
}

Fraction operator*(const Fraction &lhs, const Fraction &rhs)
{
    return Fraction{lhs.m_numerator * rhs.m_numerator, lhs.m_denominator * rhs.m_denominator};
}

Fraction operator*(const Fraction &lhs, int rhs)
{
    return Fraction{lhs.m_numerator * rhs, lhs.m_denominator};
}

Fraction operator*(int lhs, const Fraction &rhs)
{
    return rhs * lhs;
}

std::ostream &operator<<(std::ostream &out, const Fraction &rhs)
{
    out << rhs.m_numerator << "/" << rhs.m_denominator;
    return out;
}

std::istream &operator>>(std::istream &in, Fraction &rhs)
{
    int tmp_numerator{};
    char divisor{};
    int tmp_denominator{};

    in >> tmp_numerator >> divisor >> tmp_denominator;
    if (tmp_denominator == 0)
    {
        in.setstate(std::ios_base::failbit);
    }

    if (in)
    {
        /*
        rhs.m_numerator = tmp_numerator;
        rhs.m_denominator = tmp_denominator;
        */

        // convention says the rhs of operator>> be overwritten with a new object
        rhs = Fraction{tmp_numerator, tmp_denominator};
    }

    return in;
}

bool operator==(const Fraction &lhs, const Fraction &rhs)
{
    return (lhs.m_numerator == rhs.m_numerator && lhs.m_denominator == rhs.m_denominator);
}

bool operator!=(const Fraction &lhs, const Fraction &rhs)
{
    return !(lhs == rhs); // uses operator==
}

bool operator<(const Fraction &lhs, const Fraction &rhs)
{
    return (static_cast<double>(lhs.m_numerator / lhs.m_denominator) <
            static_cast<double>(rhs.m_numerator / rhs.m_denominator));
}

bool operator>(const Fraction &lhs, const Fraction &rhs)
{
    return (rhs < lhs); // uses operator<
}

bool operator<=(const Fraction &lhs, const Fraction &rhs)
{
    return !(lhs > rhs); // if not greater than, it must be less than or equal to
}

bool operator>=(const Fraction &lhs, const Fraction &rhs)
{
    return !(lhs < rhs); // if not less than, it must be greater than or equal to
}

class Point
{
  private:
    double m_x{};
    double m_y{};
    double m_z{};

  public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0) : m_x{x}, m_y{y}, m_z{z}
    {
    }

    // Convert a Point into its negative equivalent
    Point operator-() const;

    // Return true if the point is set at the origin
    bool operator!() const;

    Point operator+() const;

    double getX() const
    {
        return m_x;
    }
    double getY() const
    {
        return m_y;
    }
    double getZ() const
    {
        return m_z;
    }
};

// Convert a Point into its negative equivalent
Point Point::operator-() const
{
    return {-m_x, -m_y, -m_z};
}

// Return true if the point is set at the origin, false otherwise
bool Point::operator!() const
{
    return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0);
}

Point Point::operator+() const
{
    return Point{m_x, m_y, m_z};
}

class Car
{
  private:
    std::string m_make;
    std::string m_model;

  public:
    Car(std::string_view make, std::string_view model) : m_make{make}, m_model{model}
    {
    }

    friend bool operator==(const Car &c1, const Car &c2);
    friend bool operator!=(const Car &c1, const Car &c2);

    friend bool operator<(const Car &lhs, const Car &rhs);
    friend std::ostream &operator<<(std::ostream &out, const Car &rhs);
};

bool operator==(const Car &c1, const Car &c2)
{
    return (c1.m_make == c2.m_make && c1.m_model == c2.m_model);
}

bool operator!=(const Car &c1, const Car &c2)
{
    return (c1.m_make != c2.m_make || c1.m_model != c2.m_model);
}

bool operator<(const Car &lhs, const Car &rhs)
{
    return lhs.m_make < rhs.m_make;
}

std::ostream &operator<<(std::ostream &out, const Car &rhs)
{
    out << "(" << rhs.m_make << ", " << rhs.m_model << ")";
    return out;
}

class MyString
{
  private:
    std::string m_string{};

  public:
    MyString(std::string_view string) : m_string{string}
    {
    }

    friend std::ostream &operator<<(std::ostream &out, const MyString &rhs);
    std::string_view operator()(size_t start, size_t length);
};

std::ostream &operator<<(std::ostream &out, const MyString &rhs)
{
    out << rhs.m_string;
    return out;
}

std::string_view MyString::operator()(size_t start, size_t length)
{
    std::string_view sv{m_string};
    return sv.substr(start, length);
}

class Average
{
  private:
    std::int32_t m_total{};
    size_t m_count{};

  public:
    Average() : m_total{}, m_count{}
    {
    }

    Average(const Average &rhs) = default;
    Average &operator=(const Average &rhs) = default;

    Average &operator+=(std::int32_t rhs);
    friend std::ostream &operator<<(std::ostream &out, const Average &rhs);
};

Average &Average::operator+=(std::int32_t rhs)
{
    m_total += rhs;
    ++m_count;

    return *this;
}

std::ostream &operator<<(std::ostream &out, const Average &rhs)
{
    out << (rhs.m_count == 0 ? 0 : static_cast<double>(rhs.m_total) / rhs.m_count);
    return out;
}

class IntArray
{
  private:
    size_t m_length{};
    int *m_arr{};

  public:
    explicit IntArray(int length)
    {
        assert(length > 0);

        m_length = static_cast<size_t>(length);
        m_arr = new int[m_length];
    }

    ~IntArray()
    {
        delete[] m_arr;
    }

    IntArray(const IntArray &rhs)
    {
        m_length = rhs.m_length;
        m_arr = new int[m_length];

        for (size_t i{0}; i < m_length; ++i)
        {
            m_arr[i] = rhs.m_arr[i];
        }
    }

    IntArray &operator=(const IntArray &rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }

        delete[] m_arr;
        m_arr = nullptr;

        m_length = rhs.m_length;
        m_arr = new int[m_length];

        for (size_t i{0}; i < m_length; ++i)
        {
            m_arr[i] = rhs.m_arr[i];
        }

        return *this;
    }

    int &operator[](int index)
    {
        assert(index >= 0);
        assert(static_cast<size_t>(index) < m_length);

        return m_arr[static_cast<size_t>(index)];
    }

    friend std::ostream &operator<<(std::ostream &out, const IntArray &rhs)
    {
        for (size_t i{0}; i < rhs.m_length; ++i)
        {
            out << rhs.m_arr[i] << " ";
        }

        out << "\n";

        return out;
    }
};

IntArray fillArray()
{
    IntArray a(5);

    a[0] = 5;
    a[1] = 8;
    a[2] = 2;
    a[3] = 3;
    a[4] = 6;

    return a;
}

int main()
{
    /*
    Fraction f1{1, 4};
    f1.print();

    Fraction f2{1, 2};
    f2.print();
    */

    /*
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();
    */

    /*
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{f1 * f2};
    f3.print();

    Fraction f4{f1 * 2};
    f4.print();

    Fraction f5{2 * f2};
    f5.print();

    Fraction f6{Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4}};
    f6.print();

    Fraction f7{0, 6};
    f7.print();
    */

    /*
    Fraction f1{};
    std::cout << "Enter fraction 1: ";
    std::cin >> f1;

    Fraction f2{};
    std::cout << "Enter fraction 2: ";
    std::cin >> f2;

    std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value
    */

    // you only need to define operator== and operator< to have all 6 operator comparsions
    // just by using ! properly in the other defs

    /*
    Fraction f1{3, 2};
    Fraction f2{5, 8};

    std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
    std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
    std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
    std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
    std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
    std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';

    std::vector<Car> cars{{"Toyota", "Corolla"}, {"Honda", "Accord"}, {"Toyota", "Camry"}, {"Honda", "Civic"}};

    std::sort(cars.begin(), cars.end()); // requires an overloaded operator<

    for (const auto &car : cars)
        std::cout << car << '\n'; // requires an overloaded operator<<
    */

    // prefix, inc/dec then return
    // postfix, make copy (to perserve pre inc/dec state), inc/dec, return copy (less efficent, must return by copy
    // since a ref to a local variable is dangling
    // and just like comparsions, postfix should use prefix so --tmp and ++tmp

    // overload operator() to create functors, calling a class as a function basically
    // but can store data along with every instance (bc its a class)

    /*
    MyString s{"Hello, world!"};
    std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters
    */

    // overload a typecast to convert from one type to another type
    // should probably mark it as explcit so we have to use static_cast<T>
    // but prefer a converting constructor instead, so we own our conversions

    // copy constructor for when a new object must be made (copy to)
    // copy assignment operator for when the object already exists (copy to)

    // make sure self-assignment guard via a if(this == &rhs) return *this statement

    // no copy/assignement defined will do shallow copies
    // this is not okay for dynamic resources

    /*
    Average avg{};
    std::cout << avg << '\n';

    avg += 4;
    std::cout << avg << '\n'; // 4 / 1 = 4

    avg += 8;
    std::cout << avg << '\n'; // (4 + 8) / 2 = 6

    avg += 24;
    std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

    avg += -10;
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

    (avg += 6) += 10;         // 2 calls chained together
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

    Average copy{avg};
    std::cout << copy << '\n';
    */

    IntArray a{fillArray()};

    std::cout << a << '\n';

    auto &ref{a}; // we're using this reference to avoid compiler self-assignment errors
    a = ref;

    IntArray b(1);
    b = a;

    a[4] = 7;

    std::cout << b << '\n';

    return 0;
}
