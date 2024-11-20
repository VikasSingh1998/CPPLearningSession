#include <iostream>
#include <memory>
using namespace std;
int main()
{
    shared_ptr<int> p1(new int(10));
    weak_ptr<int> p2;
    p2 = p1;

    cout << p1.use_count() << endl; // 1
    cout << p2.use_count() << endl; // 1

    cout << p1.get() << endl;
    cout << p2.lock().get() << endl; /// these both will give the same location

    p1.reset();
    cout << p1.use_count() << endl; // 0
    cout << p2.use_count() << endl; // 0,
    // beacuse p2 is weak pointer, it if we will reset the p1 ,
    // it will become nullptr and use_count will be reduced and that address will be freed if use_count is 0.

    return 0;
}

