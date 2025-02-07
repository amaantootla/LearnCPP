#include <iostream>

/*
void DummyPrint() {
    std::cout << "Well this is useless\n";
}

int mutiply(int x, int y) {
    return x * y;
}

*/

int doubleNumber(int n) {
    return n * 2;
}

int main() {
    std::cout << "Number: ";
    int x{};
    std::cin >> x;
    std::cout << "Doubled: " << doubleNumber(x);
}

// Functions have all the normal return types of C
// Parameters work the same way as well
// Protoypes also exist

// Name spaces group functions
// To bring the cout/cin functions out of the std namespace
// using namespace std;