#include "IntVector.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, IntVector& iv)
{
    auto ivLength = iv.size();
    for (int i = 0; i < ivLength; i++)
    {
        out << iv.at(i);
        if (i != ivLength - 1)
        {
            out << ' ';
        }
    }
    out << std::endl;

    return out;
}

int main()
{
    IntVector nums {};

    nums.push_back(1);
    nums.push_back(2);

    nums.insert(3, 1);

    std::cout << nums;
}
