//  More complex example of a structure in C++ that includes pointers, dynamic memory allocation, and functions:
#include <bits/stdc++.h>
using namespace std;

struct Project {
    string title;
    double budget;

    Project(string t = "", double b = 0.0) : title(t), budget(b) {}
};

struct Employee {
    string name;
    int id;
    int projectCount;
    Project* projects;

    // Constructor to initialize the employee and allocate dynamic memory for projects
    Employee(string n, int i, int pc) : name(n), id(i), projectCount(pc) {
        projects = new Project[projectCount]; // Dynamically allocate an array of projects
    }

    // Function to assign a project
    void assignProject(int index, const string& title, double budget) {
        if (index < 0 || index >= projectCount) {
            cout << "Invalid project index!" << endl;
            return;
        }
        projects[index] = Project(title, budget);
    }

    // Function to display employee details
    void displayEmployeeDetails() {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << id << endl;
        cout << "Number of Projects: " << projectCount << endl;
        for (int i = 0; i < projectCount; ++i) {
            cout << "  Project " << i + 1 << ": " << projects[i].title 
                 << ", Budget: " << projects[i].budget << endl;
        }
    }

    // Destructor to free allocated memory
    ~Employee() {
        delete[] projects;
    }
};

int main() {
    // Create an employee with 2 projects
    Employee emp("John Doe", 101, 2);

    // Assign projects
    emp.assignProject(0, "Project Alpha", 50000.0);
    emp.assignProject(1, "Project Beta", 75000.0);

    // Display employee details
    emp.displayEmployeeDetails();

    return 0;
}
