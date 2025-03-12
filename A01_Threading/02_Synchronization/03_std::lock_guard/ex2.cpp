Example of std::lock_guard
-----------------------------
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std::mutex mtx; // Shared mutex
int counter = 0; // Shared resource

void increment() 
{
    std::lock_guard<std::mutex> lock(mtx); // Lock mutex automatically (RAII)
    
    // Critical Section (Only one thread can execute this at a time)
    for(int i=0;i<100;i++)
    {
        counter++;
    }
    std::cout << "Counter: " << counter << std::endl;

} // Lock automatically released when `lock` goes out of scope

int main() 
{
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();
    
    cout<<"Final value of the counter is: "<<counter<<endl;

    return 0;
}
/*
Counter: 100
Counter: 200
Final value of the counter is: 200
*/
------------------------------------------------------------
How It Works?
When std::lock_guard<std::mutex> lock(mtx); is created, it locks the mutex.
When the function exits (or an exception occurs), the lock_guard automatically unlocks the mutex.
No need for manual lock() and unlock().
Use Case
✅ Best suited for simple and short-lived critical sections.
✅ Prevents accidental forgetting of unlock(), reducing deadlocks.
