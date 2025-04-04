#include <iostream>
#include <list>
using namespace std;

int main()
{
    // list is implement as linkedlist(DLL)
    // compared to vector --> fast insertion and deletion is possible
    // But random access is slower comapred to vector.

    // list<int> l;//create an empty list
    // list<int> l(5);//create an list of size 5 with random value, similar to vector
    // list<int> l(10,5);//create an list of size 10 with all value set to 5

    // list<int> l(it1,it2);//copy all the elements between these 2 iterators
    // list<int> l(v.begin(),v.end());

    // cout<<l.front()<<endl;//give the front element of the list
    // cout<<l.back()<<endl;//give the last element of the list
    //--------------------------------
    // iterator begin() ==> return the iterator to first element of the list
    // iterator end() ==> return the iterator to next to last element of the list(last ka next)

    // list<int> l(10,5);
    // for(auto it=l.begin();it!=l.end();it++)
    // {
    //     cout<<*it<<" ";
    // }
    // cout<<endl;
    //--------------------------------
    // reverse iterator
    // iterator rbegin() ==> return the iterator to last element of the list
    // iterator rend() ==> return the iterator to -1 index of the list

    // list<int> l(10,5);
    // for(auto it=l.rbegin();it!=l.rend();it++)
    // {
    //     cout<<*it<<" ";
    // }
    // cout<<endl;
    //---------------------------------
    // clear(), empty(), erase() ==> works simmilar to vector
    // void push_back(val);==> push the value to end of the list
    // void pop_back(); ==> pop the value from last of the list

    // void push_front(val) ==> push the value to start of the list.
    // void pop_front() ==> remove the 1st value of the list.
    //----------------------------------
    //  insert(iterator it, value) ==> insert the value at the given location.
    //  insert(iterator it, no_of_times, value) ==> before the it(location) value will be inserted given number of it.
    //  insert(iterator it, iterator start, iterator end) ==> start and end are the iterator of another list or vector so from [start,end-1] will be inserted before the given location.
    //-----------------------------------

    return 0;
}

