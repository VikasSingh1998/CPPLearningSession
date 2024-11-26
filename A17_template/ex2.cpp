#include <iostream>
using namespace std;

template<typename T>
T add(T a, T b)
{
    return a+b;
}

int main()
{
    cout<<add(5,10)<<endl;//15
    cout<<add(5.10,10.10)<<endl;//15.2
    cout<<add(15.5,10.9)<<endl;//26.4 
    cout<<add(15,10.9)<<endl;//error: no matching function for call to ‘add(int, double)’
    return 0;
}
