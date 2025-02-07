#include <iostream>
#include <string>

using namespace std;

void passByValue(int x)
{
    x++;
}

void passByReference(int &x)
{
    x++;
}

int main()
{
    int x {10};
    int &y {x};

    cout << x << y << '\n';

    // notice how the value remains the same
    int k = 10;
    passByValue(k);
    cout << k << '\n';

    // value changes as it REFRENCES the variable in question
    passByReference(k);
    cout << k << '\n';
}

// y is just another way to say x

// cannot change the reference to another varibale
// i.e. y = k will NOT make y a reference to k

// cannot switch types
// int k {10};
// float &p {k};
// WRONG