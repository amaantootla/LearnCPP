#include <iostream>

int main()
{
    // compact, but
    int a, b;

    // best practice
    int x; // (default-initialization)
    int y;

    // must assign inital value
    a = 0;
    b = 1;
    x = 2;
    y = 3;

    // must use variables
    y = x;
    x = y;
    b = a;
    a = b;

    // best practice (direct-list-initialization)
    int z{5};
    int c{};                          // empty, aka 0 (value-initialization)
    std::cout << z << c << std::endl; // insertion operator

    // define variables you will use in the future
    [[maybe_unused]] int fuckOff;

    // extraction operator
    std::cout << "Enter three numbers: ";
    int first{};
    int second{};
    int third{};
    std::cin >> first >> second >> third;
    std::cout << "You entered " << first << ", " << second << ", " << "and " << third << ".\n";

    // side effect operators like >> and = return the LHS value
    std::cout << (x = 1) << "\n"; // x is now 1, it will return x

    return 0;
}
