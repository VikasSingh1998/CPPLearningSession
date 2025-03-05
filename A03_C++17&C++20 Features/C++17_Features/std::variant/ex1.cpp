🔹 std::variant in C++17
std::variant is a type-safe alternative to union, introduced in C++17. 
It allows storing multiple types but only one at a time.

🛠️ Why Use std::variant?
It helps store multiple possible types in a single variable.
Safer than union, as it enforces type safety and prevents undefined behavior.
Can be used instead of void*, reducing type ambiguity.
=============================================================================================
📌 Example 1️⃣: Basic Usage of std::variant
This example demonstrates storing multiple types and accessing them.
---------------------------------------------------------------------
#include <iostream>
#include <variant>
using namespace std;

int main()
{
    variant<int,float,string> val;
    
    //assign the int value to val 
    val = 10;
    cout<<"Current value to the variant is: "<< get<int>(val)<< endl;
    
    //assign the float value to the val 
    val = 10.13f;
    cout<<"Current value to the variant is: "<< get<float>(val)<< endl;
    
    //now assign the stirng value to the variant
    val = "vikas";
    cout<<"Current value to the variant is: "<< get<string>(val)<< endl;

    return 0;
}
---------------------------------------------------------------------------
✅ Key Concepts Used:

std::variant<int, float, std::string> → Can hold either an int, float, or std::string.
std::get<T>(variant) → Retrieves the stored value if the type matches.
