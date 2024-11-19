/*
==> weak_ptr does not put any empact on reference count. No changes in the reference count.
==> it is created as a copy of shared_ptr. First we have to create the shared_ptr then only we can create the weak_ptr from that shared ptr.
==> creation and deletion of weak_ptr from the shared_ptr does not put any impact on shared_ptr.
==> once all the shared_pointer pointing to some location is destroyed, all weak_ptr will be automatically destroyed.
*/
#include <iostream>
#include <memory>

using namespace std;

int main()
{
    shared_ptr<int> p1(new int(10));
    weak_ptr<int> p2;
    p2 = p1;

    cout << "value at p1 is -> " << *p1 << endl;
    // cout<<"value at p2 is -> "<<*p2<<endl;
    cout << "value at p2 is -> " << *(p2.lock()) << endl;
    //----------------------------------
    cout << "Before move:" << endl;
    cout << "p1.use_count(): " << p1.use_count() << endl; // 1
    cout << "p2.use_count(): " << p2.use_count() << endl; // 1
    cout << "p1.get(): " << p1.get() << endl;             // Address of the int

    p2 = move(p1); // move the ownership

    cout << "After move:" << endl;
    cout << "p1.use_count(): " << p1.use_count() << endl; // 0
    cout << "p2.use_count(): " << p2.use_count() << endl; // 1
    cout << "p1.get(): " << p1.get() << endl;             // nullptr
    cout << "p2.get(): " << p2.lock().get() << endl;      // Address of the int

    return 0;
}

