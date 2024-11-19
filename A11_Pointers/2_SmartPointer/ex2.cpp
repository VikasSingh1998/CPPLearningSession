Types of Smart Pointers
===========================
C++ libraries provide implementations of smart pointers in the following types:
    1. auto_ptr ==> not used(depricated).
    2. unique_ptr
    3. shared_ptr
    4. weak_ptr

1. auto_ptr
The auto_ptr was a smart pointer that was available in older versions of C++ (C++98 and C++03) 
but has been deprecated in modern C++ standards (C++11 and later). 
It was replaced by std::unique_ptr, which provides better safety and functionality.
