#include <iostream>
#include <cstdlib>
#include <time.h>
#include <bits/stdc++.h>
using namespace std;
//-------------------------
void displayPQ(priority_queue<int> pq)
{
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}
//-------------------------
int main()
{
    priority_queue<int> pq; // maxHeap
    srand(time(0));
    for (int i = 0; i < 5; i++)
    {
        pq.push((rand() % 100) + 1); // generate random number between 0 to 99 and add 1 to make [0,100]
    }
    displayPQ(pq);
    return 0;
}

