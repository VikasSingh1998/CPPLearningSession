Ex: Compare two threads
==========================
#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;

int main() {
    std::thread t1;// t1 is empty thread

    std::cout << "Main thread ID: " << std::this_thread::get_id() << std::endl;
    std::cout << "t1 ID: " << t1.get_id() << std::endl;
    
    
    std::thread::id id1 = std::this_thread::get_id();
    std::thread::id id2 = t1.get_id();
    
    if (id1 == id2) {
        std::cout << "Same thread\n";
    } else {
        std::cout << "Different threads\n";
    }

    // t1.join();  ==> Calling join() on empty thread causes crash

    return 0;
}
O/P:
Main thread ID: 137591814187904
t1 ID: thread::id of a non-executing thread
Different threads
------------------------------------------
❌ std::thread t1;
Ye line ek default-constructed thread बनाती है — यानी ऐसा thread जो किसी भी function को run नहीं कर रहा. 
इसे हम कहते हैं non-joinable thread
-------------------------------------------
🔍 Problem:
- t1.get_id() will return a default-constructed thread ID, which is usually equal to std::thread::id{}.
- t1.join() पर runtime error आएगा, क्योंकि t1 कभी start ही नहीं हुआ

===================================================================================================
Example2:
-------------------
#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;

void task() {
    m.lock();
    std::cout << "Inside thread, ID: " << std::this_thread::get_id() << std::endl;
    m.unlock();
}

int main() {
    std::thread t1(task); // ✅ Thread created with function

    std::cout << "Main thread ID: " << std::this_thread::get_id() << std::endl;
    std::cout << "t1 ID: " << t1.get_id() << std::endl;

    std::thread::id id1 = std::this_thread::get_id();
    std::thread::id id2 = t1.get_id();

    if (id1 == id2) {
        std::cout << "Same thread\n";
    } else {
        std::cout << "Different threads\n";
    }

    t1.join(); // ✅ Safe to join now
    return 0;
}
-------------
Main thread ID: 123417467419520
t1 ID: 123417467406016
Different threads
Inside thread, ID: 123417467406016
-----------------------------------------------------------------------------------------------
