//Function Overriding Example
#include <iostream>
using namespace std;
class Parent
{
public:
    void fun()
    {
        cout << "fun in class Parent" << endl;
    }
};
class Child : public Parent
{
public:
    void fun()
    {
        cout << "fun in class Child" << endl;
    }
};
int main()
{
    Parent objp;
    Child objc;
    objp.fun(); // fun in class Parent
    objc.fun(); // fun in class Child

    // here fun() is overridden in the Child class
    // now to call the fun() in Parent class by using the Child object, we have to use the :: operator( scope resolution operator ).
    objc.Parent::fun(); // fun in class Parent
    objc.Child::fun();  // fun in class Child

    return 0;
}
// obj.className::method();
/*
Function overriding occurs when a derived (or child) class provides a specific implementation of a
function that is already defined in its base (or parent) class.
In overriding, the function in the derived class has the same name, return type, and parameters as
in the base class, effectively replacing the behavior of the parent class function when called from
an instance of the derived class.

Key points about function overriding:
-------------------------------------------
It allows the child class to provide a different implementation for the same function defined in the parent class.
The function signature (name, return type, and parameters) must match exactly in both the base and derived classes.
If you want to access the parent class's version of the function from the child class, you can use the scope resolution operator (::), as shown in your example.
*/
