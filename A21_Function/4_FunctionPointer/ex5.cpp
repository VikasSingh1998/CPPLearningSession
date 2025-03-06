Function Pointers in Classes
=============================
#include <iostream>
using namespace std;

class Calculator 
{
public:
    // Function pointer inside class
    int (Calculator::*functionPointer)(int, int);

    // Member functions
    int add(int a, int b) { return a + b; }
    int multiply(int a, int b) { return a * b; }

    // Function to execute the stored function pointer
    int execute(int a, int b) 
    {
        return (this->*functionPointer)(a, b); // Dereferencing member function pointer
    }
};

int main() 
{
    Calculator calc;

    // Assign the function pointer to 'add' method
    calc.functionPointer = &Calculator::add;
    cout << "Addition: " << calc.execute(4, 5) << endl;  // Output: 9

    // Assign the function pointer to 'multiply' method
    calc.functionPointer = &Calculator::multiply;
    cout << "Multiplication: " << calc.execute(4, 5) << endl;  // Output: 20

    return 0;
}
-------------------------------------------------------------------------------

