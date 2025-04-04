#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    // We have the number stored in the form of a string.
    // string number = "4442ee32cc";
    string number = "ee32cc";

    // Initialize stringstream with the input string
    stringstream ss(number);

    // Now we can read the integer part from the stringstream.
    int val;
    ss >> val; // Extracts the integer part from the stringstream

    // Output the integer value
    cout << "int value is: " << val << endl;
    // Demonstrate that 'val' is an integer by performing an arithmetic operation
    cout << "After adding 10 to int val: " << val + 10 << endl;

    // Check if the extraction failed
    // Check for extraction failure: if (ss.fail())
    // If the input string did not contain a valid integer at the start,
    // ss.fail() would be true. This part of the code handles such cases.
    if (ss.fail())
    {
        cout << "Given string value is not the string form of an int" << endl;
    }

    return 0;
}
// output
//----------------------------------
//  int value is: 444
//  After adding 10 to int val: 454
//----------------------------------
// int value is: 4442
// After adding 10 to int val: 4452
//----------------------------------
// int value is: 0
// After adding 10 to int val: 10
// Given string value is not the string form of an int
//----------------------------------
// Here only the first part of the string which is in the int form will be extracated and converted to int.
