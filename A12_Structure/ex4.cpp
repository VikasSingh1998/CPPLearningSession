#include <bits/stdc++.h>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    // Rectangle rec;
    // rec.length = 10;
    // rec.breadth = 5;
    Rectangle rec = {10, 5};
    cout << "Area of rectangle: " << (rec.length * rec.breadth) << endl;
    return 0;
}
