#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//-------------------------
// void printStack(stack<int> s)//not pass by reference.
// {
//     while(!s.empty())
//     {
//         cout<<s.top()<<" ";
//         s.pop();
//     }
//     cout<<endl;
// }
//-------------------------
// creae the template to disply any type of stack.
template <class T>
void printStack(stack<T> s) // not pass by reference.
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
//-------------------------
int main()
{
    stack<int> s; // create an empty stack s.
    for (int i = 0; i < 5; i++)
    {
        s.push(i + 1);
    }
    // now stack contains ==> 1 2 3 4 5
    printStack(s);            // 5 4 3 2 1
    cout << s.size() << endl; // 5
    //-------------------------
    stack<int> s1(s); // create the stack s1 by copying the elements of s.
    printStack(s1);   // 5 4 3 2 1
    // s1.clear(); ==> error, ‘class std::stack’ has no member named ‘clear’
    cout << s1.size() << endl;
    //-------------------------
    stack<int> s2({1, 2, 3}); // create the stack with the given elements.
    printStack(s2);           // 3 2 1
    //-------------------------
    s1.swap(s2);
    printStack(s1); // 3 2 1
    printStack(s2); // 5 4 3 2 1
    //-------------------------
    return 0;
}

