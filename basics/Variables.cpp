#include <iostream>

int main()
{

	// Define and assign a value to a variable
	[[maybe_unused]] int x;
	x = 10;

	// Copy initialization
	[[maybe_unused]] int y = 10;

	// Direct initialization
	[[maybe_unused]] int z( 7 );

	// List initialization

	[[maybe_unused]] int a{ 5 }; // Direct
	[[maybe_unused]] int b = { 1 }; // Copy
	[[maybe_unused]] int c{}; // Value (empty)

	// Use lists!
	[[maybe_unused]] int my_var { 8 };

	// Tell the compiler to fuck off with
	// [[maybe_unused]]

	return 0;
}

// A named variable is called an identifier
// A literal is a hard coded value, e.g. "Hello", 4
// Literals exist in the executable, variables exist in memory