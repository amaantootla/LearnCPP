#include <array>
#include <iostream>

struct Item {
int gold;
std::string_view name;
};

template <typename T, std::size_t N>
void arrHelper(const std::array<T, N> &arr){
    // can take any length / type
    std::cout << std::get<0>(arr) << std::endl; // compile-time check of index, template parameters must be constexpr
    return;
}

int main()
{
    // cannot pass a non-compile time value for size, such as user input
    // whole point of it being constexpr
    [[maybe_unused]] constexpr std::array<int, 3> arr{1, 2, 3};

    [[maybe_unused]] std::array<double, 365> temperatures{}; // all values will be zero'd out
    constexpr std::array h{'h', 'e', 'l', 'l', 'o'};  // auto type and length from init list

    arrHelper<char, h.size()>(h); // both
    arrHelper<char>(h); // just type
    arrHelper(h); // neither

    // std::array is not moveable

    constexpr std::array<Item, 4> items {
        { // each in here are of type Item, without specifically saying the type e.g. Item{0, ""}
            {5, "sword"},
            {3, "dagger"},
            {3, "club"},
            {7, "spear"},
        }
    };

    for (const auto& item: items){
        std::cout << "A " << item.name << " costs " << item.gold << " gold." << std::endl;
    }
}
