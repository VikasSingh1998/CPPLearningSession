// Thread creation by using the non static member funtion
//==========================================================
#include <iostream>
#include <thread>

class MyClass
{
public:
    // fun is the non static member function.
    void fun(int x)
    {
        int i = 1;
        while (i <= x)
        {
            std::cout << "Child thread executed " << i << " times" << std::endl;
            i++;
        }
    }
};
int main()
{
    // create the instance of MyClass
    MyClass obj;

    // create the thread t1, by passing the address of the function and address of the object on which we have this function.
    std::thread t1(&MyClass::fun, &obj, 10);
    // This line creates a new thread t1 that runs the non-static memberFunction(fun) of the object(obj) instance of MyClass with an argument of 10.
    //  Here we have to give the address of the non-static member funtion and the address of object on which we have to call this non-static member function.

    // This loop will be executed by the main thread
    for (int i = 1; i <= 10; i++)
    {
        std::cout << "Main thread executed " << i << " times." << std::endl;
    }

    // Main thread waits for t1 to finish
    t1.join();

    // Return 0 to indicate successful completion
    return 0;
}
/*
Explanation
=============
1. std::thread t1 ==> this declare a new "std::thread" object named 't1'

2. &MyClass::memberFunction ==> It give the pointer to the memberFunction "memberFunction" of the class "MyClass".
   This pointer indicate which member function will be executed by the thread t1.

3. &obj ==> When invoking a non-static member function, you need to specify which instance of the class the function should be called on.
            This is because non-static member functions operate on specific instances of the class, accessing their member variables and other member functions.
*/
