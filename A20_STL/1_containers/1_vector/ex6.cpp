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
    // vector<int> v;
    // v.assign(10,5);//assign 10 elements each set to 5
    vector<int> v1(10, 5); // create a vector of size 10 and all elemtnt will be set to 5
    vector<int> v2(10, 3); // create a vector of size 10 and all elemtnt will be set to 5
    dispVector(v1);
    dispVector(v2);

    v1.swap(v1); // v and v1 will be swap
    dispVector(v1);
    dispVector(v2);
    return 0;
}

