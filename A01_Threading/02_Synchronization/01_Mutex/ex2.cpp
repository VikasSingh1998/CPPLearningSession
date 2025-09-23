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
=====================================================================================================
race condition is not deadlock --> Race Condition vs Deadlock
-----------------------------------------------------------------
🔴 Race Condition
Definition: Jab multiple threads ek shared resource ko bina proper synchronization ke access/modify karte hain → result unpredictable ho jaata hai.

Issue: Data inconsistency.
Cause: Missing locks ya improper synchronization.

Example:
// Shared counter update by 2 threads (without mutex)
counter++; // race condition -> unpredictable result

Output: Har run me counter alag-alag value dikhayega.
👉 Race condition = Uncontrolled access → Wrong results

🔴 Deadlock
Definition: Jab 2 (ya zyada) threads ek dusre ka wait karte hi reh jaate hain, aur koi bhi aage nahi badh pata.

Issue: Program freeze ho jaata hai.
Cause: Galat locking order ya circular wait.

Example:
std::mutex m1, m2;
void thread1() {
    std::lock_guard<std::mutex> lock1(m1);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> lock2(m2); // waiting for m2
}

void thread2() {
    std::lock_guard<std::mutex> lock2(m2);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> lock1(m1); // waiting for m1
}


Thread1 ne m1 lock kar liya aur m2 ka wait kar raha hai.
Thread2 ne m2 lock kar liya aur m1 ka wait kar raha hai.
Dono wait karte rahenge = Deadlock.

👉 Deadlock = Threads stuck → No progress

✅ Clear Difference Table
-----------------------------------------------------------------------------------------------------------------
Aspect	                       Race Condition 🏃‍♂️💨	                                     Deadlock 🚧
Definition	          Multiple threads access shared data without sync	          Threads wait forever on locks
Result	                   Wrong / unpredictable output	                            Program freeze / hang
Cause	M                   issing or improper locking	                               Circular wait on resources
Detection	                Wrong values, inconsistent data                       	Program stops responding
Fix	                         Use mutex/locks properly	                          Lock ordering, try_lock, deadlock avoidance

👉 So simple line for interview:
"Race condition leads to incorrect results due to unsynchronized access, 
while deadlock leads to no result because threads are stuck waiting on each other."
------------------------------------------------------------------------------------------------------------------






























    

