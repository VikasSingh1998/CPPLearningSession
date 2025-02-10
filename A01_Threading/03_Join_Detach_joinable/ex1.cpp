/*
t1.join()
===============
1. Suppose  main thread created the thread t1 and and t1 is doing some operations.
2. If Main thread executes the lines --> t1.join() , then main thread wait until t1 completes its executions.

t1.joinable()
=================
The t1.joinable() function checks whether a thread object t1 is associated with a
thread of execution. If the thread is joinable, it returns true, otherwise, it returns false.
A thread is joinable if it has been started and has not yet been joined or detached.
*/

#include <iostream>
#include <chrono>
#include <thread>

// Function to be executed by the child thread
void fun(int x)
{
    for (int i = 1; i <= x; i++)
    {
        std::cout << "Child thread executed " << i << " times" << std::endl;
    }
    // Simulate some work with a sleep
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

int main()
{
    // Create a thread (t1) that runs the function 'fun' with an argument of 10
    std::thread t1(fun, 10);

    // Main thread loop
    for (int i = 1; i <= 10; i++)
    {
        std::cout << "Main thread executed " << i << " times." << std::endl;
    }

    // Main thread waits for t1 to finish
    t1.join();

    // t1.join();//double join result into the program termination.
    /*
    terminate called after throwing an instance of 'std::system_error'
    what():  Invalid argument
    -----------------
    TO solve this problem ==> we can check whether the thread is joinable or not.
    */
    // Check if the thread is joinable before attempting to join
    if (t1.joinable())
    {
        t1.join(); // Main thread waits for t1 to finish
    }
    else
    {
        std::cout << "thread t1 is not joinable " << std::endl;
    }

    // Return 0 to indicate successful completion
    return 0;
}
