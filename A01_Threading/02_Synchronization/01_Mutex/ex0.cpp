How mutux is internally implemented in cpp
============================================
std::mutex is internally a class in C++ that provides mutual exclusion for synchronizing threads. 
It is defined in the <mutex> header.
----------------------------------------------------------------------------------------------------------------------------
1. std::mutex is a Class
The std::mutex class is a wrapper around OS-specific synchronization primitives (like POSIX mutexes on Linux or CRITICAL_SECTION on Windows).

Definition (Simplified)
------------------------
namespace std 
{
    class mutex 
    {
    public:
        mutex();           // Constructor
        ~mutex();          // Destructor

        void lock();       // Locks the mutex (blocks if already locked)
        void unlock();     // Unlocks the mutex
        bool try_lock();   // Tries to lock the mutex (returns immediately if already locked)

        mutex(const mutex&) = delete; // Mutex cannot be copied
        mutex& operator=(const mutex&) = delete;
    };
}
--------------------------------------------------------------------------
2. How std::mutex Works Internally
-----------------------------------
std::mutex maintains an internal flag (locked/unlocked state).
When lock() is called, it checks:
  1. If unlocked, the calling thread locks it.
  2. If already locked, the calling thread blocks until it gets the lock.
unlock() ==> releases the lock, allowing other threads to acquire it.
try_lock() ==> attempts to lock but does not block if already locked.
---------------------------------------------------------------------------
4. Why std::mutex Cannot Be Copied?
std::mutex m1;
std::mutex m2 = m1; // ❌ ERROR! std::mutex is non-copyable
Mutex cannot be copied because copying it would allow two mutex objects to control the same resource, leading to undefined behavior.
Instead, you pass mutex by reference if needed.
---------------------------------------------------------------------------
Example: Example to Demonstrate Mutex Blocking
================================================
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex m; // Global mutex

void task(int id) 
{
    cout << "Thread " << id << " waiting for lock"<<endl;
    m.lock();
    cout << "Thread " << id << " got the lock"<<endl;
    this_thread::sleep_for(chrono::seconds(2)); // Simulating work
    cout << "Thread " << id << " releasing lock"<<endl;
    m.unlock();
}

int main() {
    std::thread t1(task, 1);
    std::thread t2(task, 2);

    t1.join();
    t2.join();

    return 0;
}
/*
Thread 1 waiting for lock
Thread 2 waiting for lock
Thread 2 got the lock
Thread 2 releasing lock
Thread 1 got the lock
Thread 1 releasing lock
*/



  
