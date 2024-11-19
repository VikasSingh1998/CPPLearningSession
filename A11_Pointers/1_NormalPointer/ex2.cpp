#include <iostream>
using namespace std;

int main()
{
    int number = 42;   // Declare an integer variable and initialize it to 42
    int &ref = number; // Declare a reference variable 'ref' that refers to 'number'

    // A reference is essentially an alias for another variable.
    // After the reference is established, any operation on 'ref' is actually performed on 'number'.

    // Output the value of the original variable 'number'
    cout << "Value of number: " << number << endl;

    // Output the memory address of 'number' using the address-of operator (&)
    cout << "Address of number: " << &number << endl;

    // Output the value of 'number' via the reference 'ref'
    // Since 'ref' is a reference to 'number', this will print the same value as 'number'
    cout << "Value via reference: " << ref << endl;

    return 0;
}
/*
Explanation of Key Points:
==========================
Reference Variable:
--------------------
The line int &ref = number; creates a reference variable ref that refers to number.
A reference is simply an alias for another variable. Once a reference is established,
any changes made to the reference will directly affect the original variable.
*/

