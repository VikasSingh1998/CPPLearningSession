3. std::scoped_lock (C++17) - Deadlock Prevention
Theory
=======
std::scoped_lock was introduced in C++17 for deadlock prevention.
It allows locking multiple mutexes in one operation, avoiding deadlocks caused by inconsistent locking order.

Key Features
✅ Locks multiple mutexes atomically in one step.
✅ Prevents deadlocks in multi-mutex scenarios.
✅ Automatically unlocks when going out of scope (like std::lock_guard).
✅ Requires C++17 or later.
--------------------------------------------------------------------------------
