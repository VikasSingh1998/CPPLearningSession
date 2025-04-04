#include <iostream>
using namespace std;

//--------------------------
// Abstract base class B
class B
{
private:
    int a; // Private data member, specific to the base class

public:
    // Pure virtual function (makes B an abstract class)
    // This function must be implemented by any derived class
    virtual void fun1() = 0;

    // Regular member function
    // This function is fully implemented in the base class and can be inherited by derived classes
    void fun2()
    {
        cout << "fun2 in the base class" << endl;
    }
};

// Derived class D inherits from the abstract base class B
class D : public B
{
private:
    int a; // Private data member, specific to the derived class

public:
    // Implementation of the pure virtual function from the base class B
    // This is mandatory for D to be a concrete class (non-abstract) and hence, instantiable
    void fun1() override
    {
        cout << "Implementing the pure virtual function in Derived class" << endl;
    }
};

int main()
{
    // B objb; // Error: We cannot create an object of an abstract class B.

    // Pointer of type B (abstract class)
    // While we can't create an object of B, we can create a pointer of type B
    B *b;

    // Creating an object of the derived class D
    D objd;

    // Pointing the base class pointer to the derived class object
    // This is an example of polymorphism where a base class pointer is used to refer to a derived class object
    b = &objd;

    // Calling a non-virtual function through the base class pointer
    // This will call the implementation in the base class, not the derived class
    b->fun2(); // Output: fun2 in the base class

    // Calling the pure virtual function implemented in the derived class
    // This will call the derived class's implementation of the pure virtual function
    b->fun1(); // Output: Implementing the pure virtual function in Derived class

    return 0;
}

