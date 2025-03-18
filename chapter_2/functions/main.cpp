#include <cstdlib> // for EXIT_SUCCESS and EXIT_FAILURE
#include <iostream>

// circular dependencies -- forward declarations -- prototype
int input();
void nothing();
int maxOfTwo(int x, int y);

int main()
{
    int x{input()};
    std::cout << x << '\n';

    nothing();

    int y {500};
    std::cout << maxOfTwo(5, 98) << '\n';
    std::cout << x << y << '\n'; // function dependent scope

    return EXIT_SUCCESS;
}

int input()
{
    int n{5};

    // std::cin >> n;

    return n;

    // no nesting of functions UNLIKE python
}

void nothing()
{
    std::cout << "i do nothing\n";
}

int maxOfTwo(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
