#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Creating a vector of integers
    vector<int> v;

    // Adding elements to the vector
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << "v.front() give the first element of vector: " << v.front() << endl;
    cout << "v.back() give the first element of vector: " << v.back() << endl;

    // Accessing elements using index
    cout << "First element: " << v[0] << endl;
    cout << "Second element: " << v[2] << endl;
    cout << "last element: " << v.at(v.size() - 1) << endl;
    // by using the index -> we can access the elements outside the index Ex v[5]and it will not give any error.
    // by using the at(index)=> it we will try to access the elements outside the vector it will give error => v.at(v.size())=> error

    //---------------------------------------------------------------------------------------
    // Iterating through the vector using iterators
    // vector has both ==> forward iterator and reverse iterator
    // forward iterator ==> begin() anb end()
    // reverse iterator ==> rbegin() and rend()
    cout << "Vector elements- By using the iterators : ";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Using range-based for loop (C++11 and later)
    cout << "Vector elements (range-based for loop): ";
    for (int num : v)
    {
        cout << num << " ";
    }
    cout << endl;

    //---------------------------------------------------------------
    // Checking if the vector is empty
    if (v.empty())
    {
        cout << "Vector is empty." << endl;
    }
    else
    {
        cout << "Vector size: " << v.size() << endl;
    }

    // Clearing the vector
    v.clear(); // delete all the elements of the vector

    // Checking if the vector is empty after clearing
    if (v.empty())
    {
        cout << "Vector is empty after clearing." << endl;
    }

    return 0;
}

