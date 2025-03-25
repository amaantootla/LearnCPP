#include <cstdlib>
#include <iostream>
#include <string>

int main()
{
    //[[maybe_unused]] long arr[999999999]; // stack frame size (8000000032) exceeds limit (4294967295)

    int *ptr{
        new (std::nothrow) int{5}}; // gives you one sizeof(int) memory worth, and returns a pointer to that address

    // ptr will be nullptr if new failed
    if (!ptr)
        return EXIT_FAILURE;

    std::cout << *ptr << std::endl;
    *ptr = 1;
    std::cout << *ptr << std::endl;

    // send back to the OS
    delete ptr; // do not deref ptr now, UB
    ptr = nullptr;

    // anytime we lose the address of a dynamically allocated memory
    // either by the pointer going out of scope
    // or it being assigned to another value with saving the old value
    // or allocating new again to the same pointer
    // these only apply if this is done BEFORE deleting the pointer
    // if you do delete, then there is no worries

    size_t sz{1};
    // std::cin >> sz;

    std::string *mArr{new (std::nothrow) std::string[sz]}; // an array of size sz
    if (!mArr)
    {
        std::cout << "holy that is too much memory";
        return EXIT_FAILURE;
    }

    for (auto begin{mArr}; begin != mArr + sz; begin++)
    {
        if (*begin == "")
        {
            std::cout << "EMPTY VAL ";
        }
        else
        {
            std::cout << *begin;
        }
    }
    std::cout << '\n';

    delete[] mArr;

    size_t n;
    std::cout << "How many names would you like to enter? ";
    std::cin >> n;
    std::string *names{new (std::nothrow) std::string[n]};

    if (!names)
        return EXIT_FAILURE;

    for (size_t i{0}; i < n; i++)
    {
        std::cout << "Enter name #" << i + 1 << ": ";
        std::cin >> names[i];
    }

    std::cout << "\nHere is your sorted list:\n";
    std::sort(names, names + n);
    for (size_t i{0}; i < n; i++)
    {
        std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';
    }

    delete[] names;

    // use destructors for any class that manages dynamic memory
    
    [[maybe_unused]] int **arr2d {new int*[10]}; // each element is a pointer to an integer itself
    for (size_t i {0}; i < 10; i++){
        // need to manually allocate per array entry
        arr2d[i] = new int[10]; // each "row" need not have the same amount of columns (e.g. 10)
    }

    // dealloc is a manual process as well
    for (size_t i {0}; i < 10; i++){
        delete[] arr2d[i]; // each column / entry in the main array
    }
    delete[] arr2d; // the main array itself

    // willing to bet lists in python, which are heterogeneous, use void pointers
    // simply an array of void pointers, and maybe at runtime determine what type
    // it is? and add that to some aux store somewhere?

    return EXIT_SUCCESS;
}
