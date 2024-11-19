/*
What are Smart Pointers?
=============================
In CPP, Smart Pointer ===> Object hota hai.
Smart Pointer "Automatic Memory Management" provide karta hai.

They ensure that memory allocated to an object is released when the smart pointer goes out of scope.
This automatic memory management helps in avoiding memory leaks and makes memory handling safer.
*/
#include <iostream>
using namespace std;

class SmartPtr
{
    int *ptr; // This is the actual raw pointer that the smart pointer wraps.
public:
    // This is the constructor of the SmartPtr class.
    // It takes a raw pointer p as an argument (defaulted to nullptr) and initializes the ptr member with it.
    // The explicit keyword prevents implicit conversions during object creation.
    explicit SmartPtr(int *p = nullptr) // Constructor
    {
        ptr = p;
    }

    // This is the destructor of the SmartPtr class.
    // It automatically deletes the memory pointed to by ptr when the SmartPtr object goes out of scope or is explicitly deleted.
    ~SmartPtr() // Destructor
    {
        delete ptr;
    }

    // This is the overloaded dereferencing operator *.
    // It allows accessing the value pointed to by the smart pointer using the * operator as if it were a regular pointer.
    int &operator*() // Overloading dereferencing operator
    {
        return *ptr;
    }
};
int main()
{
    SmartPtr ptr(new int()); // Creating a SmartPtr object with a dynamically allocated int
    *ptr = 20;               // Dereferencing and assigning a value to the dynamically allocated int
    cout << *ptr;            // Printing the value stored in the dynamically allocated int

    // No need to manually delete ptr, as the SmartPtr destructor will take care of it
    return 0;
}
/*
 This example demonstrates the usage of a simple smart pointer class in C++,
 showcasing how it handles dynamic memory allocation and deallocation automatically.
*/

