#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string str = "CSE CPP 121";
    // Our goal is to extract each piece of information in the string str.

    stringstream sso(str); // Convert the string into the stringstream.

    string dept, course, cval;
    sso >> dept; // Extract the first chunk
    cout << "dept is: " << dept << endl;

    sso >> course; // Extract the second chunk
    cout << "Course is: " << course << endl;

    sso >> cval; // Extract the third chunk
    cout << "Course value is: " << cval << endl;

    // string extra;
    // while (sso >> extra) {
    //     cout << "Extra value: " << extra << endl;
    // }

    return 0;
}
// dept is:CSE
// Course is: CPP
// Course value is: 121
