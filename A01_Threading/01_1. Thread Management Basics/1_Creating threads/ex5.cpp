// Thread creation by using the  static member funtion
//=====================================================
#include <iostream>
#include <thread>

class MyClass
{
public:
    // fun is the  static member function.
    static void fun(int x)
    {
        int i = 1;
        while (i <= x)
        {
            std::cout << "Child thread executed " << i << " times" << std::endl;
            i++;
        }
    }
};

int main()
{
    // create the instance of MyClass
    MyClass obj;

    // Create a thread (t1) that runs the static member function with an argument of 10
    std::thread t1(&MyClass::fun, 10);

    // This loop will be executed by the main thread
    for (int i = 1; i <= 10; i++)
    {
        std::cout << "Main thread executed " << i << " times." << std::endl;
    }

    // Main thread waits for t1 to finish
    t1.join();

    // Return 0 to indicate successful completion
    return 0;
}
/*
Creating a thread that runs a static member function in C++ is straightforward
because static member functions do not operate on specific instances of a class
and do not require an object instance to be called.
--------------------------------------------------------------------------------------
*/
