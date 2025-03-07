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
