// If we create the multiple thereds ==> we don't know which one will run first.(Order is not gurantee)
//--------------
// Thread Creation By using the function pointer
//==================================================
#include <iostream>

// this function will be run by the thread.
void fun(int x)
{
    int i = 1;
    while (i <= x)
    {
        std::cout << "child thread executed " << i << " time." << std::endl;
        i++;
    }
}
int main()
{
    // main thread create the child thread t1 that run the funtion "fun" with an argumnet of 10
    // 'fun' is used as a function pointer here
    std::thread t1(fun, 10);
    // std::thread t2(fun, 10); // this thread may be create before the thread t1 by the main thread.

    // this loop will be executed by the main thread.
    for (int i = 1; i <= 10; i++)
    {
        std::cout << "main thread executed " << i << " time." << std::endl;
    }

    t1.join(); // main thread will execue this line, so main thread will wait till t1 complete its execution.
    return 0;  // return 0 to indicate the successfull exection.
}
/*
1. In C++, you can create threads using the std::thread class.
2. A thread can be created by passing a function pointer along with its arguments to the std::thread constructor.
3. Here, the function fun is used as a function pointer to create the thread.

4. std::thread t1(fun, 10);: The main thread creates a new thread t1 that runs the fun function with 10 as its argument.
5. t1.join();: The main thread waits for the child thread t1 to finish executing the fun function before proceeding.
*/
// output
// Here the output order is not guaranted. It may be in any order.
