Example of std::scoped_lock (Deadlock Prevention)
==================================================
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx1, mtx2; // Two shared mutexes

void thread1() 
{
    std::scoped_lock lock(mtx1, mtx2); // Locks both mutexes safely
    std::cout << "Thread 1 acquired both locks safely.\n";
}

void thread2() 
{
    std::scoped_lock lock(mtx2, mtx1); // Locks in any order safely
    std::cout << "Thread 2 acquired both locks safely.\n";
}

int main() 
{
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();

    return 0;
}
Output:
----------
Thread 1 acquired both locks safely.
Thread 2 acquired both locks safely.
-----------------------------------------------------------------
How It Works?
Without std::scoped_lock, if Thread 1 locks mtx1 first and Thread 2 locks mtx2 first, a deadlock can occur when each waits for the other.
With std::scoped_lock, both mutexes are locked atomically, eliminating deadlocks.
  
Use Case
========
✅ Best suited when multiple mutexes are used to protect shared resources.
✅ Ideal for multi-mutex deadlock prevention.
===================================================================================================================
  
