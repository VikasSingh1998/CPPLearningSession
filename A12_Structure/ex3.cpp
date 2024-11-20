// Create an array of type struct "Data" and store value in it.
#include <bits/stdc++.h>
using namespace std;
struct Data
{
    string name;
    int age;
};
int main()
{
    Data arr[10]; // create the array of size 10 of "Data" type.
    for (int i = 0; i < 10; i++)
    {
        arr[i].name = ("vikas" + to_string(i));
        arr[i].age = i + 21;
    }

    // now display the content of array.
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i].name << "-" << arr[i].age << endl;
    }
    return 0;
}
