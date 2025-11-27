🧠 1. What is std::thread::id?

- Har thread ko ek unique ID milta hai.
- Ye ID use hota hai to:
  - Identify which thread is running.
  - Compare threads.
  - Log/debug multi-threaded code.
-----------------------------------------------------------------------------------------
syntex:
std::thread::id id = std::this_thread::get_id();  ==> to get the id of the current thread.
-------------------------------------------------------------------------------------------
Example: Print the thread id
-----------------------------
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
    std::thread t1(task);
    std::thread t2(task);

    std::cout << "Main thread ID: " << std::this_thread::get_id() << std::endl;
    std::cout << "t1 ID: " << t1.get_id() << std::endl;
    std::cout << "t2 ID: " << t2.get_id() << std::endl;

    t1.join();
    t2.join();
    return 0;
}

Inside thread, ID: 133959477282496
Main thread ID: 133959477296000
t1 ID: 133959477282496
t2 ID: 133959468889792
Inside thread, ID: 133959468889792
======================================================================================













  
