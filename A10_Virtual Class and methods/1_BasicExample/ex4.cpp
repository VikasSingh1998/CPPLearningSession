#include <iostream>
using namespace std;
class A
{
public:
    void fun()
    {
        cout << "function in class A" << endl;
    }
};
class B
{
public:
    void fun()
    {
        cout << "function in class B" << endl;
    }
};
class C : public A, public B
{
public:
    void fun()
    {
        fun();
        cout << "function in class C" << endl;
    }
};
int main()
{
    C c;
    c.fun(); // function in class c will be called
    return 0;
}
// This will be an infinite recursion.
// fun() in class C will call fun() in class C bez of the function overriding.
// So no output will be printed and it will be an infinite recursion.
