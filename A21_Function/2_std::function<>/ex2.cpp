Different Ways to Use std::function<>
============================================================================
🔹 Example 1: Using Function Pointer
--------------------------------------
Code:
#include <iostream>
#include <functional>
using namespace std;

//Normal function.
int add(int a,int b)
{
    return a+b;
}

int main()
{
    function<int(int,int)> fun = add;// Store function pointer
    cout<<fun(3,4)<<endl;

    return 0;
}
📌 Here, func stores a pointer to add() and calls it using func(3, 7).
---------------------------------------------------------------------------
🔹 Example 2: Using std::function<> with a Lambda
---------------------------------------------------
#include <iostream>
#include <functional>
using namespace std;

int main()
{
    // Define a std::function that holds a lambda function
    function<int(int,int)> fun = [](int a,int b)  -> int {
        return a+b;
    };
    
    cout<<fun(4,5)<<endl;

    return 0;
}
✅ Here, std::function<int(int, int)> means it stores a function that 
takes two int arguments and returns an int.
------------------------------------------------------------------------
🔹 Example 3: Using Functor (Function Object)
----------------------------------------------
#include <iostream>
#include <functional>
using namespace std;

//Functor (Function Object)
//(class with operator()).
class Functor 
{
public:
    int operator()(int a,int b)
    {
        return a+b;
    }
};

int main()
{
    function<int(int,int)> fun = Functor();// // Store functor
    cout<<fun(3,4)<<endl;

    return 0;
}
--------------------------------------------------------------------
🔹 Example 4: Using std::function<> to Store Multiple Functions
-----------------------------------------------------------------
#include <iostream>
#include <functional>
using namespace std;

void normalFuntion()
{
    cout<<"This is the normal function!"<<endl;
}

//Functor (Function Object)
//(class with operator()).
class Functor 
{
public:
    void operator()()
    {
        cout<<"This is the functor"<<endl;
    }
};

int main()
{
    function<void()> fun;
    
    fun = normalFuntion;
    fun();//This is the normal function!
    
    fun = Functor();
    fun();//This is the functor

    return 0;
}
✅ We can assign different functions to func dynamically and call them.
--------------------------------------------------------------------------
🔹 Example 5: Using std::function<> for Callbacks
std::function<> is useful for event-driven programming and callbacks.
----------------------------------------------------------------------
























