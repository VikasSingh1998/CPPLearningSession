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
class B : public A
{
public:
    void fun()
    {
        cout << "function in class B" << endl;
    }
};

int main()
{
    A obja = A();
    obja.fun(); // function in class A

    B objb = B();
    objb.fun(); // function in class B

    // A reference or pointer of the parent class can hold the child class object.
    A obja1 = B();
    obja1.fun(); // function in class A
}
/*
what is the diff between
A obja = A();
and
A* obja = new A();
==============================================================
A obja = A();
-------------


A* obja = new A(); ==> new A() returns the address (a pointer) to the dynamically allocated object of type A.
-------------------------------------------------------------------------------------------------------------
new A() ==> creates an object of type A on the heap.
The memory address of this newly created object is returned.
The pointer obja holds the address of the object.
The object created by new A() will persist until you manually free the memory using delete ==>
delete obja; // Frees the memory allocated for the object

If you don't call delete, the memory will not be reclaimed, causing a memory leak.


*/

