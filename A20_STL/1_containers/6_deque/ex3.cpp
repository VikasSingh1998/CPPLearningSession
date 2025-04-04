#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//----------------------------
void displayDQ(deque<int> dq)
{
    for (auto it = dq.begin(); it != dq.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
//----------------------------
int main()
{
    deque<int> dq(5, 0); // create the deque of size 5 with all the value set to 0
    displayDQ(dq);       // 0 0 0 0 0
    //----------------------------
    dq.assign({1, 2, 3, 4, 5});
    displayDQ(dq); // 1 2 3 4 5
    //----------------------------
    dq.insert(dq.begin(), {10, 20, 30});
    displayDQ(dq); // 10 20 30 1 2 3 4 5
    //----------------------------
    dq.erase(dq.begin(), dq.begin() + 3); // remove the first dq,dq+1,dq+2 --> first 3 element from the deque
    displayDQ(dq);                        // 1 2 3 4 5
    //----------------------------

    return 0;
}

