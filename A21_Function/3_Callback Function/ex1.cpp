🔹 Example 1: Callback Using Function Pointer
-------------------------------------------------
🔹 What is a Callback Function?
A callback function is a function that is passed as an argument 
to another function and is executed later in response to an event or condition.

Callbacks are used to achieve asynchronous execution or event-driven programming.
-----------------------------------------------------------------------------------
🔹 Example 1: Callback Using Function Pointer
-----------------------------------------------
#include <iostream>
using namespace std;

// Callback function that prints a message
void displayMessage(string msg) 
{
    cout << "Message: " << msg << endl;
}

// Function that accepts a function pointer as a callback
void processData(void (*functionPointer)(string)) 
{
    string data = "Hello, Callback!";
    functionPointer(data);  // Calling the callback function
}

int main() 
{
    processData(displayMessage);  // Passing function as callback
    return 0;
}
-----------------------------------------------------------------------







