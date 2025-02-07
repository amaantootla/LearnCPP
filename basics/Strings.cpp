#include <string>
#include <string_view>
#include <iostream>

int main() {
    std::string name { "Eman" };
    std::cout << name;

    // This will only get up to the first whitespace character
    std::cin >> name;
    std::cout << name;

    // the following is used to ignore leading whitespace
    // similar to the C getline() function
    // the std::ws part is to make sure any '\n' in the buffer does not
    // count as input from the user
    // std::cin >> std::ws 

    std::getline(std::cin >> std::ws, name);

    // .length() member function, similar to a python method
    std::cout << name.length();

    // use std::string_view to pass a read only version of a string
    // mostly for performance reasons?
}