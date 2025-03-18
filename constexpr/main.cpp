#include <iostream>
#include <string>

constexpr int hi()
{ // must resovle at compile time
    return 5;
}

void viewString(std::string_view s)
{
    std::cout << s << '\n';
}

int main()
{
    // (runtime vs compile time) expression
    int a{};
    std::cin >> a;

    int b{a + 1}; // this depends on runtime information

    const int c{4}; // always at compile time

    constexpr int d{5 + hi()}; // must happen at compile time, function must be constexpr as well

    std::cout << a << b << c << d << '\n';

    std::string s{"hello"};
    std::string_view sv =
        s; // inexepsnive viewer of the string (kinda like pass by ref), any change to s will invalidate sv
    viewString(sv);

    for (int i{0}; i < 10; i++)
    {
        std::cout << "fuck off\n";
    }
}
