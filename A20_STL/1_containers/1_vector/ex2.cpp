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

    //===================================================================
    // v.erase(iterator location) => remove the element at given location
    // v.erase(iterator begin,iterator end) => remove the element between these iterators

    // while(!v.empty())
    // {
    //     cout<<v.front()<<endl;
    //     v.erase(v.begin());
    // }

    // v.erase(v.begin());
    // v.erase(v.begin(),v.end());//v.end() -> point next to last elements
    //=====================================================================
    cout << v.size() << endl;
    // void pop_back() ==> remove the last element of the vector
    v.pop_back(); // remove the last element of the vector
    cout << v.size() << endl;

    return 0;
}

