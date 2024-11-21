#include <bits/stdc++.h>
#include <iostream>
using namespace std;

enum data1
{
    val0,
    val1,
    val2,
    val3,
    val4
};
enum data2
{
    val0, // Error --> redeclaration of val0
    val1, // Error --> redeclaration of val1
    val2, // Error --> redeclaration of val2
};
int main()
{
    cout << "hello" << endl;
    cout << data1::val0 << endl;
    return 0;
}
// This problem is not there in the enum class.
// since each enumerator will be locally maintained, not at global enum level.
