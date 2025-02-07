#include <iostream>
#include <string>

void passByValue(int x)
{
    x++;
}

void passByAddress(int *x)
{
    // x is simply a MEMORY ADDRESS
    *x = *x + 1;
}

int main()
{
    int x = 10; // normal variable
    int &y = x; // reference to a variable

    int *ptr = &x; // pointer to the address OF a variable
    std::cout << *ptr << '\n'; // * in this context to DEREFERENCE the address

    // in C it's NULL
    int *ptr2 = nullptr;

    // before: 10
    // after: 10
    passByValue(x);
    std::cout << x << '\n';

    // before: 10
    // after: 11
    passByAddress(&x);
    std::cout << x << '\n';
    return 0;
}

// &x = address

// ptr = address
// *ptr = value at that address

// you can pass a pointer by reference (to change the value of the pointer)