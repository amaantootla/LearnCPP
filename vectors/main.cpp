#include <iostream>
#include <stdlib.h>
#include <vector>

template <typename T> void iWishThisWasPython(const std::vector<T> &v)
{ // yes this is the only way to pass in a non specific type vector -_-
    for (auto n : v)
    {
        std::cout << n;
    }
    std::cout << std::endl;
}

template <typename T> std::vector<T> returnSomeFatVector()
{
    std::vector<T> v(1000000);
    return v;
}

template <typename T> T findMax(const std::vector<T> &v)
{
    if (v.empty())
    {
        return T{};
    }

    T max{v[0]};

    for (std::size_t i{1}; i < v.size(); i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }

    return max;
}

template <typename T> bool isValueInArray(const std::vector<T>& arr, const T& target){
    for (auto& val: arr){
        if (val == target)
            return true;
    }

    return false;
}

int main()
{
    std::vector<int> startingSize(10); // 10 elements, all zero'd
    std::vector<int> oneElement{10};   // one element, value 10

    std::cout << startingSize.size() << std::endl;

    for (auto n : startingSize)
    {
        std::cout << n;
    }
    std::cout << std::endl;

    std::cout << oneElement[0];
    std::cout << std::endl;

    // std::vector<int> threeIntegers(3);
    // int sumTotal{};
    // int productTotal{1};

    // // std::cout << "Enter 3 integers: ";
    // // for (std::size_t i = 0; i < 3; i++)
    // // {
    // //     std::cin >> threeIntegers[i];
    // // }
    // // for (auto n : threeIntegers)
    // // {
    // //     sumTotal += n;
    // //     productTotal *= n;
    // // }

    // // std::cout << "The sum is: " << sumTotal << std::endl << "The product is: " << productTotal << std::endl;

    iWishThisWasPython<int>(startingSize);

    std::vector<int> anotherTen{};
    anotherTen = startingSize; // copied
    for (auto &n : anotherTen)
    { // auto& to get the ref that each element is
        n = 9;
    }
    for (auto n : anotherTen) // indep from vector<int> startingSize
    {
        std::cout << n;
    }
    std::cout << std::endl;

    // std::vector (and std::string) support move semantics, returning these types by value is okay
    [[maybe_unused]] std::vector<std::string> moveToMe = returnSomeFatVector<std::string>();

    // passing into a function should still use a (const) ref
    // it makes zero sense to use move semantics since now the parameter has the value
    // you passed in, but the original value is empty?? plus if it is a lvalue moving is not possible anyway

    std::vector data1{84, 92, 76, 81, 56};
    std::cout << findMax(data1) << '\n';

    std::vector data2{-13.0, -26.7, -105.5, -14.8};
    std::cout << findMax(data2) << '\n';

    std::vector<int> data3{};
    std::cout << findMax(data3) << '\n';

    std::vector<std::string_view> names{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
    std::string input{};
    [[maybe_unused]] bool found = false;

    std::cout << "Enter a name: ";
    std::cin >> input;

    for (const auto &name : names)
    {
        if (name == input)
        {
            found = true;
        }
    }

    if (isValueInArray<std::string_view>(names, input)) // converts input to string_view as well
    {
        std::cout << input << " was found." << std::endl;
    }
    else
    {
        std::cout << input << " was not found." << std::endl;
    }
    
}
