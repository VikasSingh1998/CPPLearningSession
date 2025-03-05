Basic Syntax of Lambda Function
----------------------------------
auto functionName = [capture](parameters) -> return_type { 
    // function body
};

Parts of a Lambda Function
---------------------------
Capture Clause [] → Captures variables from the surrounding scope.
Parameter List () → Specifies input arguments (like a regular function).
Return Type -> return_type (optional) → Specifies the return type.
Function Body {} → Contains the actual logic of the lambda function.
========================================================================
1. Simplest Lambda Function (No Parameters, No Captures)
---------------------------------------------------------
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    auto fun = [](){
        cout<<"this is the first lambda function!"<<endl;
    };
    fun();
    return 0;
}
/*
auto funName = []() -> RT {};
if the RT is not there, no need to  the write ->
---------------------------------------------------------
💡 Explanation:

[] → No captures.
() → No parameters.
*/ 
