Race Condition Example (without mutex)
--------------------------------------
#include <iostream>
#include <thread>

int counter = 0;  // shared resource

void increment() {
    for(int i = 0; i < 100000; i++) 
    {
        //no synchronization
        counter++;  // multiple threads update at same time ❌
        //read-modify-write is not atomic operation
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final Counter: " << counter << "\n";
    return 0;
}
---------------------------------------
📝 Expected Output:
Ideally, counter = 200000 (100000 from each thread).

⚠️ But Actual Output:
Kabhi 150000, kabhi 170000, kabhi 180000... different every run.

Reason → Race Condition (dono threads ek hi time pe counter ko update kar rahe hain).
