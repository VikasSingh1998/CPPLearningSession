#include <iostream>
using namespace std;

// Abstract base class A
class A
{
public:
    // Pure virtual function (PVF) in class A
    // This function must be implemented by any non-abstract derived class
    virtual void fun1() = 0;

    // Regular member function with a defined body
    // This function can be inherited by derived classes as is
    void fun2()
    {
        cout << "fun2 body in class A" << endl;
    }
};

// Class B inherits from abstract class A
// Since A has a pure virtual function, B must provide an implementation for it
// B also declares its own pure virtual function, making B an abstract class
class B : public A
{
public:
    // Implementing the pure virtual function fun1 from class A
    // This implementation is mandatory to make B concrete, but B introduces its own PVF fun3
    virtual void fun1() override
    {
        cout << "Implementing the PVF of class A in class B" << endl;
    }

    // New pure virtual function introduced in class B
    // Any class deriving from B must implement this function or it will remain abstract
    virtual void fun3() = 0;
};

// Class C inherits from abstract class B
// Since B has a pure virtual function (fun3), C must provide an implementation for it
// Once all PVFs are implemented, C becomes a concrete (non-abstract) class
class C : public B
{
public:
    // Implementing the pure virtual function fun3 from class B
    // With this implementation, C is now a concrete class and can be instantiated
    virtual void fun3() override
    {
        cout << "Implementing the PVF of class B in class C" << endl;
    }
};

int main()
{
    // Creating an object of class C
    // C is concrete because it implements all pure virtual functions from its base classes
    C objc;

    // Calling fun2(), which is defined in the base class A and inherited by C
    objc.fun2(); // Output: fun2 body in class A

    return 0;
}
/*
*/
