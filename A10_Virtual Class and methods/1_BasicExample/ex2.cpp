#include <iostream>
using namespace std;
class A
{
public:
    void fun()
    {
        cout << "fun in class A" << endl;
    }
};
class B
{
public:
    void fun()
    {
        cout << "fun in class B" << endl;
    }
};
class C : public A, public B // Multiple Inheritance
{
public:
    void fun()
    {
        cout << "fun in class C" << endl;
    }
    // fun() from class A and B are inherited but is overridden
    // to call the fun() in class A and B, we have to  use :: operator
    void callFunAB()
    {
        A::fun();
        B::fun();
    }
};

int main()
{
    C objc;
    objc.fun(); // fun in class C
    // fun() is overridden in the class C, so fun() in class C will be  executed.

    // to call the fun() in class A and class B we have to use the ::
    objc.A::fun(); // fun in class A
    objc.B::fun(); // fun in class B

    objc.callFunAB();
    // fun in class A
    // fun in class B

    return 0;
}
/*
Multiple Inheritaance
======================
Multiple inheritance allows a class to inherit from more than one base class.
This can be useful when a class needs to have the functionalities of multiple base classes.
However, it also introduces complexity, such as the potential for ambiguity if both base classes have a member with the same name.
---------------------
Handling Ambiguities
---------------------
In case of ambiguity (e.g., if both A and B have a member with the same name), you need to specify
which base class's member you are referring to using the scope resolution operator (::)
*/
