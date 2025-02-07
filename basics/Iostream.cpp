#include <iostream>

int main()
{
    // C++ uses insertion operators, "<<"
    std::cout << "Wow wonky syntax af!";
    
    int x { 10 };
    std::cout << x;

    // Concatenate
    std::cout << "One" << " Two";

    // std::endl = newline + flush the buffer
    // just use \n, C-style
    std::cout << "Hey!" << std::endl;
    std::cout << "More stuff" << std::endl;
    std::cout << "Yk you could just\n";

    // cin uses a extraction operator
    std::cout << "Number: ";
    int p {};
    std::cin >> p; // assign x the value of stdin
    std::cout << "Entered: " << p;

    int first{};
    int sec{};
    std::cout << "Two numbers delimited via a space: ";
    std::cin >> first >> sec;
    std::cout << first << sec;
}