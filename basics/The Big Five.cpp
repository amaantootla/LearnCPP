#include <iostream>

class Value
{
private:
    int* v = nullptr;

public:

    // Constructor
    Value(int v)
    {
        this->v = new int(v);
    }

    // Destructor
    ~Value()
    {
        delete v;
    }

    // Copy Constructor
    // x (us) = y (rhs)
    // x is a NEW object
    // it does NOT exist prior
    // the "=" operator will handle
    // if x already exists
    Value (const Value& rhs)
    {
        this->v = new int(*rhs.v);
    }

    // Move Constructor
    // we basically just steal
    // the rhs objects pointer
    // this is like a shallow copy
    // invoked when std::move has been used on this object
    Value (Value && rhs)
        : v {rhs.v}
    {
        rhs.v = nullptr;
    }

    // Copy assignment operator
    // give us the value of the rhs object
    // we already exist :) this is NOT
    // a constructor
    Value& operator= (const Value& rhs)
    {
        // bogus case
        if (this == &rhs)
            return *this;
        
        // our v takes the value of
        // the rhs v
        *v = *rhs.v;
    }

    // Move assignment operator
    // again we already exist
    // again used when this object has been std::move'd (rvalue-ified)
    Value& operator= (Value && rhs)
    {
        std::swap(v, rhs.v);
        return *this;
    }

    int getV() const { return *v ;}
    void setV(int v) { *(this->v) = v ;}
};

int main()
{
    Value num { 10 };
    std::cout << num.getV() << ' ';
    num.setV(15);
    std::cout << num.getV() << ' ';

    std::cout << std::endl;
}

// rhs means right hand side
// x = y;
// y is on the right hand side

// A shallow copy of class with pointers will copy the addresses of the pointers
// this is bad, any change to the original class (e.g. via the setV() method)
// will affect the copies as well

// A deep copy is when the value of the pointers from the class being copied
// are copied into our own new pointers

// && makes a lvalue into an rvalue
// Value&& just means the function takes in an rvalue
// such as a temp object or an lvalue explicity converted
// to an rvalue via static_cast<> or std::move or invoked
// via std::swap