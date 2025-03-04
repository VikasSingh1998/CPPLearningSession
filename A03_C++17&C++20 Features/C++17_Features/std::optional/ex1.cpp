What is std::optional?
std::optional<T> is a feature introduced in C++17. 
It is a wrapper that can either contain a value or be empty. 
This helps avoid returning raw pointers or special values (like -1 or nullptr) to indicate missing data.
//========================================================================================================
#include <iostream>
#include <optional>
#include <string>

using namespace std;

// Function to find a username by ID
optional<string> findUserByID(int id)
{
    if(id == 1) return "user1_vikas";
    else if(id == 2) return "user2_ravi";
    else if(id == 3) return "user3_prashant";
    else return nullopt;
}

int main()
{
    optional<string> username = findUserByID(4);
    
    //Check if the value exists inn the username.
    if(username.has_value())
    {
        cout<<"User Name is: "<<*username<<endl;
    }
    else
    {
        cout<<"No user found for the given ID."<<endl;
    }
    
    return 0;
}
--------------------------------
Output:
No user found for the given ID.
-----------------------------------------------------------------------------------
