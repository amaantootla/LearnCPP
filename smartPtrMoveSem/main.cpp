#include <cassert>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

template <typename T> class iUseDynamicMemory
{
  private:
    T *m_arr{nullptr};
    size_t m_length{0};

    void deepCopy(const iUseDynamicMemory &rhs)
    {
        m_length = rhs.m_length;
        m_arr = new T[m_length];

        for (size_t i{0}; i < m_length; ++i)
        {
            m_arr[i] = rhs.m_arr[i];
        }
    }

    friend void swap(const iUseDynamicMemory &a, const iUseDynamicMemory &b)
    {
        std::swap(a.m_length, b.m_length);
        std::swap(a.m_arr, b.m_arr);
    }

  public:
    iUseDynamicMemory(int length = 1)
    {
        assert(length > 0);

        m_length = static_cast<size_t>(length);
        m_arr = new T[m_length];
    }

    iUseDynamicMemory(const iUseDynamicMemory &rhs)
    {
        deepCopy(rhs);
    }

    iUseDynamicMemory(const iUseDynamicMemory &&rhs)
    {
        swap(*this, rhs);
    }

    iUseDynamicMemory &operator=(const iUseDynamicMemory &rhs)
    {
        delete[] m_arr;
        deepCopy(rhs);

        return *this;
    }

    iUseDynamicMemory &operator=(const iUseDynamicMemory &&rhs)
    {
        delete[] m_arr;
        swap(*this, rhs);

        return *this;
    }

    ~iUseDynamicMemory()
    {
        delete[] m_arr;
    }
};

void lvalue(int &x)
{
    std::cout << "lvalue call: " << x << std::endl;
}

void rvalue(int &&x)
{
    std::cout << "rvalue call: " << x << std::endl;
}

class Fraction
{
  private:
    int m_numerator{0};
    int m_denominator{1};

  public:
    Fraction(int numerator = 0, int denominator = 1) : m_numerator{numerator}, m_denominator{denominator}
    {
    }

    friend std::ostream &operator<<(std::ostream &out, const Fraction &f1)
    {
        out << f1.m_numerator << '/' << f1.m_denominator;
        return out;
    }
};

void printFraction(const Fraction *ptr)
{
    if (ptr)
        std::cout << *ptr << '\n';
    else
        std::cout << "No fraction\n";
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    // use move semantics
    // hop over resource ownership from one smart pointer to another

    int a{10};
    int &b{a};
    [[maybe_unused]] int &&x{10838}; // r-value reference

    lvalue(b);
    rvalue(13928); // no x, an r-value reference would not count, as that is actually a lvalue, only the fr literal is a
                   // r-value

    // if using copy and swap use your own swap on the resoruce your class owns
    // NOT std::swap() since that will call the move constructor/assignment operator
    // which will just keep calling itself

    // if you no longer need to use a l-value or are swapping
    // use move semantics, that is way more efficent
    // even when adding data to containers, use std::move() instead of the lvalue
    // why create a copy when the local variable will be destoryed anyway

    std::vector<std::string> v{};
    std::string tmp{};

    for (size_t i{0}; i < 10; ++i)
    {
        std::cin >> tmp;
        v.push_back(std::move(tmp)); // what good is copying tmp, we dont even use it anymore? might as well stale it
        // tmp is valid but unknown, we dont use it again until we write a new value via the call to std::cin
    }

    // class iUseDynamicMemory manages a resource, lets make sure if we every allocate it on the heap
    // that we delete it, using a smart pointer, which handles that for us

    [[maybe_unused]] auto smartPtr{std::make_unique<iUseDynamicMemory<int>>(10)};

    // you can return by std::unique_ptr<T>, and move semantics will be used on assigning the value
    // do not return by pointer or reference, makes no sense

    auto ptr{std::make_unique<Fraction>(3, 5)};
    printFraction(ptr.get()); // to get the actual Fraction that the std::unique_ptr stores

    Fraction* frac {new Fraction{}};
    [[maybe_unused]] std::shared_ptr<Fraction> ptr1 {frac};

    {
        //std::shared_ptr<Fraction> ptr2 {frac}; // this wont work, you can only share a resoruce by copying a existing shared pointer
        [[maybe_unused]] std::shared_ptr<Fraction> ptr2 {ptr1}; // so like this
    }

    // use make_shared() instead, no way to accidently point to the same resoruce vs shared_ptr

    return EXIT_SUCCESS;
}
