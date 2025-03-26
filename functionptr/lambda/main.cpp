#include <algorithm>
#include <array>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>

double max(const double, const double);
void swap(int&, int&);
int& getLargestElement(int*, int);

struct Season
{
    std::string_view name{};
    double averageTemperature{};
};

struct Student
{
    std::string_view name;
    int points;
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    std::array<Student, 8> arr{{{"Albert", 3},
                                {"Ben", 5},
                                {"Christine", 2},
                                {"Dan", 8},
                                {"Enchilada", 4},
                                {"Francis", 1},
                                {"Greg", 3},
                                {"Hagrid", 5}}};

    auto it = std::max_element(arr.begin(), arr.end(),
                               [](const Student &s1, const Student &s2) { return s1.points < s2.points; });
    std::cout << it->name << " is the best student\n";

    std::array<Season, 4> seasons{{{"Spring", 285.0}, {"Summer", 296.0}, {"Fall", 288.0}, {"Winter", 263.0}}};

    std::sort(seasons.begin(), seasons.end(),
              [](const Season &a, const Season &b) -> bool { return a.averageTemperature < b.averageTemperature; });

    for (const auto &season : seasons)
    {
        std::cout << season.name << '\n';
    }

    // lambdas cannot access outside variables except what is passed in as a parameter
    // or what is captured, and the captured varibales are const, so cannot modify them
    // unless you add the mutable keyword, this isn't a good example of using that lol.
    [[maybe_unused]] auto pointless = [name = it->name]() mutable {
        auto modify = static_cast<std::string>(name);
        modify += " The great";
        std::cout << modify << " from a lambda!\n";
    };
    pointless();
    
    // to change the original varibale use pass by ref so it would be [&it]
    // to pass in all used varibles by copy use [=] or as ref use [&]

    // beware dangling refrneces and rvalues
    // beware that if a copy is captured and the lambda is copied
    // that new lambda will operate on its own captured copies

    return EXIT_SUCCESS;
}
