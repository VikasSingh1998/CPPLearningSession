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
    rec.Area();
    return 0;
}
