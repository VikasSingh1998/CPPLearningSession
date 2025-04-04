#include <stdio.h>
#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        std::cout << "Default constructor called" << std::endl;
    }

    A(const A &other)
    {
        std::cout << "Copy constructor called" << std::endl;
    }
};

int main()
{
    A obja = A(); // A() ==> this will call the default constructor.
    return 0;
}
// output
// ===========
// Default constructor called
// ===================================================================================================
/*
In C++, the statement A obja = A(); does a couple of things, depending on how the class A is defined:
---------------------------------------------------------------------------------------------------------
1. Object Creation: A() creates a temporary object of type A. This calls the default constructor of class A.

2. Copy Initialization: The temporary object created by A() is then used to initialize obja through copy initialization.
   This means the copy constructor of class A is called to create obja as a copy of the temporary object.

So, A obja = A(); essentially creates a temporary object of class A and then uses that temporary object to initialize obja.

output without optimization==>
------------------------------
Default constructor called
Copy constructor called
==========================================================================================================
Important Note:
================
In practice, modern C++ compilers often optimize this code using Copy Elision (including Return Value Optimization - RVO).
With these optimizations, the compiler might eliminate the temporary object creation and directly initialize obja using the default constructor,
avoiding the call to the copy constructor. However, conceptually, the steps I outlined above are what would happen without such optimizations.
*/
