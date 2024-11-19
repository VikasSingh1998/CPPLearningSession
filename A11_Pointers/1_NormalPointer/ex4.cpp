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
===========================================================================
Problems with Normal Pointers
=============================
Some Issues with normal pointers in C++ are as follows:
1. Memory Leaks: 
    This occurs when memory is repeatedly allocated by a program but never freed. 
    This leads to excessive memory consumption and eventually leads to a system crash. 

2. Dangling Pointers: 
    A dangling pointer is a pointer that occurs at the time when the object is de-allocated 
    from memory without modifying the value of the pointer.

3. Wild Pointers: 
    Wild pointers are pointers that are declared and allocated memory but the pointer is never initialized 
    to point to any valid object or address.

4. Data Inconsistency: 
    Data inconsistency occurs when some data is stored in memory but is not updated in a consistent manner.

5. Buffer Overflow: 
    When a pointer is used to write data to a memory address that is outside of the allocated memory block. 
    This leads to the corruption of data which can be exploited by malicious attackers.
