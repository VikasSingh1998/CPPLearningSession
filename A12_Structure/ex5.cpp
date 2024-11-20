#include <bits/stdc++.h>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
    void Area()
    {
        cout << "Area of rectangle: " << (length * breadth) << endl;
    }
};

int main()
{
    Rectangle rec = Rectangle{10, 5};
    // The instance of the structure is known as "Structure variable".
    // The instance of the class is known as "Object of the class".
    // Using uniform initialization
    // Rectangle rec{10, 5}; ==> this also works
    rec.Area();
    return 0;
}
/*
Rectangle rec{10, 5};
This syntax is called uniform initialization or list initialization, and it allows you to initialize an object in a consistent way. It works with classes, structs, and other data types.

Why it works:
Rectangle rec{10, 5}; invokes the constructor of Rectangle with 10 and 5 as arguments.
Uniform initialization is a safer and clearer way to initialize objects, preventing some common issues like narrowing conversions.

*/
