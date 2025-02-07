// class BASE
// class DERIVED : virtual public BASE
// class D2: virtual public BASE
// class LASR: public DERIVED, public D2

// a virtual base class is only constructed once

// it is up to the most derived class to call the base constructor
// class LASR() : D2 {}, DERIVED {}, BASE{}