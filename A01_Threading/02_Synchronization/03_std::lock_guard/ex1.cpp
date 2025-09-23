std::lock_guard ==> automatically locks a std::mutex when it is created and unlocks it when it goes out of scope.
---------------------------------------------------------------------------------------------------------------------
1. std::lock_guard is a RAII (Resource Acquisition Is Initialization)-based locking mechanism that 
   automatically locks a std::mutex when it is created and unlocks it when it goes out of scope. 
2. This eliminates the need to manually call lock() and unlock(), preventing accidental deadlocks.
---------------------------------------------------------------------------------------------------------------------

---------------------------------------------------------------------------------------------------------------------
Mutex ko manually lock() aur unlock() karna thoda risky hota hai, 
kyunki agar programmer bhool gaya unlock karna (ya exception aagayi), to deadlock ho sakta hai.

Is problem ko avoid karne ke liye C++ STL ne std::lock_guard diya hai.
🔹 What is lock_guard?
👉 A lock_guard is a wrapper around mutex which automatically acquires the lock when created and releases it when destroyed (RAII principle).

Matlab tumhe khud unlock() karne ki zarurat nahi hai.
----------------------------------------------------------------------------------------------------------------------
