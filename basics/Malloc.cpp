#include <iostream>
#include <string>

int main()
{
    int* x {new int}; // POINTER to a block of memory that is a int
    *x = 10; // DEREFERENCE the POINTER to set the VALUE of the block to 10

    // clean up
    delete x; // cleans up the memory POINTED to by x
    x = nullptr; // clean up the pointer

    int* y {new (std::nothrow) int}; // if new fails, return a nullptr
    if (y == nullptr)
    {
        std::cout << "wtf" << '\n';
    }
    *y = 5;
}

// C has malloc()