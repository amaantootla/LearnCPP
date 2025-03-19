#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

void pass(int x, int &ref) // second argument cannot be a ravlue, like a literal, makes sense if we need to change, but
                           // not if we just want a non-expensive view
{
    std::cout << x << ref << '\n'
              << &x << &ref << '\n'; // notice x is a new object (pass by value), whereas ref is the original object
    --ref;                           // pass by reference
}

void rvaluePass(const int &ref)
{
    std::cout << ref << '\n'; // we lose the ability to change ref tho ...
}

void watch(const std::string *sptr)
{
    std::cout << *sptr << std::endl;
}

void stillCopy([[maybe_unused]] int *ptr)
{
    ptr = nullptr; // this is a COPY of a pointer, we are not dereferencing it, we are changing WHO we point to
}

void notCopy(int *&ptr, int *other)
{
    ptr = other; // now we change WHO the original pointer points to, do not do this bruh
}

void sort2(int &x, int &y)
{
    if (x > y)
    {
        std::swap(x, y);
    }
}

int main()
{
    const int x{5}; // rvalue, literals, expressions
    int y{3};       // rvalue, both 5 and 3 are tmp, they are not identifiable

    int a{x};     // non-modifiable lvalue (x is const)
    int b{y};     // modifiable lvalue (y is non-const)
    int c{x + 1}; // rvalue, x+1 is not identifiable

    c = a;     // a is a lvalue, it will implicitly turn into a rvalue
    b = c + b; // both c and b are lvalues, operator+ expects rvalues? both c and b turn into rvalues

    int &e = a;       // declare a reference to a object via a T&
    const int &f = x; // yes the reference must match the const-ness as well
    const int &g = b; // hey b is not const? well the ref can be MORE const, and only the ref is treated as const

    // a non-const lvalue reference cannot bind to a rvalue
    // we can never make a reference like e or f point to any other object
    // much like pointers, references can be left dangling, beware

    e = c; // now a will have the vlaue of c

    const int &theFuck{10}; // const lvalue reference to rvalue, valid. when expecting rvalues, always prefer const T&
    const long &notSame{a}; // const lvalue reference with different type, this binds to a TMP object NOT a
    std::cout << a << --a << notSame << '\n'; // notice notSame does not get decremented in value, BEWARE

    std::cout << x << y << a << b << c << e << f << g << theFuck << '\n';

    std::cout << a << &a << '\n';
    pass(a, a);
    std::cout << a << &a << '\n';

    rvaluePass(5);

    char first{'h'};
    char second{'i'};
    std::cout << first << &first << *(&first) << '\n';
    char *ptr{&first};
    std::cout << *ptr << '\n';
    ptr = &second; // yes it can point to something else
    std::cout << *ptr << '\n';
    *ptr = 'e'; // yes it can change the value of what it is pointing at
    std::cout << *ptr << '\n';

    int *nptr{}; // easy way to null, can set to nullptr later

    if (nptr)
    {
        // we are valid
        std::cout << *nptr << '\n';
    }
    else
    {
        // we are invalid
        ;
        // return EXIT_FAILURE;
    }

    // a const pointer cannot change the value of what it is pointing to
    // but it CAN change WHO it is pointing to
    const int *cptr = &x;
    std::cout << *cptr << '\n';
    int bruh = 0;
    cptr = &bruh; // despite bruh not being const
    std::cout << *cptr << '\n';

    // you CAN make a const pointer by putting the const after the data type
    int const *rcptr{&bruh};
    std::cout << *rcptr + 1 << '\n';

    std::string vv{"SOME RELALYYAYVFYUVUDSVUYDVJFHBSKDVBKJSFBNVKJHBFSKHBV KHFSBVKFBS KJVB KFJB"};
    watch(&vv);

    // pointer to a const is okay
    // a const pointer is not, that is so stupid, esp to pass into a function

    int *wow = {&c};
    std::cout << *wow << std::endl;
    stillCopy(wow);
    std::cout << *wow << std::endl; // only a copy OF the pointer is passed in
    notCopy(wow, &a);
    std::cout << *wow << std::endl; // well now the actual original pointer points at something else,

    // use pass by address for default values (if the default is nullptr we know it is a default case and not user
    // supplied)

    int xx = 7;
    int yy = 5;

    std::cout << xx << ' ' << yy << '\n'; // should print 7 5

    sort2(xx, yy); // make sure sort works when values need to be swapped
    std::cout << xx << ' ' << yy << '\n'; // should print 5 7

    sort2(xx, yy); // make sure sort works when values don't need to be swapped
    std::cout << xx << ' ' << yy << '\n'; // should print 5 7


    return EXIT_SUCCESS;
}
