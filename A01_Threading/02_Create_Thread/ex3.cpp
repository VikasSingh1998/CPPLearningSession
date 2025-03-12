// Thread creation by using the Functor(function Object)
#include <iostream>
#include <thread>

// Functor ==> A class with operator()
// A functor (function object) in C++ is a class that overloads the operator(), making instances of the class callable like a function.
class Functor
{
public:
    void operator()(int x) const
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
    // Create an instance of the Functor class.
    Functor functor;//we can use this instance as a fuction.

    // Create a thread (t1) that runs the functor with an argument of 10
    std::thread t1(functor, 10);

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
