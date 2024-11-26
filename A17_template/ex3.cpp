//How to take the different types arguments.
#include <iostream>
using namespace std;

template<typename T1, typename T2>
auto add(T1 a, T2 b) //>=C++ 14
{
    return a+b;
}

int main()
{
    cout<<add(5,10)<<endl;//15
    cout<<add(5.10,10.10)<<endl;//15.2
    cout<<add(15.5,10.9)<<endl;//26.4 
    cout<<add(15,10.9)<<endl;//25.9
    return 0;
}
