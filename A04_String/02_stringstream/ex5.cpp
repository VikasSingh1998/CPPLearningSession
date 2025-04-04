#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string str = "CSE\nCPP\n121"; // Initialize a string with the value "CSE\nCPP\n121"

    // Create an object of stringstream and initialize it with the input string
    stringstream sso(str);

    string line;
    // Read lines from the stringstream in a loop
    while (getline(sso, line))
    {
        cout << line << endl;
    }

    return 0;
}
// Read lines from the stringstream:
//===================================
// while (getline(sso, line)) starts a loop that continues as long as getline successfully reads a line from sso.
// The getline function reads until it encounters a newline character (\n) or the end of the input.

// In the first iteration, getline(sso, line) reads "CSE" into line.
// In the second iteration, getline(sso, line) reads "CPP" into line.
// In the third iteration, getline(sso, line) reads "121" into line.
//===================================
// output
//-----------
// CSE
// CPP
// 121

