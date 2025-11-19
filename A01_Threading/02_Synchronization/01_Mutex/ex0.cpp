🧠 Mutex ko yaad rakhne ka BEST visualization
-----------------------------------------------------------------------
“Mutex = Ek Room ki Key”
mutex ====> key

Imagine ek room hai jisme shared resource rakha hai.
Ex: Data, Queue, Buffer, Shared variable, File etc.

Is room ka sirf 1 key hai.
Us key ko hum mutex bolte hain.
-----------------------------------------------------------------------
=======================================================================
🟠 Thread = Person (worker)
Har thread ek insaan jaisa hai jo us room me jana chahta hai.
-------------------------------------------------------------------------
🔴 Rule of Mutex
----------------------------------
(Locking Rule):
Jiske paas key hai wohi room me jaa sakta hai. ==> mutex.lock() 
Baaki sab log bahar line me wait karenge (block).

🔵 Unlocking Rule:
Jab thread ka kaam khatam ho jaaye → woh key wapas rakh deta hai (mutex.unlock()).
Aur next thread key le sakta hai.
==============================================================================
💥 Aisa kyun karte hain?
Taki multiple threads ek hi resource ko ek saath access karke usse galat na kar dein.
Same room me 10 log ghus jayenge to data corrupt ho jaayega.

Mutex bolta hai:
"Ek time me sirf ek banda andar."
=============================================================================
Diagram:

          [ROOM]  <-- Shared Data
             |
          [MUTEX] <-- Key
             |
   +-------------------+
   |        |          |
THREAD1   THREAD2    THREAD3
 (Wait)    (Gets)    (Wait)

Thread2 ne mutex lock kar liya → andar chala gaya
Thread1, Thread3 wait kar rahe hain
Thread2 bahar aayega → unlock → next thread andar jaayega
==============================================================================
🧠 Shortcut Memory Formula

✔ Mutex = Mutual Exclusion
✔ Means “Mutually exclude others from entering the shared room.”

💡 Summary for long-term memory
-------------------------------
Shared room → shared resource
Key → mutex
Person (thread) → A worker performing operation
Locking → Key pakad ke andar jao
Unlocking → Key latka ke bahar aao
Other threads wait → Line me khade ho jao until key milti hai
==============================================================================





================================================================================================
================================================================================================
Mutex:  ---> "key" of the room
-------------------------------
Mutex ek synchronization mechanism hai which is used to avoid the race condition.
Mutex ek time par sirf ek thread ko shared resource access karne deta hai, taaki race condition avoid ho.
    
----------------------------------------------------------------------------------------------------------------------------   
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
=========================================================
A semaphore is a non-negative integer that represents the number of available units of a resource. 
A thread or process can acquire a unit of the resource by decrementing the semaphore, 
and release it by incrementing the semaphore. 
A mutex is a binary variable that can have only two values: locked or unlocked.

========================================================


  
