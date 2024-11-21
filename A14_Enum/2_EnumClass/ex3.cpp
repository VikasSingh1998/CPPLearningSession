#include <bits/stdc++.h>
#include <iostream>
using namespace std;

enum class days
{
    monday,
    tuesday,
    wednesday,
    thursday = 10,
    friday,
    saturday
};
enum class daysList2
{
    monday, // no conflict with the previous namespace
    tuesday,
    wed
};
int main()
{
    // cout << days::friday << endl; // Error
    /*
    Your code will not compile because the enum class values cannot be directly used in cout.
    The reason is that enum class values are strongly typed and not implicitly convertible to integers,
    so cout doesn't know how to print them.
    To fix this, you need to explicitly cast the enum class value to its underlying type, which is usually int by default.
    */

    cout << static_cast<int>(days::monday) << endl;    // 0
    cout << static_cast<int>(days::wednesday) << endl; // 2
    cout << static_cast<int>(days::thursday) << endl;  // 10

    return 0;
}
