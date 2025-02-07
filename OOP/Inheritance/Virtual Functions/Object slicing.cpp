// Derived d { 10 }
// Base b { d }
// b is a sliced object of d, i.e. b contains the Base part of d
// no virtual function resolution will occur (it only works for refs or ptrs)

// vectors must use ref wrapper in std or be a vector of pointers (no anonymous objects)