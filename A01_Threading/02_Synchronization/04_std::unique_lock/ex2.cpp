Example of std::unique_lock
-----------------------------
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std::mutex mtx; // Shared mutex
int counter = 0; // Shared resource

void increment() 
{
    std::unique_lock<std::mutex> lock(mtx); // Lock the mutex

    // Critical Section
    for(int i=0;i<100;i++)
    {
        counter++;
    }
    lock.unlock(); // Manually unlock the mutex before function exits

    // Doing non-critical work here without holding the mutex
    std::cout << "Non-critical work done by thread.\n";
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();
    
    cout<<"Counter value is: "<<counter<<endl;

    return 0;
}
-----------------------------------------------------------
How It Works?
std::unique_lock<std::mutex> lock(mtx); locks the mutex.
lock.unlock(); allows manual unlocking before the function ends.
Allows performing non-critical work after unlocking.
Use Case
✅ Best suited when you need manual unlocking for better efficiency.
✅ When you need to transfer ownership of locks (move semantics).
✅ When locking is deferred (std::defer_lock).
------------------------------------------------------------
