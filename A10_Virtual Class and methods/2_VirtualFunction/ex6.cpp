#include <iostream>
using namespace std;
//--------------------------
// Base class B
class B
{
private:
    int a; // Private data member of base class

public:
    // Virtual function to demonstrate runtime polymorphism
    virtual void fun1()
    {
        cout << "virtual fun1 in Base" << endl;
    }

    // Non-virtual function, which does not support runtime polymorphism
    void fun2()
    {
        cout << "fun2 in the base class" << endl;
    }
};

// Derived class D inheriting from base class B
class D : public B
{
private:
    int a; // Private data member of derived class

public:
    // Override the virtual function from the base class
    void fun1() override
    {
        cout << "override the virtual fun1 in the Derived class" << endl;
    }

    // Non-virtual function, hiding the base class's fun2 method
    void fun2()
    {
        cout << "Derived class fun2" << endl;
    }
};

int main()
{
    B *b;   // Pointer of type Base class
    D objd; // Object of Derived class

    b = &objd; // Base class pointer pointing to a derived class object

    // Calls Base class's fun2() because fun2 is not virtual
    b->fun2(); // Output: fun2 in the base class

    // Calls Derived class's fun1() because fun1 is virtual and overridden in the derived class
    b->fun1(); // Output: override the virtual fun1 in the Derived class

    return 0;
}

