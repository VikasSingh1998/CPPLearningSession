// sort the student according to marks and if the marks is equal then on greater roll number should come first.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Student
{
private:
    int roll;
    int marks;
    string name;

public:
    Student(int roll, string name, int marks)
    {
        this->roll = roll;
        this->marks = marks;
        this->name = name;
    }

    int getRoll() const { return roll; }
    int getMarks() const { return marks; }
    string getName() const { return name; }
};

class Compare
{
public:
    bool operator()(const Student &s1, const Student &s2) const
    {
        if (s1.getMarks() != s2.getMarks())
        {
            return s1.getMarks() < s2.getMarks(); // Sort by marks in ascending order
        }
        else
        {
            return s1.getRoll() > s2.getRoll(); // If marks are equal, sort by roll number in descending order
        }
    }
};

void displayPQ(priority_queue<Student, vector<Student>, Compare> pq)
{
    while (!pq.empty())
    {
        cout << "current student data:" << endl;
        Student s = pq.top();
        pq.pop();
        cout << "Roll is: " << s.getRoll() << endl;
        cout << "Name is: " << s.getName() << endl;
        cout << "marks is: " << s.getMarks() << endl;
        cout << endl;
    }
    cout << endl;
}

int main()
{
    priority_queue<Student, vector<Student>, Compare> pq; // My own comparator function.
    // we have to give 3 things.
    // datatype==> which datatype  we have to store.
    // container ==> where we will store this datatype
    // comparator class ==> greater is template so, greater<int> is class.

    for (int i = 0; i < 5; i++)
    {
        pq.push(Student(i + 1, "vikas" + to_string(i), i + 60));
    }
    displayPQ(pq);
    return 0;
}

