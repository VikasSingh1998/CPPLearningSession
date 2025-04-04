#include <iostream>
using namespace std;
//--------------------------
class A
{
    virtual void fun1()
    {
        cout << "fun1 in the class A" << endl;
    }
};

class B : public A
{
};

class C : public A
{
};

class D : public B, public C
{
public:
    void fun2()
    {
        // fun1();

        cout << "fun2 in the class D" << endl;
    }
};

int main()
{
    D objd;      // Creating an object of class D
    objd.fun2(); // Calls fun2() in class D
    return 0;
}
/*
Here there are 2 fun() function in class D,but jab tak usko call nhi karenge tab tk koi bhi error nahi aayega,
Compiler will give an error only when we call the fun1().
 */
