✅ Example: Using Function Pointers Inside a Struct
-------------------------------------------------------
Code:
------
#include <iostream>
using namespace std;

// Define a struct with a function pointer
struct MathOperations 
{
    int (*functionPointer)(int, int); // Function pointer inside struct
};

// Simple addition function
int add(int a, int b) 
{
    return a + b;
}

// Simple subtraction function
int subtract(int a, int b) 
{
    return a - b;
}

int main() 
{
    MathOperations math;  // Create a struct object

    // Assign function pointers dynamically
    math.functionPointer = add;
    cout << "Addition: " << math.functionPointer(5, 3) << endl;  // Output: 8

    math.functionPointer = subtract;
    cout << "Subtraction: " << math.functionPointer(5, 3) << endl;  // Output: 2

    return 0;
}
---------------------------------------------------------------------------------------------------------
🔹 Explanation
The struct MathOperations contains a function pointer "functionPointer" that can hold different functions.
We assign "add" and "subtract" to math.functionPointer, allowing dynamic function selection at runtime.
-----------------------------------------------------------------------------------------------------------

