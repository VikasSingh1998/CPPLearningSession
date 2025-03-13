Understanding wait()
=====================

------------------------------------------------------------
There are two ways to call wait() in C++:

Way 1: wait() with only a std::unique_lock<std::mutex>
-------------------------------------------------------
cv.wait(lock);
---------------
When a thread calls cv.wait(lock); it pauses execution indefinitely until 
another thread calls notify_one() or notify_all() on the same std::condition_variable.

How it Works:
--------------
1. The thread acquires the lock (std::unique_lock<std::mutex>).
2. It calls wait(lock), which:
    a. Releases the lock on the mutex (so other threads can access the critical section).
    b. Puts the thread to sleep (indefinitely) until it's notified.
3. Another thread signals using notify_one() or notify_all().
4. The waiting thread wakes up and reacquires the lock before continuing execution.
-----------------------------------------------------------------------------------------------
Example: Thread Waiting Indefinitely Until Notified
----------------------------------------------------
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx; // Mutex for synchronization
std::condition_variable cv; // Condition variable for signaling
bool ready = false; // Shared flag to control execution

void worker() 
{
    std::unique_lock<std::mutex> lock(mtx);//Now child is putting lock on the mutux, 
    //since main thread was sleeping it might put lock successfully.

    cv.wait(lock); // Thread waits here until notified (lock is released while waiting)

    // After waking up, the lock is re-acquired, and the thread checks the condition
    if (ready) 
    {
        std::cout << "Worker: Received signal! Processing...\n";
    }
}

int main() 
{
    std::thread t(worker);//main thread will create the child thread t, so child may execute the worker() after this.

    // Simulate some work in the main thread(lets say main thread is busy in some opeations.)
    std::this_thread::sleep_for(std::chrono::seconds(2)); // main thread will speep for 2 seconds.
    //In this 2 seconds child thread tried to do his opeations.

    {
        std::lock_guard<std::mutex> lock(mtx);//main thread will Lock mutex before modifying shared data
        ready = true;//main thread is setting the ready as true.
    } // Lock is automatically released when `lock_guard` goes out of scope

    std::cout << "Main: Sending signal to worker...\n";
    cv.notify_one(); // Notify the worker thread to wake up

    t.join(); // Wait for the worker thread to finish
    return 0;
}
output:
-------
Main: Sending signal to worker...
Worker: Received signal! Processing...
===========================================================================================


