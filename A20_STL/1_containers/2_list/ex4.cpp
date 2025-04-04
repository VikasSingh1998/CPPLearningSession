#include <iostream>
#include <list>
using namespace std;

void printList(list<int> &l)
{
    // we cant use index to access the elements of the list.
    //----------------------------
    //  for(auto e:l){
    //      cout<<e<<" ";
    //  }
    //----------------------------
    for (auto it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
int main()
{
    // Creating a list of integers
    list<int> l(10, 4);
    printList(l); // 4, 10 times

    l.assign(10, 0); // 10 time 0 will be assgned and old value of the list will be removed.
    printList(l);    // 0, 10 times
    //=================================
    // l2.swap(l1); ==> to swap the 2 list.
    list<int> l1(5, 1);
    list<int> l2(5, 2);
    printList(l1); // 1, 5 times
    printList(l2); // 2, 5 times
    l2.swap(l1);
    printList(l1); // 2, 5 times
    printList(l2); // 1, 5 times

    return 0;
}

