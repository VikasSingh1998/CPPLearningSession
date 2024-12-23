#include <bits/stdc++.h>
using namespace std;

void display(priority_queue<int> pq)
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
    //By default this will be the MAX-HEAP
    priority_queue<int> pq1;
    for(int i=0;i<7;i++)
    {
        pq1.push(rand()%100);
    }
    display(pq1);

    return 0;
}
//PQ ==> By default MAX-HEAP
// 93 86 86 83 77 35 15 


