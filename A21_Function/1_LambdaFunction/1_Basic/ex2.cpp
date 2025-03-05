1. Simplest Lambda Function (No Parameters, No Captures)
//=========================================================
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
