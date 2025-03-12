std::lock_guard ==> automatically locks a std::mutex when it is created and unlocks it when it goes out of scope.
---------------------------------------------------------------------------------------------------------------------
1. std::lock_guard is a RAII (Resource Acquisition Is Initialization)-based locking mechanism that 
   automatically locks a std::mutex when it is created and unlocks it when it goes out of scope. 
2. This eliminates the need to manually call lock() and unlock(), preventing accidental deadlocks.
---------------------------------------------------------------------------------------------------------------------
