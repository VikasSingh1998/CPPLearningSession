#include <iostream>
// To use :: as a separator instead of the default newline character,
// you can use the overloaded version of getline which allows you to
// specify a custom delimiter.
#include <sstream>
using namespace std;
int main()
{
    string str = "CSE::CPP::121";

    // create the object of stringstream.
    stringstream sso(str);

    string line;
    while (getline(sso, line, ':'))
    {
        // Since we are splitting by "::",
        // we need to ignore the extra ':'
        if (sso.peek() == ':')
        {
            sso.ignore();
        }
        cout << line << endl;
    }

    return 0;
}
// CSE
// CPP
// 121
//==========================================----------------
// We use getline with a third parameter ':' to specify the delimiter.
// We then use sso.peek() to check if the next character is also a colon (:).
// If it is, we call sso.ignore() to skip the extra colon.

