#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector stack = {};
    stack.push_back(10); // push int 10 onto the stack
    stack.pop_back(); // pops off the latest item from the stack (i.e. last element)
    stack.reserve(10) // set the capacity to 10 at least
                      // to minimize resize operation costs
}

// length = how many elements are being used
// capacity = how many elements CAN be used