// TO convert the string into the integer value and vice versa we use the stringstream.
//========================================---------------------------------------------
#include <iostream>
#include <sstream>
using namespace std;
int main()
{
    int input;
    cout << "Enter the integer value: ";
    cin >> input;

    // now we have to convert the integer value into the string value.
    // SO, we have to use the stringstream.

    // similar to other stream ==> we can use << and >> with stringstream also.
    stringstream ss; // create the object of the stringstream
    ss << input;     // give this input to the stringstream
    // so we can read the string value from the ss object.

    string str;

    // now we will read the string from the ss object and store into the str.
    ss >> str;
    cout << "Enter value string  form is: " << str << endl;
    // cout << "typedef of str is: " << typeid(str).name() << endl;

    return 0;
}
// output
//-------------------------------------------------------------
// Enter the integer value: 1234
// Enter value string  form is: 1234
// typedef of str is: NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
//-------------------------------------------------------------
// Enter the integer value: 123ere3r4
// Enter value string  form is: 123
// typedef of str is: NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
//-------------------------------------------------------------
// Enter the integer value: weweewewew
// Enter value string  form is: 0
// typedef of str is: NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
//-------------------------------------------------------------
// it is only extracing the first int part of the input and conveting into the string.
// if no int value is present then==> 0 will be printed in the string form

