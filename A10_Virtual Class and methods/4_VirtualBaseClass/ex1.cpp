#include <iostream>
using namespace std;
//--------------------------

// Base class A
class A
{
    // Virtual function fun1 in class A
    // This function can be overridden by derived classes
    virtual void fun1()
    {
        cout << "fun1 in the class A" << endl;
    }
};

// Class B inherits from class A
// B inherits fun1() from A
class B : public A
{
    // No additional members or functions in B
    // B simply inherits all public and protected members of A
};

// Class C inherits from class A
// C also inherits fun1() from A
class C : public A
{
    // No additional members or functions in C
    // C simply inherits all public and protected members of A
};

// Class D inherits from both B and C
// This creates ambiguity because both B and C inherit from A, so D has two copies of A's members
class D : public B, public C
{
public:
    // Member function fun2 in class D
    void fun2()
    {
        // Attempt to call fun1() will result in ambiguity
        // fun1(); // Error: reference to 'fun1' is ambiguous

        // Explanation:
        // D inherits from both B and C, and both B and C have a fun1() function inherited from A.
        // Since the compiler sees two possible fun1() functions (one from B and one from C),
        // it doesn't know which one to call, resulting in an error.

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
Explanation of Key Points:
===========================
Inheritance Hierarchy:
-------------------------
Class A: The base class that contains a virtual function fun1().
Class B and Class C: Both classes inherit from A, so they each have their own version of fun1() inherited from A.
Class D: Inherits from both B and C. Since both B and C have a version of fun1() from A, class D ends up with two potential fun1() functions.

Ambiguity in Multiple Inheritance:
-----------------------------------
When D inherits from both B and C, there is an ambiguity because both B and C have inherited fun1() from A.
If you try to call fun1() from D, the compiler will not know whether to call the fun1() from B's branch or C's branch of the inheritance tree, leading to an error.
This issue is a common problem in multiple inheritance scenarios in C++, where the same function or member exists in multiple base classes.

Resolving Ambiguity:
---------------------
In this example, the ambiguity isn't resolved, and trying to call fun1() directly would result in a compilation error.
To resolve this ambiguity, you could specify which version of fun1() you want to call by explicitly qualifying it (e.g., B::fun1() or C::fun1()),
or you could use "virtual inheritance" to ensure that fun1() is only inherited once in the entire hierarchy.
*/
