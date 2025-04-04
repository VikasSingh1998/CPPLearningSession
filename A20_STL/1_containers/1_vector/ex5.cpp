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
    vector<int> v(10);
    cout << v.capacity() << endl; // 10
    cout << v.size() << endl;     // 10

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i + 1);
    }
    cout << v.capacity() << endl; // 20
    cout << v.size() << endl;     // 20

    dispVector(v);
    return 0;
}

