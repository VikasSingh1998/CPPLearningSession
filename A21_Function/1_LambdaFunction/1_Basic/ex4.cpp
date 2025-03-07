5. Using Lambda in std::function
=-----------------------------------
#include <iostream>
#include <functional>  // Required for std::function
using namespace std;

int main() {
    function<int(int, int)> multiply = [](int a, int b) { return a * b; };
    cout << "Product: " << multiply(4, 5) << endl;
    return 0;
}
💡 Why std::function?

It allows storing lambdas and function pointers in a flexible way.
-----------------------------------------------------------------------------
6. Mutable Lambda (Modify Captured Variables)
---------------------------------------------
#include <iostream>
using namespace std;

int main() {
    int count = 0;

    auto increment = [count]() mutable -> void  
    { 
        count++; 
        cout << "Count: " << count << endl; 
    };
    
    increment();
    increment();

    cout << "Outside Lambda, Count: " << count << endl; // Remains 0
    return 0;
}
/*
Count: 1
Count: 2
Outside Lambda, Count: 0
*/
💡 Why mutable?
Captured variables (by value) cannot be modified inside the lambda unless mutable is used.
==================================================================================



















