#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    vector v = { 5, 6, 7, 8}; // no type need be specified
    for (int i : v)
    {
        cout << i;
    }
    cout << '\n';

    // .resize() does exactly what you think it does
    v.resize(10);
    for (int i = 4; i < 10; i++)
    {
        v.at(i) = i;
    }

    for (int i: v)
    {
        cout << i;
    }
    cout << '\n';

    // a vector of size 10, with all elements set to 0
    // but then the type MUST be stated
    vector<int> v2(10);
}

// vector is a dynamic array
// [] or .at()
// .size() (dynamic array via pointers do not do this)
// .begin(), .end() for the start-end of the vector