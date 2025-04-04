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
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i + 1);
    }
    dispVector(v);                // 1 2 3 4 5 6 7 8 9 10
    cout << v.size() << endl;     // 10
    v.resize(5);                  // only the first five elements will be there in the vector.
    dispVector(v);                // 1 2 3 4 5
    cout << v.max_size() << endl; // 2305843009213693951, this give the max number of elements which we can push into the vector.
    return 0;
}

