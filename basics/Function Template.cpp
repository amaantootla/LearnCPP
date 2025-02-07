#include <iostream>

template<typename T, int N>
class Vector
{
    private:
        T arr[N];
    public:
        int getN() const { return N; }
};

template<typename T>
T add(T x, T y)
{
    return x + y;
}

template<typename T>
void print(T s)
{
    std::cout << s << std::endl;
}

int main()
{
    Vector<int, 10> my_vector; // just like how std::vector works

    print<int>(add<int>(5, 5)); // our type in this case is int
    print<double>(add<double>(5.86, 5.96)); // our type in this case is double

    print(add(10, 8)); // our type in this case is int (implicity derived via the parameters)
}

// typename makes the type the function/class can handle variable
// TYPE makes essentially a macro the function/class can use (at compile time)