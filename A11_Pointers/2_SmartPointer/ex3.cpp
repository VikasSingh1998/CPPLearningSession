/*
==> A memory address can be pointed by only one unique_ptr at a time.
==> When a unique_ptr is pointing to a memory location, no other unique_ptr
    can point to the same memory location simultaneously. This is because
    unique_ptr enforces exclusive ownership of the memory it manages.

==> Only one std::unique_ptr can own a resource.
==> It ensures that only one std::unique_ptr instance can point to a resource at any given time.
==> When the std::unique_ptr is destroyed or reset, it automatically releases the memory it owns.
==> This pointer type is useful when you want to transfer ownership or ensure that an object has a single owner.
*/
//==========================================================================
// C++ program to demonstrate the working of unique_ptr
// Here we are showing the unique_pointer is pointing to P1.
// But, then we remove P1 and assign P2 so the pointer now points to P2.

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
    unique_ptr<Rectangle> P1(new Rectangle(10, 5)); // smart pointers are object.
    cout << P1->area() << endl;                     // 50

    // Create a second unique_ptr<Rectangle> named P2 and assign P1 to it using "move"
    // the line unique_ptr<Rectangle> P2(P1); was commented out and replaced with P2 = move(P1);.
    // This is because unique_ptr does not allow direct copy construction or assignment.
    // You have to use move to transfer ownership.

    unique_ptr<Rectangle> P2;
    // unique_ptr<Rectangle> P2(P1); ==> error
    // p2=p1; ==> error
    P2 = move(P1);

    // This'll print 50
    cout << P2->area() << endl;

    // cout << P1->area() << endl;
    return 0;
}
/*
The key point to note here is the use of move to transfer ownership of the dynamically allocated Rectangle object from P1 to P2.
After this transfer, P1 no longer owns the object, and attempting to access it through P1 will result in a runtime error.
P2 now manages the object, and you can access it through P2.
*/
