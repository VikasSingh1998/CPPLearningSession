// A pointer in C++ is a variable that holds the memory address of another variable.
// It allows indirect access to the value stored at that memory address.
//=-------------------------------------------------------------------------
#include <iostream>
using namespace std;
int main()
{
    int number = 42;
    int *ptr = &number; // Pointer to an integer

    cout << "Value of number: " << number << endl;
    cout << "Address of number: " << &number << endl;
    cout << "Value via pointer: " << *ptr << endl; // Dereferencing the pointer

    return 0;
}
/*
Value of number: 42
Address of number: 0x61ff08
Value via pointer: 42
*/
