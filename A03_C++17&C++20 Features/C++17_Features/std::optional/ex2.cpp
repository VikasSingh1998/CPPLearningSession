Example 2️⃣: Default Values Using std::optional::value_or()
If a value is absent, we can provide a default value using .value_or().
----------------------------------------------------------------------------
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
    optional<string> username = findUserByID(4).value_or("defaultName");
    
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
-------------------------------------------------------
Output:
User Name is: defaultName
-------------------------------------------------------------------------------------
Summary
==========
Feature	                          Explanation
.has_value()	----------> Checks if a value is present
*optional_var	-----------> Dereferences the optional to get the actual value
.value_or(default)	----------> Returns the value if present, otherwise returns a default value
std::nullopt	----------------> Represents an empty std::optional

🚀 Key Takeaways
std::optional<T> makes function return values more expressive.
Avoids nullptr, magic values (-1, 0, empty string) for missing data.
Improves code readability and robustness.
====================================================================================







