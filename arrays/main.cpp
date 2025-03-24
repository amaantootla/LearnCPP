#include <array>
#include <functional> // for ref wrapper
#include <iostream>

template <typename T, size_t R, size_t C>
using Array2d = std::array<std::array<T, C>, R>; // yeah this sucks

struct Item
{
    int gold;
    std::string_view name;
};

template <typename T, std::size_t N> void arrHelper(const std::array<T, N> &arr)
{
    // can take any length / type
    std::cout << std::get<0>(arr) << std::endl; // compile-time check of index, template parameters must be constexpr
    return;
}

void nowPtr(int *ptr, size_t size)
{
    // oh goodie, when we pass an array, it decays into an array
    std::cout << sizeof(ptr) << std::endl;
    size_t total{0};

    // size info is lost, GULP
    for (size_t i{0}; i < size; i++)
    {
        total += sizeof(*ptr);            // the element currently being pointed to
        std::cout << ptr[i] << std::endl; // [] is shorthand for deref + offset at i times
    }
    std::cout << total << std::endl;
}

void print(const char *begin, const char *end)
{
    size_t i{0};
    while (begin + i != end)
    {
        std::cout << *(begin + i) << std::endl;
        i += 1;
    }
}

void printReverse(const char *begin, const char *end)
{
    size_t i{1}; // since we start at one past the end
    while (end - i != begin - 1) // and we are okay with the value at begin, since it is inclusive and valid
    {
        std::cout << *(end - i) << std::endl;
        i += 1;
    }
}

int main()
{
    // cannot pass a non-compile time value for size, such as user input
    // whole point of it being constexpr
    [[maybe_unused]] constexpr std::array<int, 3> arr{1, 2, 3};

    [[maybe_unused]] std::array<double, 365> temperatures{}; // all values will be zero'd out
    constexpr std::array h{'h', 'e', 'l', 'l', 'o'};         // auto type and length from init list

    arrHelper<char, h.size()>(h); // both
    arrHelper<char>(h);           // just type
    arrHelper(h);                 // neither

    // std::array is not moveable

    constexpr std::array<Item, 4> items{{
        // each in here are of type Item, without specifically saying the type e.g. Item{0, ""}
        {5, "sword"},
        {3, "dagger"},
        {3, "club"},
        {7, "spear"},
    }};

    for (const auto &item : items)
    {
        std::cout << "A " << item.name << " costs " << item.gold << " gold." << std::endl;
    }

    // refs cant be reseated and are not objects
    int x{1};
    int y{1};
    int z{1};

    std::array<std::reference_wrapper<int>, 3> wtf{x, y, z};
    wtf[0].get() = 10; // each array element is a reference_wrapper, use .get() to get the actual data member
    // remember using = on a reference_wrapper object will reseat the ref, but you can only reseat to a lvalue duh

    auto ptref{std::reference_wrapper<int>(x)}; // ptref is a ref to x, can make it point to anything though
    std::cout << ptref.get() << std::endl;
    ptref = y; // this makes it point at y now
    std::cout << ptref.get() << std::endl;

    [[maybe_unused]] int c[10]{}; // c-style array with 10 ints, contigious in memory, each offset by sizeof(int)
    [[maybe_unused]] int first[5]{1, 2, 3, 4, 5}; // first 5 numbers
    [[maybe_unused]] int yeah[]{1, 2, 3};         // yes you can omit the length
    std::cout << sizeof(c) << std::endl;
    std::cout << std::size(c) << std::endl; // the length

    [[maybe_unused]] constexpr int a[3]{};

    // arrays cannot point to a new set of data

    nowPtr(c, std::size(c)); // prints 8, i thought we were size 40, well thats the size of the pointer, it points to
                             // the first element

    // math w pointers, address of next object, so in a array each 1...n - 1 will be size(T) apart, watch
    const int *arrPtr{c};
    for (size_t i{0}; i < 10; i++)
    {
        std::cout << arrPtr + i << std::endl; // and of course it is relative to where arrPtr was pointing to
    }

    const int *begin{c};
    const int *end{c + std::size(c)}; // points to one past the end

    for (; begin != end; begin++)
    { // traverse whole array, incremenet to next object each time
        const int tmp = *begin;
        std::cout << tmp << std::endl;
    }

    const char hello[]{"Hello, world!"};
    print(hello, hello + std::size(hello));
    printReverse(hello, hello + std::size(hello));

    Array2d<int, 2, 5> arrTwo {{
        {1,2,3,4,5},
        {5,4,3,2,1},
    }}; // 5 cols, 2 rows, lord.

    for (auto& r: arrTwo) {
        for (auto& c: r){
            std::cout << c;
        }
    }

    
}
