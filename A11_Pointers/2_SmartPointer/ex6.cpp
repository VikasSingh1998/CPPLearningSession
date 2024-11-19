/*
shared_ptr
==========
By using shared_ptr more than one pointer can point to this one object at a time
and it’ll maintain a Reference Counter using the use_count() method.
reference counter ==> how many pointer is pointing to that object.
*/
//===============================================================================
// Here both smart pointer P1 and P2 are pointing to the object Addition to which
// they both maintain a reference of the object
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

    cout << P1->area() << endl; // 50

    // Create another shared_ptr<Rectangle> named P2 and assign P1 to it:
    shared_ptr<Rectangle> P2;
    P2 = P1;
    // 	Now both P1 and P2 share ownership of the same Rectangle object. The reference count for this object becomes 2.

    cout << P2->area() << endl; // 50

    // 	Since P1 and P2 share ownership, modifying the object through either pointer reflects the change in both.
    //  Therefore, printing the area using P1 again doesn't result in an error and gives the same area value:
    cout << P1->area() << endl; // 50

    // This'll print 2 as Reference Counter is 2
    // Print the reference count of the Rectangle object pointed to by P1 using use_count() (which is 2):
    cout << P1.use_count() << endl;
    return 0;
}

