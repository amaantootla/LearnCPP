#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

bool lessThanThreeGreaterThanOne(const int n)
{
    return n < 3 && n > 1;
}

int main()
{
    // STL has iterators built in
    std::array arr{1, 2, 3};
    auto begin{arr.begin()};
    auto end{arr.end()};

    for (; begin != end; begin++)
    {
        std::cout << *begin;
    }
    std::cout << '\n';

    std::vector vec{1, 2, 2, 2, 2, 3};
    for (auto it{vec.begin()}; it != vec.end(); it++)
    {
        if (*it == 1)
        {
            // we erase the current element, erase() returns a new valid iterator, make sure to reassign
            it = vec.erase(it);
        }
    }

    // some handy shortcuts
    auto found{
        std::find_if(vec.begin(), vec.end(), lessThanThreeGreaterThanOne) // runs that helper on each element
    };

    if (found == vec.end())
    {
        std::cout << "No matching values.\n";
    }
    else
    {
        std::cout << "Found matching value: " << *found << "\n";
    }

    std::cout << "Number of numbers greater than 1 and less than 3: "
              << std::count_if(vec.begin(), vec.end(), lessThanThreeGreaterThanOne) << '\n';

    return EXIT_SUCCESS;
}
