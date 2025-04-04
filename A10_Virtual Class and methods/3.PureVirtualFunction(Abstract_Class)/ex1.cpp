#include <iostream>
using namespace std;

// Base class B, which contains a pure virtual function and hence is an abstract class
class B
{
private:
    int a; // Private data member, not accessible to derived classes

public:
    // Pure virtual function, making B an abstract class
    // This must be implemented by any derived class, or the derived class will also be abstract
    virtual void fun1() = 0;

    // Non-virtual function in the base class
    // This function is fully implemented in the base class and can be used by derived classes
    void fun2()
    {
        cout << "fun2 in the base class" << endl;
    }
};

// Derived class D inheriting from abstract base class B
class D : public B
{
private:
    int a; // Private data member specific to the derived class

public:
    // Implementation of the pure virtual function from the base class B
    // This is mandatory; otherwise, D would also be abstract
    void fun1() override
    {
        cout << "Implementing the pure virtual function in Derived class" << endl;
    }
};

int main()
{
    // B objb; // Uncommenting this line will cause a compilation error
    // Error: cannot declare variable ‘objb’ to be of abstract type ‘B’
    // Explanation: You cannot instantiate an object of an abstract class.

    D objd; // Valid: objd is an object of the derived class D, which provides an implementation for all pure virtual functions

    // Calling a non-virtual function from the base class using the derived class object
    objd.fun2(); // fun2 in the base class
    objd.fun1(); // Implementing the pure virtual function in Derived class

    return 0;
}
/*
Note
========
We can not create the object of abstract class.
But we can create the pointer of the abstract class.
*/
