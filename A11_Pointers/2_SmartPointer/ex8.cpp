/*
weak_ptr
=========
Weak_ptr is a smart pointer that holds a non-owning reference to an object.
It’s much more similar to shared_ptr except it’ll not maintain a Reference Counter.
In this case, a pointer will not have a stronghold on the object.
The reason is if suppose pointers are holding the object and requesting for other objects then they may form a Deadlock.
*/
//===================================================================================================
#include <iostream>
using namespace std;
// Dynamic Memory management library
#include <memory>

class Rectangle
{
    int length;
    int breadth;

public:
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }

    int area() { return length * breadth; }
};

int main()
{
    // Create a shared_ptr<Rectangle> named P1 and initialize it with a dynamically allocated Rectangle object with length 10 and breadth 5:
    shared_ptr<Rectangle> P1(new Rectangle(10, 5));

    // 	Create a weak_ptr<Rectangle> named P2 and initialize it with P1:
    // Unlike shared_ptr, a weak_ptr does not affect the reference count of the object it points to.
    // It is used to observe and access an object without keeping it alive or affecting its ownership.
    weak_ptr<Rectangle> P2(P1);

    cout << P1->area() << endl;          // 50
    cout << (P2.lock())->area() << endl; // 50

    // Print the reference count of the Rectangle object pointed to by P1 using use_count()
    // (which is 1 because P2 does not contribute to the reference count):
    cout << P1.use_count() << endl;
    return 0;
}
/*
In summary, the std::weak_ptr in this code allows you to create a non-owning weak reference to an object managed by a std::shared_ptr.
It enables you to access the object without affecting its reference count or keeping it alive.
This is useful for scenarios where you need to observe an object's state without prolonging its lifetime or causing cyclic dependencies.
*/

