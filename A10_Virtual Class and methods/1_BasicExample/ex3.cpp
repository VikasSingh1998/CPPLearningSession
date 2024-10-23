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
class C : public A, public B
{
public:
    void fun1()
    {
        cout << "fun1 in class C" << endl;
        // fun();//Error
        // error: reference to ‘fun’ is ambiguous --> which fun() to call
        // to resolve the ambiuity problem, we have to use :: with class name
        A::fun(); // fun in class A
        B::fun(); // fun in class B
    }
};

int main()
{
    C objc;
    objc.fun1(); // fun1 in class C

    return 0;
}
// className::fun() ==> to call the fun() in class "className"
