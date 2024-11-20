//  More complex example of a structure in C++ that includes pointers, dynamic memory allocation, and functions:
#include <bits/stdc++.h>
using namespace std;

struct Project
{
    string title;
    double budget;
};

struct Employee
{
    string name;
    int id;
    int projectCount;
    Project *project;

    Employee(string n, int i, int pc)
    {
        name = n;
        id = i;
        projectCount = pc;

        // create the array of size pc
    }
};

