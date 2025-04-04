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
    list<int> l;
    for (int i = 0; i < 5; i++)
    {
        l.push_back(i + 1);
    }
    printList(l); // 1 2 3 4 5
    //----------------------------
    list<int> l2(l); // copy all the elements of l to l2
    printList(l2);   // 1 2 3 4 5
    //----------------------------
    l2.insert(l2.begin(), l.begin(), l.end()); // from l,[first,last-1]  elements will be insert before l2.start
    printList(l2);                             // 1 2 3 4 5 1 2 3 4 5
    l2.insert(l2.begin(), 99);                 // from l,[first,last-1]  elements will be insert before l2.start
    printList(l2);                             // 99 1 2 3 4 5 1 2 3 4 5
    //----------------------------
    cout << l2.size() << endl; // 11
    l2.resize(5);              // now in l2 only first 5 elements will be there and other will be removed.
    printList(l2);             // 99 1 2 3 4

    return 0;
}

