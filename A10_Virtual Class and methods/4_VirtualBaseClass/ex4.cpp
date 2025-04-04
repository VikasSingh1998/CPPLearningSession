#include <iostream>
using namespace std;
//--------------------------
class A
{
public:
    virtual void fun1()
    {
        cout << "fun1 in the class A" << endl;
    }
};

class B : public A
{
public:
    void fun1()
    {
        cout << "fun1 in the class B" << endl;
    }
};

class C : public A
{
public:
    void fun1()
    {
        cout << "fun1 in the class C" << endl;
    }
};

int main()
{
    A *ptra;
    B objb;
    C objc;

    ptra = &objb;
    ptra->fun1(); // fun1 in the class B

    ptra = &objc;
    ptra->fun1(); // fun1 in the class C
    return 0;
}

