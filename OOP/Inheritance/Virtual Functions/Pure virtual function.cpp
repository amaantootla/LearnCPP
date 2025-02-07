// pure virtual function = abstract function = function with no defination
// MUST be defined by derived classes
// BUT it can be defined in base as well, just not inline (to provide a deafult implementation).
//virtual TYPE NAME() [const] = 0
// any class with a pure virtual function makes it a abstract base class

// CANNOT CREATE AN INSTANCE OF A ABSTRACT BASE CLASS

// interface class = no member variables + all virtual functions
// preface interface class with an "I"
// this way you can upcast to the interface class so you can use any
// derived class that matches the standard laid out by the interface class

