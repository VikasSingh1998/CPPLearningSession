/*
try_lock()
------------
=> try_lock() try to lock the mutex and return immediately either success or fail.
=> On successful lock acquisition it return true else false.
=> If try_lock() is not able to lock the mutex, then it does not get blocked, that's why it is called non-blocking.
=> If try_lock() is called by the same thread which own the mutex, the behaviour is undefined. It is a dead-lock situation with undefined thared.
=> If we have to lock the same mutex by some thread more than one time, then we go for the recursive mutex.
//================================================================================================================================
m.lock() ==> it is a blocking call, means if one thread is in the critical section and if the other thread try to lock then it will be blocked and can't do the other operations.
m.try_lock() ==> it is non-blocking call, means thread try to lock, if it is alredy locked then it will not be locked and that thread can perform other operations.
*/
//================================================================================================================================
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int count = 0; // Shared resource
std::mutex m;  // Mutex to protect the shared resource

// Function that increments the count variable 1,000,000 times
void incrementCountBy1000000Times()
{
    for (int i = 0; i < 1000000; i++) // Loop to increment count 1,000,000 times
    {
        // Try to lock the mutex
        if (m.try_lock()) // Non-blocking call; returns true if lock is acquired, false otherwise
        {
            count++;    // Critical Section: Increment the shared resource
            m.unlock(); // Unlock the mutex after modifying the shared resource
        }
        // If try_lock() fails (mutex is already locked by another thread), the loop continues
        // without incrementing the count and does not get blocked
    }
}

int main()
{
    // Create two threads that execute the incrementCountBy1000000Times function
    std::thread t1(incrementCountBy1000000Times);
    std::thread t2(incrementCountBy1000000Times);

    // Threads may start at the same time and try to update count simultaneously
    // Without proper synchronization, this could lead to a race condition

    // Wait for both threads to finish execution
    t1.join();
    t2.join();

    // Output the final value of count
    // Due to the non-blocking nature of try_lock, some increments may be missed,
    // so the final value of count might be less than 2,000,000
    cout << count << endl;

    return 0;
}
/*
try_lock():
===============
m.try_lock() attempts to lock the mutex without blocking.
If the mutex is already locked, try_lock() returns false, and the loop continues without incrementing count.
If the mutex is successfully locked, try_lock() returns true, the critical section (count++) is executed, and the mutex is unlocked with m.unlock().

Important Note
===============
Because try_lock() is non-blocking, it is possible for some increments to be missed if both threads frequently fail to acquire the lock simultaneously.
As a result, the final value of count might be less than 2,000,000.
*/
