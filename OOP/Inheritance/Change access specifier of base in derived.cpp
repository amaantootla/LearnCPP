#include <iostream>

class Base
{
    public:
        int very_private_value {};
};

class Derived : public Base
{
    private:
        using Base::very_private_value {};
        // now very_private_value is
        // actually private!
};