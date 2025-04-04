#include <iostream>
#include <cstdlib>
#include <time.h>
#include <bits/stdc++.h>
using namespace std;
//-------------------------

class Compare
{
public:
    bool operator()(int a, int b) // same datatype which we are storing in the PQ.
    {
        // return a>b;
        // How to link-->
        // for any 2 value, this shuld be true ==>In memory --> 10 9 8 5 3(front),while taking out it will come in ascending order.SO minHeap
        // take any 2 value--> let say 9(a) and 3(b) --> then 9>3 is true.
        //-------------------------
        return a < b; //==> in memory==>1 2 3 4(front),max on front ==> so maxHeap
    }
};
//-------------------------
void displayPQ(priority_queue<int, vector<int>, Compare> pq)
{
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}
//----------------------------
int main()
{
    priority_queue<int, vector<int>, Compare> pq; // My own comparator function.
    // we have to give 3 things.
    // datatype==> which datatype  we have to store.
    // container ==> where we will store this datatype
    // comparator class ==> greater is template so, greater<int> is class.

    srand(time(0));
    for (int i = 0; i < 5; i++)
    {
        pq.push((rand() % 100) + 1); // generate random number between 0 to 99 and add 1 to make [0,100]
    }
    displayPQ(pq);
    return 0;
}

