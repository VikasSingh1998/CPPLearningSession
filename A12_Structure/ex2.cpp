#include <bits/stdc++.h>
using namespace std;

struct Person
{
    string name;
    string mob;
    string add;
} p1;

int main()
{
    p1.name = "vikas";
    p1.mob = "123";
    p1.add = "rajpur";

    // Structure members are accessed using dot (.) operator.
    cout << p1.name << endl;
    cout << p1.mob << endl;
    cout << p1.add << endl;

    // we can assign the value to struct object at the time when
    // we are cerating the strcture object.
    // Structure members can also be initialized using curly braces ‘{}’.
    struct Person p2 = {"ravi", "12321", "rajpur"};
    cout << p2.name << endl;
    cout << p2.mob << endl;
    cout << p2.add << endl;

    return 0;
}
