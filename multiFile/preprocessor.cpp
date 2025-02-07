#include <iostream>

using namespace std;

// subs every occurance of "NAME" for "ME"
// always global scope, if this was defined in a
// function it would still sub the same
// THIS ONLY APPLIES TO THIS FILE
// another file would not have NAME subbed in even if it was included on
// the g++ cmd args
#define NAME "ME"

#define YEAH

int main()
{
    // conditional compile whatever or not a macro is defined
    // e.g. "YEAH" is in fact defined, so the code will be compiled
    #ifdef YEAH
        cout << "yeah is defined" << endl;
    #endif

    #ifdef NAH
        cout << "this code will not compile, since NAH is not defined" << endl;
    #endif

    #if 0
        cout << "never compiles" << "this is just a fancy comment out alternative" << endl;
    #endif
}