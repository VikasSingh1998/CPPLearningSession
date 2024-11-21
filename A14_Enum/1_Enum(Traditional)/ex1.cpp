Enum, which is also known as enumeration, is a user-defined data type
that enables you to create a new data type that has a fixed range of
possible values, and the variable can select one value from the set of values.
// -------------------------------------------------------------------------------
IN cpp there are 2 types of Enum
1. Traditional enum
2. Enum Class (Scoped Enum)
//==================================
Traditional enum
====================-----
1. Named Integer Constants
-------------------------
Traditional enums define a set of named integer constants.
Each enumerator (like Red, Green, Yellow) is associated with
an integer value, starting from 0 by default, and incrementing
by 1 for each subsequent enumerator.

enum TrafficLightState {
    Red,    // Internally represented as 0
    Green,  // Internally represented as 1
    Yellow  // Internally represented as 2
};

Key Points:
-------------
Named Constants: The enum provides human-readable names (Red, Green, Yellow) for integer values (0, 1, 2), improving code clarity.
Implicit Values: By default, Red is assigned 0, Green is 1, and Yellow is 2, but these can be customized.
enum TrafficLightState {
    Red = 5,     // Red is now 5
    Green,       // Green is automatically assigned 6
    Yellow = 10  // Yellow is manually set to 10
};

2. Implicit Conversions: Enum to Integer
-------------------------------------------
In traditional enum, the enumerators are implicitly convertible to integers.
This means that you can assign an enumerator to an integer variable
without any explicit conversion, which can lead to bugs.

{
    TrafficLightState state = Red; // This works fine
    int val = state;  // No error. Implicit conversion happens here.
    std::cout << val;  // Output: 0 (because Red corresponds to 0)
}

Issues:
Unintended Conversions: Since enums are implicitly converted to integers,
you might accidentally treat an enum as a number, leading to confusion or unintended behavior.

Comparison with Integers: You can compare enum values directly with integers, which may result in subtle bugs.

if (state == 1) {
    std::cout << "State is Green";  // This works because Green is 1, but it's confusing and error-prone.
}

3. Scope: Enumerators Share the Same Scope as the Enum
----------------------------------------------------------
In traditional enums, the enumerator names (like Red, Green, and Yellow) are in the same scope as the enum itself.
This means that once an enumerator is defined, it can cause conflicts if another enum or variable has the same name.

enum TrafficLightState
{
    Red,
    Green,
    Yellow
};
enum OtherState
{
    Red, //Error -> Red already defined in the TrafficLightState
    Blue
};
Issues:
Name Conflicts:
If two enums have the same enumerator name (like Red in TrafficLightState and OtherState),
you’ll get a compiler error due to the name collision.

Polluted Namespace:
All enumerators are injected into the global or local scope,
so the more enums you have, the greater the risk of name conflicts.

4. Type Safety: Lack of Strong Type Checking
--------------------------------------
Traditional enum lacks strong type safety, meaning you can mix enumerators
from different enums without any compiler error. This can lead to confusing bugs,
as the compiler does not distinguish between enumerators from different enums.

Example:
enum TrafficLightState {
    Red,
    Green,
    Yellow
};

enum OtherState {
    Red,   // Another Red in a different enum
    Blue
};

TrafficLightState trafficState = Red;  // This works fine.
OtherState otherState = Red;  // This also works fine, but is it clear which Red this is?

// You can even do this:
trafficState = otherState;  // No compiler error! But this mixes two different enums.

Issues:
Mixing Different Enums:
Since enums are just integers, the compiler does not stop you from assigning one enum to another,
even if they represent completely different concepts (e.g., a traffic light state and some other state).

Confusing Bugs:
You might accidentally use an enumerator from one enum in a context
where another enum is expected, and the compiler won’t catch this.


Summary of Issues with Traditional enum:
Implicit Integer Conversion: Enumerators can be automatically treated as integers, leading to unintended behavior.
Name Conflicts: Enumerators are not scoped, so they can conflict with other identifiers.
Lack of Type Safety: Mixing enumerators from different enums is possible, which can lead to confusing bugs.
Unintended Comparisons: Enumerators can be compared with integers or even other enum types, which can create logical errors.
//=================================================================================
