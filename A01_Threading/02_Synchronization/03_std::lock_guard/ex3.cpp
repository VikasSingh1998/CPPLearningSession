Modified Code: Locking Only Line k
-----------------------------------
If you want to keep only line k in the critical section while keeping the rest of the code outside the mutex lock, 
you should use a block scope {} for std::lock_guard. 
This ensures that only the necessary part of the function is protected by the mutex.
------------------------------------------------------------------------------------------------
Code:

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std::mutex mtx; // Shared mutex
int counter = 0; // Shared resource

void increment() 
{
    // Non-critical section
    line1; 
    line2;
    ..
    ..
    
    {   // Critical Section: Only Line `k` is protected by the mutex
        std::lock_guard<std::mutex> lg(mtx);
        counter++;  // Line k (Only this operation is locked)
    }   // Mutex automatically unlocks here

    ..
    ..
    linen;

} 

int main() 
{
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();
    
    cout << "Final value of the counter is: " << counter << endl;

    return 0;
}
--------------------------------------------------------------------------------------------------------
Why This Approach?
✅ Minimal Locking → Only locks the critical operation (Line k).
✅ Improves Performance → Reduces time threads spend waiting for the mutex.
✅ RAII Principle Maintained → lock_guard ensures the mutex is properly released.
---------------------------------------------------------------------------------------------------------
