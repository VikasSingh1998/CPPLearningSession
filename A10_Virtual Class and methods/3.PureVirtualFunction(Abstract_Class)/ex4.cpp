#include <iostream>
using namespace std;

class A // class A is abstract class, because it contain the pure virtual function
{
public:
    virtual void fun1() = 0; // this is the pure virtual function in A
    void fun2()
    {
        cout << "fun2 body in class A" << endl;
    }
};

class B : public A
{
public:
    virtual void fun1()
    {
        cout << "Implementing the PVF of class A in class B" << endl;
    }
    virtual void fun3() = 0;
};
class C : public B, public A
{
public:
    virtual void fun3()
    {
        cout << "Implementing the PVF of class B in class C" << endl;
    }
};
int main()
{
    C objc; // error: cannot declare variable ‘objc’ to be of abstract type ‘C’
    // unimplemented PVF fun1 in class C
    return 0;
}

// Since class c is inheriting the class A directly, it should give the definition of the fun1() which is PVF in class A,
// else it will also becomes the abstract class.

