🔁 क्या होता है recursive_mutex  ===> LOCK with COUNTER to count how many times it is locked by "same" thread.
---------------------------------------------------------------------------------------------------------
-> std::recursive_mutex ek aisa mutex hai jo ek hi thread ko multiple baar lock karne ki permission deta hai, bina deadlock ke.
-> Ye tab useful hota hai jab:
    ==> Ek function recursively call hota hai.
    ==> Ya multiple functions ek hi thread mein ek hi mutex ko lock karte hain.
----------------------------------------------------------------------------------------------------------
Normal MUTEX vs Recursive MUTEX
--------------------------------
MUTEX ---> Multiple lock not allowed(Deadlock ho jata hai).
Recursive_Mutex --> Multiple lock allowed(same thread multiple times lock kar sakta hai)
-----------------------------------------------------------------------------------------------------------
===========================================================================================================
🧠 Example: Recursive Function with recursive_mutex
-----------------------------------------------------
#include <iostream>
#include <thread>
#include <mutex>

std::recursive_mutex rmtx;

void recursive_function(int count) {
    if (count <= 0) return;

    rmtx.lock();
    std::cout << "Lock acquired, count = " << count << std::endl;

    recursive_function(count - 1); // recursive call

    rmtx.unlock();
    std::cout << "Lock released, count = " << count << std::endl;
}

int main() {
    std::thread t1(recursive_function, 3);
    t1.join();
    return 0;
}
🧩 Agar yahan std::mutex use karte to program deadlock ho jata, kyunki ek hi thread baar-baar lock kar raha hai.

⚠️ Caution
- Har baar lock() ke liye ek unlock() zaroori hai. Agar 3 baar lock kiya hai to 3 baar unlock bhi karna padega.
- Overuse mat karo — recursive_mutex flexibility deta hai, but agar logic sahi likha ho to normal mutex hi better hota hai (zyada efficient hota hai).

📌 Summary
- recursive_mutex = same thread ko baar-baar lock karne ki chhoot.
- Useful in recursive functions or nested locking.
- Har lock ke liye ek unlock zaroori hai.

====================================================================================================================
--------------------------------------------------------------------------------------------------------------------
recursive_mutex means lock with counter??
------------------------------------------
🔁 Recursive Mutex = Lock + Counter
- Jab ek thread recursive_mutex ko lock karta hai, internal counter increment hota hai.
- Har lock() call ek count badhata hai, aur har unlock() call ek count kam karta hai.
- Jab counter zero ho jata hai, tab mutex actually unlock hota hai.

std::recursive_mutex rmtx;
rmtx.lock();   // counter = 1
rmtx.lock();   // counter = 2
rmtx.unlock(); // counter = 1
rmtx.unlock(); // counter = 0 → mutex fully unlocked

🔍 Why Is This Useful?
- Jab ek thread nested functions ya recursive calls mein same mutex ko baar-baar lock karta hai.
- Agar normal mutex use karte to deadlock ho jata, kyunki thread apne hi lock ka wait karta.

📌 Summary
- recursive_mutex internally ek lock counter maintain karta hai.
- Har lock() → counter++.
- Har unlock() → counter--.
- Jab counter zero hota hai → mutex unlock hota hai.

=====================================================================================================================
















  

  
