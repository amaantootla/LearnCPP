#include <iostream>
#include <utility> // for std::move

int main()
{
    return 1;
}

// rvalue reference can be created via
// e.g. T&& x = Class(5, 5)
// normally Class would go out of scope at the end of the expression (since its a rvalue)
// but the rvalue reference keeps it alive
// so we can still operate on it
// std::cout << x
// would still work since x would act as Class (since its a reference to it)

// when an rvalue is passed in to a function
// to construct it or assign it
// use the move versions of the copy/assignment methods
// which will set the rvalue to null and steal its pointer
// (shallow copy), obviously this wont work for lvalues (named vars)
// since why would you modifible another named varibale
// we know if its a temp object if its a rvalue reference being
// passed in

// the rvalue should be left in a valid state so its destrctor
// doesnt mess up pointers

// std::move just rvalue-ifies a lvalue so
// move semantics can be used

// see The Big Five for implementations of
// such semantics