Function Pointers Using std::function
---------------------------------------
C++11 introduced std::function for type-safe function wrappers, 
making function pointers easier to manage.

✅ Example: Using std::function for Dynamic Function Selection
---------------------------------------------------------------
#include <iostream>
#include <functional>  // Required for std::function
using namespace std;

// Simple arithmetic functions
int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

int main() 
{
    // Declare std::function type
    function<int(int, int)> operation;

    // Assign function dynamically
    operation = add;
    cout << "Addition: " << operation(4, 6) << endl;  // Output: 10

    operation = multiply;
    cout << "Multiplication: " << operation(4, 6) << endl;  // Output: 24

    return 0;
}
===================================================================================
🔹 Why use std::function?
---------------------------
Feature	                                Function Pointer	    std::function
Supports Free Functions	                   ✅                    	✅
Supports Lambda Functions	                 ❌                   	✅
Supports Member Functions	                 ❌	                    ✅
Type Safety	                               ❌	                    ✅
More Flexibility	                         ❌	                    ✅
-----------------------------------------------------------------------------------
std::function	A powerful, type-safe alternative to function pointers with added flexibility.
