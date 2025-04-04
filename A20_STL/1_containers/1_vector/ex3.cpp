#include <iostream>
#include <vector>
using namespace std;

void dispVector(const vector<int> &v)
{
    // v.push_back(4); ==> if we will not give the const --> we can change the v content inside this function.
    // so whenever we want that that some value shuld not be change inside some method --> we should declare it as const.
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}
int main()
{
    // Creating a vector of integers
    vector<int> v;

    // Adding elements to the vector
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    //==================================================================
    // v.insert(iterator location, value) ==> insert the value at the given location
    // v.insert(iterator location, int no_of_time, value )=> insert the value, no_of_time before the location.
    // v.insert(iterator location, iterator start, iterator end) ==> inser elements from [start,end-1] of another collection before the location
    v.insert(v.begin(), 10);
    cout << v[0] << endl;       // 10
    v.insert(v.begin(), 3, 20); // insert 20, 3 times before the v.begin()
    cout << v[0] << endl;       // 20
    dispVector(v);              // 20 20 20 10 1 2 3

    vector<int> v1;
    v1.insert(v1.begin(), v.begin() + 3, v.end() - 1); // 10 1 2 will be inserted.
    dispVector(v1);                                    // 10 1 2
    return 0;
}

