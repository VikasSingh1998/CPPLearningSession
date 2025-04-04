#include <iostream>
using namespace std;

// Base class B
class B
{
private:
    int a; // Private data member, not accessible to derived classes

public:
    // Virtual function in the base class
    // This function can be overridden in derived classes, but it's not mandatory
    virtual void fun1()
    {
        cout << "virtual fun1 in Base" << endl;
    }

    // Non-virtual function in the base class
    // This function cannot be overridden in the derived class in the sense of polymorphism
    void fun2()
    {
        cout << "fun2 in the base class" << endl;
    }
};

// Derived class D inheriting from base class B
class D : public B
{
private:
    int a; // Private data member, not related to the base class's private member

public:
    // Non-virtual function in the derived class
    // This hides the base class's fun2() method, but does not override it
    void fun2()
    {
        cout << "Derived class fun2" << endl;
    }

    // Note: fun1() from the base class is not overridden here,
    // but this is perfectly valid. If not overridden, the base class's version of fun1() is used.
};

int main()
{
    B *b;   // Pointer of type Base class
    D objd; // Object of Derived class

    b = &objd; // Base class pointer pointing to a derived class object

    // Since fun1() is virtual and not overridden in D, this calls the base class's fun1()
    b->fun1(); // Output: virtual fun1 in Base

    return 0;
}
/*
Explanation of Key Points:
=============================
Virtual Function in Base Class (fun1):
---------------------------------------
The function fun1 is declared as virtual in the base class B.
This means that if the derived class D defines its own version of fun1,
that version will be called when the function is invoked through a base class pointer or reference.
However, if the derived class does not provide an override (like in this case), the base class's implementation will be used.
This is completely valid, and the program will compile and run without errors.

Non-Virtual Function (fun2):
-----------------------------
The function fun2 is not virtual in the base class B. This means that even though the derived class D defines its own version of fun2,
it does not override the base class version in the context of polymorphism.
When fun2() is called on a base class pointer pointing to a derived class object,
the base class version will be called unless explicitly cast to the derived class.

Pointer to Base Class (B *b):
------------------------------
b is a pointer to B, but it is pointing to an object of the derived class D.
The call b->fun1() will call fun1() of the base class B because fun1 was not overridden in D.

*/
