🔹 Understanding Function Pointers in C++
-------------------------------------------
A function pointer is a variable that stores the address of a function. 
Using function pointers, we can call functions dynamically at runtime.

✅ Basic Syntax of Function Pointer
-------------------------------------
returnType (*pointerName)(parameterTypes);

returnType: The return type of the function.
pointerName: Name of the function pointer.
parameterTypes: The types of parameters the function accepts.
===================================================================================================
🔹 Example 1: Basic Function Pointer
This example demonstrates how to declare, assign, and call a function pointer.
Code:
------
#include <iostream>
using namespace std;

// Function to print a message
void display() 
{
    cout << "Hello World" << endl;
}

int main() 
{
    // Declare a function pointer that can point to a function returning void and taking no parameters
    void (*funcPtr)();

    // Assign the function's address to the pointer
    funcPtr = display;

    // Call the function using the pointer
    funcPtr();

    return 0;
}
----------------------------------------------------------------------------------------------------
🔹 Example 2: Function Pointer with Parameters
This example shows how to use function pointers with parameters.

Code:
-----
#include <iostream>
using namespace std;

//Function to add the 2 number and return the sum.
int add(int a, int b)
{
    return a+b;
}

int main() 
{
    // Declare a function pointer that can point to a function returning int and taking two int parameters
    int (*funcPtr)(int,int);

    // Assigns the function add to funcPtr.
    funcPtr = add;

    // Calls the add function using the pointer.
    cout<<funcPtr(4,5);//9

    return 0;
}
------------------------------------------------------------------------------------------------

