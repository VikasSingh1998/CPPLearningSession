#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Person
{
    string name;
    int age;
};
typedef vector<Person> personList;

int main()
{
    personList persons; // Create an instance of vector<Person>

    // Add 5 default Person objects to the vector
    for (int i = 0; i < 5; i++)
    {
        persons.push_back(Person{"vikas" + to_string(i), i + 20}); // Add a default Person with empty name and age 0
    }

    // Optionally, print the persons to verify
    for (const auto &person : persons)
    {
        cout << "Name: " << person.name << ", Age: " << person.age << endl;
    }
    return 0;
}
/*
Name: vikas0, Age: 20
Name: vikas1, Age: 21
Name: vikas2, Age: 22
Name: vikas3, Age: 23
Name: vikas4, Age: 24
*/

