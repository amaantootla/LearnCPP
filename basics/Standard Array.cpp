#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int, 5> my_array;
    
    // bounds checking via at()
    my_array.at(0) = 10;
    
    // built in size checking
    cout << my_array.size() << '\n';

    // size() returns size_t, NOT int
    array<int, 3> test;
    for (size_t i = 0; i < test.size(); i++)
    {
        test[i] = i + 3;
        cout << i + 3;
    }
    cout << '\n';

}