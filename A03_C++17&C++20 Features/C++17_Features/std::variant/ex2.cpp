📌 Example 2️⃣: Checking the Active Type Using std::holds_alternative
This example shows how to check which type is currently stored.
--------------------------------------------------------------------------
#include <iostream>
#include <variant>
using namespace std;

int main()
{
    variant<int,float,string> val;
    
    // val = 10;
    // val = 10.23f;
    val = "vikas";
    
    // val = 12.5;  
    // 12.5 is of type double, but double is not in variant<int, float, string>
    // The error occurs because std::variant<int, float, std::string> does not include double, 
    // but you are assigning 12.5, which is of type double.

    
    if(holds_alternative<int>(val))
    {
        cout<<"Int value is: "<<get<int>(val)<<endl;
    }
    else if(holds_alternative<float>(val))
    {
        cout<<"Float value is: "<<get<float>(val)<<endl;
    }
    else if(holds_alternative<string>(val))
    {
        cout<<"String value is: "<<get<string>(val)<<endl;
    }
    else
    {
        cout<<"Given type is not matched!"<<endl;
    }

    return 0;
}
------------------------------------------------------------------
✅ Key Concepts Used:

std::holds_alternative<T>(variant) → Checks if variant holds a specific type before retrieving it.
Avoids runtime errors from using std::get<T> on a type that isn't currently stored.
--------------------------------------------------------------------
