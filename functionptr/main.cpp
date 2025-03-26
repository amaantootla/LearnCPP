#include <functional>
#include <iostream>
#include <optional>

using ArithmeticFunction = std::function<int(int, int)>;

int blob()
{
    return 9;
}

int glob()
{
    return 8;
}

void say(int (*fptr)() = blob)
{
    if (!fptr)
        return;

    // we can pass another function to us
    std::cout << fptr() << '\n';
}

void getValues(int &x, int &y)
{
    std::cout << "Enter two numbers: ";
    std::cin >> x >> y;
}

void getValues(char &c)
{
    std::cout << "Enter +, -, *, /: ";
    std::cin >> c;
}

int add(int x, int y)
{
    return x + y;
}
int subtract(int x, int y)
{
    return x - y;
}
int multiply(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    return static_cast<int>(x / y);
}

std::optional<ArithmeticFunction> getArithmeticFunction(char c)
{
    switch (c)
    {
    case '+':
        return add;
        break;
    case '-':
        return subtract;
        break;
    case '*':
        return multiply;
        break;
    case '/':
        return divide;
        break;
    default:
        return {};
        break;
    }
}

int sumEachDigit(int n)
{
    if (n <= 0)
    {
        return 0;
    }

    int rightMost = n % 10;
    int rest = n / 10;
    return rightMost + sumEachDigit(rest);
}

int main(int argc, char *argv[])
{
    int (*fptr)(){nullptr}; // pointer to a function that returns an int and takes in no arguments
    fptr = blob;            // blob returns an int, and takes in no arguments (don't NEED to use &blob)

    if (fptr)
    {                                //  null check
        std::cout << fptr() << '\n'; // oh hey, we can call the function
    }

    // pass a function to another function
    say(fptr);
    say(); // no worries that function is already the default

    auto dptr{say};
    dptr(glob); // well the deafult argument does not work here, we need to manually supply that other function

    int x{};
    int y{};
    char c{};
    getValues(x, y);
    getValues(c);
    std::optional<ArithmeticFunction> action = getArithmeticFunction(c);

    if (!action) // we only return a ArithmeticFunction if the operator entered was valid
    {
        std::cout << "Invalid inputs." << '\n';
    }
    else
    {
        std::cout << x << " " << c << " " << y << " = " << action.value()(x, y) << '\n';
    }

    std::cout << "Enter an integer: ";
    std::cin >> x;
    std::cout << "Sum of each of its digits is: " << sumEachDigit(x) << '\n';

    // the heap is also called the free store
    // heap access is slower but larger
    // stack access is faster but smaller (since no pointer deref)

    for (int i{0}; i < argc; i++)
    { // argc is argument counter, even with just argv[0] it counts as argc 1
        std::cout << argv[i] << std::endl;
    }

    // lambda's for functions that need a function pointer
    [[maybe_unused]] auto supressEroor = [/* capture clause */](/* parameters */) {
        std::cout << "i am an anon lambda\n";
    };

    // can even store a function in a variable???
    auto lambda = [](int n) -> void { std::cout << n << '\n'; };

    lambda(10);

    // can use auto for parameters in a lambda, that will generate another lambda
    // per every type, beware static variable's are only shared among the same type
    // like parameter int vs std::string_view calls

    // all lambda instances (if using auto) must always return the same type
    // just go ahead and add the little extra syntac -> type at the end
}
