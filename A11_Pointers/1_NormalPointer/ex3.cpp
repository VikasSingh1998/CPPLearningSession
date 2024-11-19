// C++ program to demonstrate working of a Pointers
// Problems with Normal Pointers

#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;
};

void fun()
{
    // By taking a pointer p and dynamically
    // creating object of class rectangle.
    Rectangle *p = new Rectangle();
    //p is a pointer which will hold the address of obj of type Rectangle
}

int main()
{
    // Infinite Loop
    while (1)
    {
        fun();
    }
}
// output ==> Memory limit exceeded
/*
PS D:\Learning_Session\CPPLearningSession\A11_Pointers\normal_pointer\output> & .\'e13_momoryLeak.exe'
terminate called recursively
*/
// ====================================
/*
Explanation:
In function fun, it creates a pointer that is pointing to the Rectangle object.
The object Rectangle contains two integers, length, and breadth.
When the function fun ends, p will be destroyed as it is a local variable.
But, the memory it consumed won’t be deallocated because we forgot to use delete p; at the end of the function.
That means the memory won’t be free to be used by other resources.
But, we don’t need the variable anymore, we need the memory.

In function, main, fun is called in an infinite loop. That means it’ll keep creating p.
It’ll allocate more and more memory but won’t free them as we didn’t deallocate it.
The memory that’s wasted can’t be used again. Which is a memory leak.
The entire heap memory may become useless for this reason.
*/

