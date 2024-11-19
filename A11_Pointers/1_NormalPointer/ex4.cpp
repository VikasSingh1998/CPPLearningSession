#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;

    // We could also add constructors and other member functions
    // to initialize and manipulate the rectangle's dimensions,
    // but for this demonstration, we'll focus on memory management.
};

void fun()
{
    // Dynamically allocate memory for a Rectangle object
    Rectangle *p = new Rectangle();

    // Problem: The dynamically allocated memory is never deallocated
    // When the function fun ends, 'p' goes out of scope, but the memory
    // allocated with 'new' is not automatically freed. This causes a
    // memory leak, as the allocated memory remains reserved in the heap.

    // Solution: To prevent the memory leak, we should free the memory
    // when we're done using it.
    delete p;

    // Note: Once the memory is deallocated, 'p' becomes a dangling pointer.
    // In this specific case, 'p' goes out of scope immediately after, so
    // it's not a problem, but in more complex programs, it's important to
    // avoid using pointers after they have been deleted.
}

int main()
{
    // Infinite Loop: The function fun is called repeatedly
    while (1)
    {
        fun(); // Keep calling fun, which allocates and deallocates memory
    }

    // The program will still run indefinitely due to the infinite loop,
    // but now it won't run out of memory because each allocation is followed
    // by a deallocation.

    return 0;
}

