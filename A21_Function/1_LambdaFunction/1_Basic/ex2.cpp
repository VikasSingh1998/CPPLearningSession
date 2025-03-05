2. Lambda with Parameters and return type
------------------------------------------
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    auto add = [](int a,int b) -> int{
        return a+b;
    };
    cout<<add(3,5)<<endl;
    return 0;
}
--------------------------------------------
Explanation:
  auto add = ...; =====>  Stores the lambda in a variable.
