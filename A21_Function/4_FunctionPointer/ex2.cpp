🔹 Example 3: Function Pointer as a Function Parameter (Callback Function)
This example demonstrates passing a function pointer as a parameter to another function.

Code:
-----
#include <iostream>
using namespace std;

// Function that prints a message
void display(string name) 
{
    cout << "Hello, " << name << "!" << endl;
}

// Function that takes a function pointer as a parameter (callback function)
void executeCallback(void (*functionPointer)(string), string name)
{
    functionPointer(name); // Call the function passed as an argument
}

int main() 
{
    // Pass function pointer to another function
    executeCallback(display, "vikas");

    return 0;
}
---------------------------------------------------------------------------
A callback function is the function whose pointer is passed as an argument to another function. 
The function that receives and calls the function pointer is usually called a higher-order function 
(or simply a function that accepts a callback).

🔹 Clarification with Terminology
Callback Function → The function whose pointer is passed as an argument.
Function Receiving the Callback → The function that accepts the function pointer and calls it.

--------------------------------------------------------------------------------------------------------


