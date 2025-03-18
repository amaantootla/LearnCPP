#include "io.h"
#include <iostream>
#include <cstdlib>

int main()
{
    int x {readNumber()};
    int y {readNumber()};
    writeAnswer(x + y);
    return EXIT_SUCCESS;
}
