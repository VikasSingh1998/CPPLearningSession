/*
detach()
==========
1. detach() is used to detach the newly created thread from the parent thread.
2. Before deatching the thread --> we should always check whether the thared is joinable  or not.
   If it is joinable then only it can be detached --> else program will be terminated.
   i.e double detach() will result into the program termination.

3. If we have detached thread and main thread function is returning --> then the detached thread execution is suspended.
-------------------------
we should always write detach() or join() on the thread object, otherwise during the thared object distructor, program will be terminated.
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
        // Sleep for a short duration to simulate work being done by the child thread
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main()
{
    // Create a thread (t1) that runs the function 'fun' with an argument of 10
    std::thread t1(fun, 10);

    // Detach the child thread from the parent thread
    // This allows t1 to run independently from the main thread
    t1.detach();

    // Main thread loop: Perform some work in the main thread
    for (int i = 1; i <= 10; i++)
    {
        std::cout << "Main thread executed " << i << " times." << std::endl;
        // Sleep for a short duration to simulate work being done by the main thread
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    // Check if t1 is joinable (it shouldn't be since it's detached)
    // Joining a non-joinable thread will result in a runtime error, so always check
    if (t1.joinable())
    {
        t1.join(); // Main thread waits for t1 to finish
    }
    else
    {
        std::cout << "Thread t1 is not joinable (already detached or finished)" << std::endl;
    }

    // Return 0 to indicate successful completion of the program
    return 0;
}
