#include <bits/stdc++.h>
using namespace std;

//We are creating the custom comp funtion.
bool comp(int a,int b)
{
    return a>b;// Min-heap: lower values have higher priority
}

// Function to display the elements of the priority queue
void display(priority_queue<int,vector<int>,decltype(&comp)> pq)
{
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}

int main()
{
    //Create the MIN-HEAP by using the custom comp funtion
    priority_queue<int,vector<int>,decltype(&comp)> pq(comp);// Pass comp to the constructor
    
    //push 7 random element in the PQ.
    for(int i=0;i<7;i++)
    {
        pq.push(rand()%100);
    }
    display(pq);

    return 0;
}
// 15 35 77 83 86 86 93 
// ==========================================================

