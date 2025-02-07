// virtual functions are overrides to go for the most derived version
// when called from a pointer OR reference

// tag all virtual functions with the override specifer: 
//virtual std::string print() override { return "Im class B"; }

// the final keyword stops a class or function from being inheritied/overriden

// covarient return types:
// overriden functions can return a pointer to their class
//Derived* print() {std::cout << "something"; return this; }
// recall that "this" is a POINTER to the current class
// if casted to Base* THEN it would return a Base* as well


// TIP:
// make the inital function virtual in the base class via the virtual keyword
// tag any virtual functions in the derived classes via the override keyword

// do NOT call virtual functions from constrctuors and destrctuors
// when being constrcuted the derived segment (i.e. the part that contains the virtual function)
// would not even exist yet
// and for the destrctuor, the virtual function would always resolve to the base
// since the derived segment is now destroyed

// ALWAYS make destrctuors virtual