#include <iostream>
using namespace std;
class Base
{
public:
    // void fun()
    virtual void fun() // to do the late binding
    {
        cout << "function in class Base" << endl;
    }
};
class Derived : public Base
{
public:
    void fun()
    {
        cout << "function in class Derived" << endl;
    }
};

int main()
{
    Base objb;
    Derived objd;

    // Base class pointer hold the address of Base class object.
    // Base *ptrb = &(Base()); ====> Wrong see ex5 in this topic for more explanation.
    Base *ptrb = &objb;
    ptrb->fun(); // function in class Base

    // Derived class pointer hold the address of Derived class object
    Derived *ptrd = &objd;
    ptrd->fun(); // function in class Derived

    // Base pointer can hold the address of Derived class object
    ptrb = &objd; // Object derived ka hai and reference base ka.
    ptrb->fun();  // function in class Base => (if fun() in class Base is not virtual)
                  // function in class Derived => (if fun() in class Base is virtual)

    // Here Base class pointer hold the address of Derived class object.
    // so derived class function should be called, since object is of derived class.

    // to solve this, virtual function is used.
    // virtual function ==> we have to do the run time binding  of that function.

    // Derived class pointer ==> can not hold the address of Base class object.
    // ptrd = &objb;//error: invalid conversion from ‘Base*’ to ‘Derived*’
    // child ka reference ==> parent ko point nhi kr sakta.
    return 0;
}

