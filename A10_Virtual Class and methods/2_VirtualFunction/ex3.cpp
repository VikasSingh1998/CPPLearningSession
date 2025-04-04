#include <iostream>
using namespace std;
class Base
{
public:
    static virtual void fun() // error
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

    // Base pointer can hold the address of Derived class object
    Base *ptrb = &objd;
    ptrb->fun();

    return 0;
}
// error: member ‘fun’ cannot be declared both ‘virtual’ and ‘static’
//--------------------------------------------------------------------
//  If some method is described as static ⇒ this method is the property of that class, not the object. Static functions are resolved at compile time, while virtual functions are resolved at runtime based on the object's type.
//  Virtual functions can not be static  ⇒  bez, virtual functions are made so that they can be inherited in child class and their object can use them. Virtual functions need an object to operate on.
//  So it does not make any sense to make the virtual function static.

