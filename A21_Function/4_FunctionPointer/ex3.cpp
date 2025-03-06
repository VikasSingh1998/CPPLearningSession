🔹 Example 4: Array of Function Pointers (Menu Selection)
This example demonstrates how function pointers can be used in an array for dynamic function selection.
-------------------------------------------------------------------------------------------------------
Code:
----------------------
#include <iostream>
using namespace std;

// Functions
void option1() 
{
    cout << "You selected Option 1!" << endl;
}

void option2() 
{
    cout << "You selected Option 2!" << endl;
}

void option3() 
{
    cout << "You selected Option 3!" << endl;
}

int main() 
{
    // Array of function pointers
    void (*menuOptions[])() = {option1, option2, option3};

    int choice;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    // Validate choice and call the corresponding function
    if (choice >= 1 && choice <= 3) 
    {
        menuOptions[choice - 1](); // Calls the appropriate function
    } 
    else 
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
/*
Output:
--------
Enter your choice (1-3): 3
You selected Option 3!
*/
------------------------------------------------------------------------------------------------------------
Notes:
-------
Basic Function Pointer	====> Stores address of a function and calls it dynamically.
Function Pointer with Parameters	=====> Can store functions that take arguments.
Function Pointer as Callback	=====> A function pointer can be passed as an argument to another function.
Array of Function Pointers	=====> Used for dynamically selecting and calling functions, useful for menus.
------------------------------------------------------------------------------------------------------------

