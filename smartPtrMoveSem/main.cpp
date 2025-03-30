#include <cstdlib>
#include <iostream>

void lvalue(int &x)
{
    std::cout << "lvalue call: " << x << std::endl;
}

void rvalue(int &&x)
{
    std::cout << "rvalue call: " << x << std::endl;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    // use move semantics
    // hop over resource ownership from one smart pointer to another

    int a{10};
    int &b{a};
    [[maybe_unused]] int &&x{10838}; // r-value reference

    lvalue(b);
    rvalue(13928); // no x, an r-value reference would not count, as that is actually a lvalue, only the fr literal is a
                   // r-value

    return EXIT_SUCCESS;
}
