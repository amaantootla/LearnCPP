#include <climits> // for CHAR_BIT
#include <cstdint>
#include <cstdint>
#include <iomanip> // for std::setw (which sets the width of the subsequent output)
#include <iostream>

int main()
{
    std::cout << "A byte is " << CHAR_BIT << " bits\n\n";

    std::cout << std::left; // left justify output

    std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";
    std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
    std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
    std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
    std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
    std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
    std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
    std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";

    // full form
    [[maybe_unused]] signed short int e{};
    [[maybe_unused]] signed int f{};
    [[maybe_unused]] signed long int g{};
    [[maybe_unused]] signed long long int h{};

    // be less verbose
    [[maybe_unused]] short a{};
    [[maybe_unused]] int b{};
    [[maybe_unused]] long c{};
    [[maybe_unused]] long long d{};

    std::cout << "BEWARE INETGER DIVISION 6/4: " << 6 / 4 << '\n';

    // fixed widths are quirky, avoid, instead use fastest for the CPU and least memory
    std::cout << "least 8:  " << sizeof(std::int_least8_t)  * 8 << " bits\n";
	std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
	std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
	std::cout << '\n';
	std::cout << "fast 8:  "  << sizeof(std::int_fast8_t)   * 8 << " bits\n";
	std::cout << "fast 16: "  << sizeof(std::int_fast16_t)  * 8 << " bits\n";
	std::cout << "fast 32: "  << sizeof(std::int_fast32_t)  * 8 << " bits\n";

    return 0;
}
