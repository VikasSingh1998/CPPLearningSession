#include <bits/stdc++.h>
#include <iostream>
using namespace std;

enum days
{
    monday, // default value is 0
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday
};
int main()
{
    cout << days::friday << endl;//4 
    return 0;
}
