#include <iostream>
using namespace std;
class Base // class Base is an abstract class because it contains pure virtual function fun1
{
public:
    virtual void fun1() = 0; // fun1 is pure virtual function
    void fun2()
    {
        cout << "fun2 in Base class" << endl;
    }
};
class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived class constructor" << endl;
    }
};
// Here Derived class is also abstract Class ==> because it is not geving any defination to PVF fun1()
int main()
{
    Base objb;    // error: cannot declare variable ‘objb’ to be of abstract type ‘Base’
    Derived objd; // error: cannot declare variable ‘objd’ to be of abstract type ‘Derived’
    return 0;
}
// virtual void fun()=0;  ⇒  this is pure virtual function.
// Any class which contains the pure virtual function is called an abstract class.

// Any class inheriting the abstract class should contain the definition of pure virtual function.
// Else that child class will also become the abstract class.
// We can not create the object of the abstract class.

