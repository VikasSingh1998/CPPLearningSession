/*what is the mutex?
----------------------
==> Mutex is used to avoid the race conditions by ensuring that only one thread can access a shared resource at a time.
==> we use the lock() and unlock() function on mutex to avoid the reace condition.
=============================================================================================================================
What is a race condition?
--------------------------
A race condition occurs when two or more threads access shared data concurrently, and the outcome depends on the timing of their execution.
This can lead to unpredictable results and bugs.
=============================================================================================================================
How to solve a race condition?
------------------------------
Use synchronization mechanisms like mutexes to control access to shared resources.
Lock the mutex before accessing the shared resource and unlock it after the access is complete.
=============================================================================================================================
What is a critical section?
------------------------------
A critical section is a portion of code that accesses a shared resource and must not be concurrently accessed by more than one thread.
Mutexes are used to protect critical sections.
*/
// =============================================================================================================================
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int myAmount = 0; // Shared resource
std::mutex m;     // Mutex to protect the shared resource

void addMoney()
{
    m.lock(); // Lock the mutex before entering the critical section
    // Critical Section
    myAmount++; // Increment the shared resource
    m.unlock(); // Unlock the mutex after leaving the critical section
}

int main()
{
    // Create two threads that execute the addMoney function
    std::thread t1(addMoney);
    std::thread t2(addMoney);

    // Threads may start at the same time and try to update myAmount simultaneously
    // This could lead to a race condition without proper synchronization

    // Wait for both threads to finish execution
    t1.join();
    t2.join();

    // Output the final value of myAmount
    // With mutex protection, myAmount should be 2 as both threads increment it once
    cout << myAmount << endl;

    return 0;
}
//====================================================================================
/*
Mutex: Ensures only one thread accesses the critical section at a time.
Race Condition: Occurs when multiple threads access shared data simultaneously leading to unpredictable results.
Solve Race Condition: Use mutex to synchronize access.
Critical Section: Code block accessing shared resource that must not be executed by more than one thread at a time.
*/
