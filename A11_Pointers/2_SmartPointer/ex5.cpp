/*
==> A shared pointer is a container for raw pointer.
==> Here, more than one shared_ptr can point to one memory location.
==> Here it maintain the reference count for that address ==> to count how many shared_ptr are pointing to that address.
==> that address will only be freed when no shared_ptr will point to that address.
==>
*/

#include <iostream>
#include <memory>
using namespace std;
int main()
{
    shared_ptr<int> p1(new int(10)); // smart pointers are object, so p1 is pointing to int type object.
    shared_ptr<int> p2;
    p2 = p1; // it is not moving the ownership now both are owner of same location.

    cout << p1.use_count() << endl; // 2
    cout << p2.use_count() << endl; // 2

    if (p1.get() == p2.get())
    {
        cout << "both p1 and p2 are pointing to the same object" << endl;
    }

    p2 = move(p1); // here p1 will set to nullptr and only p2 will be the owner of the location.
    if (p1 == nullptr)
        cout << "p1 is nullptr" << endl;

    cout << p1.use_count() << endl; // 0
    cout << p2.use_count() << endl; // 1 ,only p2 is pointing to that memory location.
    shared_ptr<int> p3(p2);
    cout << p3.use_count() << endl; // 2 ,now p2 and p3 is pointing to that memory location.

    p2.reset();                     // now p2 will not point to that location.
    cout << p1.use_count() << endl; // 0
    cout << p2.use_count() << endl; // 0
    cout << p3.use_count() << endl; // 1

    return 0;
}
