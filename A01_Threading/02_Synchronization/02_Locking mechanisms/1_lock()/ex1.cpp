1. Understanding lock() and unlock() on std::mutex
----------------------------------------------------------
In C++, std::mutex provides two primary methods for locking and unlocking a mutex.
lock(): 
---------
Acquires the lock on the mutex. 
If the mutex is already locked by another thread, the calling thread blocks (waits) until the mutex becomes available.

unlock(): 
----------
Releases the lock on the mutex, allowing other waiting threads to acquire it.
----------------------------------------------------------------------------------------------------
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx; // Shared mutex
int counter = 0; // Shared resource

void incrementCount() 
{
    mtx.lock(); // Acquiring the lock
    for(int i=0;i<1000;i++)
    {
        counter++;
    }
    mtx.unlock(); // Releasing the lock
}

int main() 
{
    thread t1(incrementCount);
    thread t2(incrementCount);

    t1.join();
    t2.join();
    
    cout<<"Final count value is: "<<counter<<endl;
    return 0;
}

