Examples
-----------
std::this_thread::get_id() ==> Get current thread's ID

std::this_thread::sleep_for()  ==> Pause thread for a duration

std::this_thread::sleep_until()  ==> Pause until a specific time

std::this_thread::yield()  ==> Yield execution to allow other threads to run
--------------------------------------------------------------------------------
Example:
std::cout << "Main thread ID: " << std::this_thread::get_id() << std::endl;
-------------------------------------------------------------------------------
std::this_thread::sleep_for(std::chrono::seconds(2));
-------------------------------------------------------------------------------
std::this_thread::yield(); // Give chance to other threads
-------------------------------------------------------------------------------




