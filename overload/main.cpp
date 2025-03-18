#include <cstdlib>
#include <ios>
#include <iostream>
#include <string>

// same name, different number/type of argument(s) or being const/non-const, NOT by return type

void test(std::string_view s)
{
    std::cout << "printing a cpp string: " << s << '\n';
}

// default args
void test(const char *s = "what the")
{
    std::cout << "printing a c-ctyle string: " << s << '\n';
}

template <typename T> T generic(T n)
{
    n = n + n; // as long as the type has operator+ defined for it, this will work, for ex, int,char,double,std::string
    return n;
}

template <> const char *generic(const char *) = delete; // this specific instanace does not work

template <typename T, typename U> bool twoGeneric(T a, U b)
{
    // as long as both operator== between the two is defined this will work
    // works between std::string and char* string
    return a == b;
}

int main()
{
    std::string s = "HELLO";
    std::string_view sv = s;
    const char *cs = "BYE";
    const char *bs = "HELLO";

    test(sv);
    test(cs);
    test();

    std::cout << generic<int>(10) << '\n';
    std::cout << generic<double>(9.92748938456585958) << '\n';
    std::cout << generic<std::string>(s) << '\n';
    
    std::cout << std::boolalpha << twoGeneric<std::string, const char *>(s, cs) << '\n';
    std::cout << std::boolalpha << twoGeneric<std::string, const char *>(s, bs) << '\n';

    return EXIT_SUCCESS;
}
