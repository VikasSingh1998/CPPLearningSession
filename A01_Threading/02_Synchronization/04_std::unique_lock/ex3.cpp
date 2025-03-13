Deferred Locking with std::unique_lock
We can delay locking using std::defer_lock and manually lock later.
----------------------------------------------------------------------------
Syntx:
======
std::unique_lock<std::mutex> lock(mtx, std::defer_lock); // Does NOT lock immediately
lock.lock(); // Locking when needed
