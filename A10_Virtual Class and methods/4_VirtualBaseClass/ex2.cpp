#include <iostream>
using namespace std;

//--------------------------
// Base class A
class A
{
public:
    // Virtual function fun1 in class A
    // This function can be overridden by derived classes
    virtual void fun1()
    {
        cout << "fun1 in the class A" << endl;
    }
};

// Class B inherits from A using virtual inheritance
// Virtual inheritance ensures that there is only one base class A, even if multiple paths are used
class B : virtual public A
{
    // No additional members or functions in B
    // B simply inherits all public and protected members of A
};

// Class C inherits from A using virtual inheritance
// Like B, C also inherits A virtually, ensuring that A is not duplicated in further inheritance
class C : virtual public A
{
    // No additional members or functions in C
    // C simply inherits all public and protected members of A
};

// Class D inherits from both B and C
// Since both B and C inherit A virtually, D will have only one instance of A
class D : public B, public C
{
public:
    // Member function fun2 in class D
    void fun2()
    {
        fun1(); // No ambiguity here due to virtual inheritance
        // With virtual inheritance, D has a single instance of A, so fun1() is unambiguous

        cout << "fun2 in the class D" << endl;
    }
};

int main()
{
    D objd;      // Creating an object of class D
    objd.fun2(); // Calls fun2() in class D and then fun1() from class A
    return 0;
}
/*
fun1 in the class A
fun2 in the class D
*/
/*
Virtual inheritance ensures only one copy of a base class's member variables are inherited by grandchild derived classes.
*/
/*
Here we have inherited class A virtually,so A acts as virtual base class.
whenever you inherit virtual base class,it is like all the member of base class are static,
So only one of them is used.

Here are the key points about virtual base classes in C++:
Diamond Problem: Multiple inheritance can lead to the diamond problem, where a class inherits from two classes
that both inherit from a common base class. This creates ambiguity in the inheritance hierarchy, especially when
there are member variables or functions with the same name in the intermediate base classes.
-----------
Virtual Base Class: To solve the diamond problem, you can use virtual base classes. When a base class is declared as virtual,
it means that only one instance of the base class will be present in the inheritance hierarchy, even if multiple derived classes
inherit from it indirectly.
-----------
Single Instance: By using a virtual base class, the derived classes that inherit from it indirectly share a single instance
of the virtual base class. This ensures that there are no duplicate subobjects of the virtual base class in the final derived class.
----------
Object Layout: The use of virtual base classes affects the object layout in memory. It introduces additional mechanisms,
such as a virtual base pointer, to ensure that the correct instance of the virtual base class is accessed and that there
are no duplicate subobjects.
-----------
Initialization: When constructing objects that involve virtual base classes, the virtual base class part of the object is
initialized before any non-virtual base classes. This ensures that the virtual base class is properly constructed and avoids
issues with uninitialized data.
-----------
In summary, virtual base classes in C++ are used to handle multiple inheritance scenarios where the diamond problem could arise.
They allow for a single shared instance of the base class in the inheritance hierarchy, ensuring proper object layout and avoiding
ambiguities in member access.
*/
