#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//-------------------------
template <class T>
void printQueue(queue<T> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
//-------------------------
int main()
{
    queue<int> q;
    for (int i = 0; i < 5; i++)
    {
        q.push(i + 1);
    }
    cout << q.size() << endl; // 5
    printQueue(q);            // 1 2 3 4 5

    return 0;
}

