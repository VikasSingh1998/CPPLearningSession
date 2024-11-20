// Structure Pointer ==>
// We can have pointer to the structure.
// If we have pointer to the structure then member are accessed by using -> operator insted of . operator.
//=======================================================
#include <bits/stdc++.h>
using namespace std;
struct Data
{
    string name;
    int age;
};
int main()
{
    Data d1 = {"vikas", 24};
    cout << d1.name << "-" << d1.age << endl;

    Data *p = &d1; // pointer p holds the address of d1
    cout << p->name << "==" << p->age << endl;
    return 0;
}
