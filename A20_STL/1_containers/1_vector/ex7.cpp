#include <iostream>
#include <vector>
using namespace std;

void dispVector(const vector<int> &v)
{
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> v1; // create an empty vector of size and capacity 0
    // v1[0]=10;//error
    v1.push_back(10);
    cout << v1[0] << endl;

    vector<int> v2(v1); // create a vector v2 by copying all the elements of the v1
    dispVector(v2);
    return 0;
}

