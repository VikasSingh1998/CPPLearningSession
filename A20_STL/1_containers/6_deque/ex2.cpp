#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//----------------------------
void displayDQ(deque<int> dq)
{
    // while(!dq.empty()){
    //     cout<<dq.front()<<" ";
    //     dq.pop_front();
    // }
    // cout<<endl;
    //----------------------------
    for (auto it = dq.begin(); it != dq.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
//----------------------------
int main()
{
    deque<int> dq;
    for (int i = 0; i < 3; i++)
    {
        dq.push_back(i);
    }
    displayDQ(dq); // 0 1 2

    for (int i = 5; i < 8; i++)
    {
        dq.push_front(i);
    }
    displayDQ(dq); // 7 6 5 0 1 2
    //----------------------------
    cout << dq.size() << endl; // 6
    //----------------------------
    dq.assign({1, 2, 3, 4, 5}); // clear all the previous content and insert this content.
    displayDQ(dq);              // 1 2 3 4 5
    //----------------------------
    vector<int> v({10, 20, 30, 40});
    deque<int> dq1(v.begin(), v.end());
    displayDQ(dq1); // 10 20 30 40
    //-----------------------------
    dq.swap(dq1);
    displayDQ(dq);  // 10 20 30 40
    displayDQ(dq1); // 1 2 3 4 5
    //-----------------------------

    return 0;
}

