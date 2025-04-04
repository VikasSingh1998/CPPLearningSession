/*
A Virtual Base Pointer (VPTR) is a hidden pointer that the compiler uses in a class with
virtual inheritance to ensure that there's only one instance of the base class, no matter
how many times it is inherited. This mechanism helps manage the single shared instance
of the base class in complex inheritance hierarchies.
==========================================================================================
*/
#include <iostream>
using namespace std;

// Base class A
class A
{
public:
    int x;
    A() : x(10)
    {
        cout << "Constructor of A" << endl;
    }
    void display()
    {
        cout << "Value of x in A: " << x << endl;
    }
};

// Class B inherits from A virtually
class B : virtual public A
{
public:
    B()
    {
        cout << "Constructor of B" << endl;
    }
};

// Class C inherits from A virtually
class C : virtual public A
{
public:
    C()
    {
        cout << "Constructor of C" << endl;
    }
};

// Class D inherits from both B and C
// D will only have one instance of A due to virtual inheritance
class D : public B, public C
{
public:
    D()
    {
        cout << "Constructor of D" << endl;
    }
};

int main()
{
    D objd;         // Creating an object of class D
    objd.display(); // Calls the display function from class A

    // Accessing the base class member
    objd.x = 20;
    objd.display(); // Shows updated value of x

    return 0;
}
/*
Constructor of A
Constructor of B
Constructor of C
Constructor of D
Value of x in A: 10
Value of x in A: 20
*/
/*
Explanation of Key Points:
===========================
Constructors Order:
------------------------
When D is instantiated, the constructors are called in the order: A, B, C, and finally D.
Despite D inheriting from both B and C, the constructor for A is called only once because of virtual inheritance.

Single Instance of A:
---------------------
Even though D inherits from both B and C, both of which inherit from A, only one instance of A exists within D.
This is managed by the Virtual Base Pointer (VPTR), which points to the shared instance of A.

Virtual Base Pointer (VPTR):
------------------------------
Under the hood, when classes B and C inherit A virtually, the compiler adds a virtual base pointer (VPTR) to each of them.
This VPTR ensures that both B and C in D point to the same instance of A.

As a result, when you access A's members (like x or display()), the VPTR ensures you're accessing the single shared instance of A in D.
*/
