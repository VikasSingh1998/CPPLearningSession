2. std::unique_lock (Flexible Locking)
---------------------------------------
std::unique_lock is a more flexible locking mechanism compared to std::lock_guard. 

It provides additional features like:
--------------------------------------
Deferred Locking: You can create a lock without immediately locking the mutex.
Explicit Unlocking: You can manually unlock the mutex before the lock goes out of scope.
Move Semantics: It supports transferring ownership of locks.

Key Features
--------------
✅ More control over locking and unlocking.
✅ Supports deferred and timed locking.
✅ Can be moved to another std::unique_lock.
✅ More overhead than std::lock_guard.
