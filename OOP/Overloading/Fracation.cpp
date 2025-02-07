#include <iostream>

class Fraction
{
    private:
        int m_numerator {};
        int m_denominator {};
    
    public:
        Fraction(int numerator, int denominator)
            : m_numerator {numerator}, m_denominator {denominator}
        {
        }

        void print()
        {
            std::cout << m_numerator << '/' << m_denominator << std::endl;
        }

        // MUST pass by const Fraction refrence
        // in order to work with rvalues
        friend Fraction operator*(const Fraction& frac1, const Fraction& frac2);
        friend Fraction operator*(const Fraction& frac, int value);
        friend Fraction operator*(int value, const Fraction& frac);
};

Fraction operator*(const Fraction& frac1, const Fraction& frac2)
{
    int new_num {};
    int new_den {};

    new_num = frac1.m_numerator * frac2.m_numerator;
    new_den = frac1.m_denominator * frac2.m_denominator;

    return Fraction(new_num, new_den);
}

Fraction operator*(const Fraction& frac, int value)
{
    int new_num {};

    new_num = frac.m_numerator * value;

    return Fraction(new_num, frac.m_denominator);
}

Fraction operator*(int value, const Fraction& frac)
{
    return frac * value;
}

int main()
{
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

    return 0;
}