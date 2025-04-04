#include <iostream>
#include <list>
using namespace std;

int main()
{
    // Creating a list of integers
    list<int> l;

    // Adding elements to the list
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    // Accessing elements using iterators
    cout << "List elements: ";
    for (auto it = l.begin(); it != l.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Using range-based for loop (C++11 and later)
    cout << "List elements (range-based for loop): ";
    for (int num : l)
    {
        cout << num << " ";
    }
    cout << endl;

    // Checking if the list is empty
    if (l.empty())
    {
        cout << "List is empty." << endl;
    }
    else
    {
        cout << "List size: " << l.size() << endl;
    }

    // Inserting an element at the beginning
    l.push_front(5);

    // Removing an element from the end
    l.pop_back();

    // Removing an element from the beginning
    l.pop_front();

    // Removing a specific element from the list
    l.remove(20);

    // Printing the modified list
    cout << "Modified list elements: ";
    for (int num : l)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

