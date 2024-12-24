#include <bits/stdc++.h>
using namespace std;

struct Student
{
    int rollNo;
    string name;
};

//We are creating the custom comp funtion.
bool studentComp(const Student& s1,const Student& s2)//pass by reference
{
    return s1.rollNo>s2.rollNo;// Min-heap: lower values have higher priority
}

// Function to display the elements of the priority queue
void display(priority_queue<Student,vector<Student>,decltype(&studentComp)> pq)
{
    while(!pq.empty())
    {
        // In C++, the pq.top() function in a std::priority_queue does not return an iterator
        // it returns the value of the top element in the priority queue.
        Student s=pq.top();
        cout<<s.rollNo<<"--"<<s.name<<endl;
        pq.pop();
    }
    cout<<endl;
}

int main()
{
    //We will create a Min-heap which will store the student data.
    priority_queue<Student,vector<Student>,decltype(&studentComp)> pq(studentComp);
    //pq(studentComp) ==> Initializes the priority queue with the custom comparison function.
    
    //push 7 random element in the PQ.
    for(int i=0;i<7;i++)
    {
        Student s;
        s.name = "vikas"+to_string(i);
        s.rollNo = rand()%100;
        pq.push(s);
    }
    display(pq);

    return 0;
}
/*
15--vikas3
35--vikas5
77--vikas2
83--vikas0
86--vikas1
86--vikas6
93--vikas4
*/
// std::priority_queue does not support iterators.
/*
Why Use decltype(&comp)? --> To pass the correct function pointer type to the std::priority_queue.
-----------------------------
When defining a std::priority_queue with a custom comparator, 
you need to specify the comparator's type. 

If you use decltype(&comp), it ensures the correct function pointer type 
is automatically deduced, avoiding manual errors.
*/
//====================================================
/*
std::priority_queue requires a callable object, such as a function object (functor), 
a lambda function, or a function pointer, as its custom comparator.
*/
