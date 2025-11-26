Internal Working of std::recursive_mutex
------------------------------------------
std::recursive_mutex internally maintains a lock count and owner thread ID. 
This allows the same thread to acquire the lock multiple times without deadlock, unlike std::mutex which blocks on re-locking.

1. Ownership Tracking
- Jab thread lock() call karta hai, mutex check karta hai:
- Kya ye mutex pehle se kisi thread ke paas hai?
- Agar haan, kya same thread hai?
- Agar same thread hai → lock count increment hota hai.
- Agar different thread hai → thread wait karega until mutex unlock ho.

2. Lock Count Mechanism
- Har successful lock() call → internal counter ++
- Har unlock() call → counter --
- Jab counter zero ho jata hai → mutex fully unlocked ho jata hai.
  
3. Thread ID Storage
- Internally, mutex ek thread ID store karta hai (usually via std::thread::id)
- Ye ID verify karta hai ki lock/unlock calls same thread se ho rahe hain ya nahi.

4. Deadlock Prevention
- Agar same thread baar-baar lock() kare to std::mutex deadlock kar deta hai.
- recursive_mutex isko avoid karta hai by allowing reentrant locking.

📌 Summary
- recursive_mutex = mutex + counter + thread ID
- Allows same thread to lock multiple times safely.
=========================================================================================
Actual Impl of recursive_mutex
--------------------------------





