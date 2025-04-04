#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string str = "CSE CPP 121"; // Initialize a string with the value "CSE CPP 121"

    // Create an object of stringstream and initialize it with the input string
    stringstream sso(str);

    string line1;
    // Use getline to read the entire content of the stringstream into line1
    getline(sso, line1);

    // Output the content of line1
    cout << line1 << endl; // This will print: CSE CPP 121

    return 0;
}

