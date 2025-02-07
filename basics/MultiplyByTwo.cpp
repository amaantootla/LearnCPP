#include <iostream>

int main() {
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    std::cout << "Double that number is: " << x * 2; 

    // Extra Credit
    std::cout << "Tripe that number is: " << x * 3;
}