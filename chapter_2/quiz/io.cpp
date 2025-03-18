#include "io.h"
#include <iostream>

int readNumber()
{
    int n {};
    std::cout << "Enter a integer: ";
    std::cin >> n;
    return n;
}

void writeAnswer(int num)
{
    std::cout << "The answer is " << num << '\n';
    return;
}

