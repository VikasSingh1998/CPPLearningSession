// thread creation by using the lambda function
#include <iostream>
#include <thread>

// Define a lambda function and assign it to the variable 'fun'
auto fun = [](int x) -> void 
{
    int i = 1;
    while (i <= x)
    {
        std::cout << "Child thread executed " << i << " times" << std::endl;
        i++;
    }
};

int main()
{
    // Line executed by main thread:
    // Create a thread (t1) that runs the lambda function 'fun' with an argument of 10
    std::thread t1(fun, 10);

    // The main function should not return until all work is done, so this line should be moved after t1.join()
    // return 0;

    // Line executed by main thread:
    // This loop will be executed by the main thread
    for (int i = 1; i <= 10; i++)
    {
        std::cout << "Main thread executed " << i << " times." << std::endl;
    }

    // Line executed by main thread:
    // Main thread waits for t1 to finish
    t1.join();

    // Line executed by main thread:
    // Return 0 to indicate successful completion
    return 0;
}
