#include <iostream>
#include <memory>
using namespace std;

int fun1()
{
    int *p = new int(10);
    if (10 % 2 == 0)
    {
        return 1;
    }
    // if the condition is true, the this delete p wont be executed and causes memory leak
    // so we have to use smart pointer.
    delete p;
    return 0;
}

int fun2()
{
    unique_ptr<int> p(new int(10));
    if (10 % 2 == 0)
        return 1;
    return 0;
}

int fun3()
{
    unique_ptr<int> p1(new int(10)); // p1 -> some location
    cout << *p1 << endl;             // 10

    unique_ptr<int> p2; // here p2{ptr} will points to NULL
    // p2=p1;//error -> we cant copy the address of one unique_ptr to another unique_ptr .only one owner will be there for one instance.
    // so we have to movce the ownership.
    p2 = move(p1); // now move the ownership from p1 to p2
    // cout<<*p1<<endl;//error -> segmentation fault error
    cout << *p2 << endl; // 10

    if (p1 == nullptr)
    {
        cout << "p1 is not the owner" << endl;
    }
    else
    {
        cout << "p2 is owner" << endl;
    }
    return 0;
}
int main()
{
    // cout<<fun1()<<endl;
    // cout<<fun2()<<endl;
    cout << fun3() << endl;
    return 0;
}
/*
how to create the unique_ptr
1st way
=========
unique_ptr<int> p(new int(10)); ==> while creating the object of unique_ptr, pass the pointer to its constructor.

2nd way
=======
unique_ptr<int> p; //here p will points to NULL
p.reset(new int(10));//now p will point to new address location (this newly create int object 10)

====> here if p was pointing to some object, and we are using reset then first that object memory will be released and then p will
point to some new address
---------------------------
*/
//===========================================================================================================================
/*$$$$$Note$$$$
===> unique_ptr is a container for raw pointer i.e unique_ptr contain a ptr which will point to some object(hold location  of some memory).

===> unique_ptr prevent the copying of its contained pointer ===> it means suppose a p{ptr} means p contained ptr and that ptr is
pointing to some memory location the  --> that memory location can't be pointed by another unique_ptr

means suppose we have created the unique_ptr p and it is pointing to some memory loaction and i want to create another unique_ptr
and want to point to same memory loaction then it is not possible.

===> We cant copy that address to another unique_ptr but we can transfer the ownership to another pointer by using move() function.
Means suppose p1 --> points to some location now make another unique_ptr p2 and move the ownership of that location to p2.
*/

