#include <bits/stdc++.h>
using namespace std;

struct Address
{
    string city;
    string state;
    int zip;
};
struct Employee
{
    string name;
    int id;
    Address address;
    double sal;
    string dept[5];

    // function to display the employee details
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Id: " << id << endl;
        cout << "Address  of the employee: " << endl;
        cout << "city: " << address.city << endl;
        cout << "State: " << address.state << endl;
        cout << "Zip: " << address.zip << endl;
        cout << "Salary: " << sal << endl;
        cout << "dept are: ";
        for (auto str : dept)
        {
            if (!str.empty())
            {
                cout << str << ",";
            }
        }
        cout << endl;
    }
};
int main()
{
    // Create an Employee instance and initialize data
    Employee emp = {
        "John Doe",
        12345,
        {"New York", "NY", 10001},
        75000.0,
        {"Engineering", "Research", "", "", ""}};

    // Call the display function
    emp.display();

    return 0;
}
