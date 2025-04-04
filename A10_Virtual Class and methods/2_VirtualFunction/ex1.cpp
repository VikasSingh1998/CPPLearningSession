#include <iostream>
using namespace std;
class Base
{
public:
    void fun()
    {
        cout << "function in class Base" << endl;
    }
};
class Derived : public Base
{
public:
    void fun()
    {
        cout << "function in class Derived" << endl;
    }
};

int main()
{
    // Base ka reference point kr rha hai Base ke object ko
    Base objBase = Base();
    objBase.fun(); // function in class Base

    // Derived class reference refer to Derived class object.
    Derived objDerived = Derived();
    objDerived.fun(); // function in class Derived

    // "Parent class reference can refer to a child class object"
    Base objBase1 = Derived();
    objBase1.fun(); // function in class Base

    // Object Derived class ka hai and reference base ka  ===> fir bhi Base ka fun() call ho rha hai, but Object derived class ka hai to derive ka fun() call hona chahiye.
    // Therefore we have to  use the virtual function to do the run time bunding of the fun() with the object.

    // ==> Virtual Function is used to do the run time binding.

    return 0;
}

