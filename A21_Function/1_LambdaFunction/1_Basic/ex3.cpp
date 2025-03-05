3. Capturing Variables from Scope in Lambda Functions
--------------------------------------------------------
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x = 10, y = 20;
    
    // 1. Capture by value.
    // x and y are captured **by value**, 
    // meaning their copies are used inside the lambda.
    auto add = [x,y]() -> int{
        return x+y;
    };
    
    cout<<add()<<endl;//30
    
    // 2. capture by reference.
    // x is captured **by reference**, so modifying x inside lambda affects the original x.
    auto xrefFun = [&x]() {
        x++;
    };
    xrefFun();
    cout<<x<<endl;//11

    return 0;
}
----------------------------------------------------------------------------------------------------------------------------------------
💡 Capture Types in Lambda Functions
-------------------------------------------------------------------------------------
Capture Type	                    Example                          	Effect
-------------------------------------------------------------------------------------
Capture by Value	                 [x, y]                	Copies x and y inside the lambda. Outer variables remain unchanged.
Capture by Reference              	[&x]	                Uses reference to x. Modifications inside lambda affect the original x.
Capture All by Value	               [=]	                Copies all local variables inside the lambda.
Capture All by Reference	           [&]	                Uses reference for all local variables, modifying the originals.
-----------------------------------------------------
[=]() mutable	 ==========> Captures all variables by value but allows modification of local copies
[x, &y]	       ==========> Captures x by value (read-only) and y by reference (modifiable)
------------------------------------------------------------------------------------------------------------------------------------------
Example: Capture All by Reference
---------------------------------------------
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x = 10, y = 20;
    
    // Capture all variables by reference (modifies original)
    auto add = [&]() -> int{
        x +=5;
        y -=5;
        return x+y;
    };
    cout<<add()<<endl;//30
    cout<<"X value is: "<<x<<endl;//15
    cout<<"Y value is: "<<y<<endl;//15

    return 0;
}
------------------------------------------------------------------------
Example: Capture All by Value
-------------------------------------
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x = 10, y = 20;
    
    // Capture all variables by values
    auto add = [=]() -> int{
        x +=5;//error: assignment of read-only variable ‘x’
        y -=5;//error: assignment of read-only variable ‘y’
        return x+y;
    };
    cout<<add()<<endl;//30
    cout<<"X value is: "<<x<<endl;//15
    cout<<"Y value is: "<<y<<endl;//15

    return 0;
}
Understanding the Compilation Error
------------------------------------------------------------------------------------
In your code, the lambda function captures variables by value ([=]), 
meaning it creates copies of x and y. 
The originals remain unchanged. 
However, when you try to modify them inside the lambda (x += 5; and y -= 5;), you get an error.
This happens because captured-by-value variables are treated as const inside the lambda by default.
--------------------------
How to solve this error:
%%%%%%%%%%%%%%%%%%%%%%%%%%
✅ How to Fix This?
Option 1: Capture by Reference [&] (Modify Original Variables)
If you want to modify x and y, capture them by reference.

auto add = [&]() -> int { // Capture by reference (modifiable)
    x += 5; // ✅ Now allowed
    y -= 5; // ✅ Now allowed
    return x + y;
};
----------------------------
Option 2: Use mutable to Modify Copies
If you want to modify only the copies inside the lambda while keeping the originals unchanged, use mutable:

auto add = [=]() mutable -> int { // Capture by value but allow modifications to copies
    x += 5;  // ✅ Allowed, modifies local copy of x
    y -= 5;  // ✅ Allowed, modifies local copy of y
    return x + y;
};
---------------------------------------------------------------------------------
mutable allows modification of captured-by-value variables inside the lambda.
Original x and y remain unchanged.
Only the copies inside add are modified.
=================================================================================


