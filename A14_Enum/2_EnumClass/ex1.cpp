Scoped Enum (enum class)
=========================
1. Definition: Strongly-Typed and Scoped Enumeration
-----------------------------------------------------
enum class is used to define a strongly-typed and scoped enumeration.
Unlike traditional enum, where enumerators are implicitly converted to
integers and exist in the surrounding scope, enum class keeps the enumerators
contained within the enum itself.
This means they are fully qualified and need to be accessed through the enum’s scope.

Example:
enum class TrafficLightState {
    Red,
    Green,
    Yellow
};

Here, the enum class TrafficLightState defines three enumerators (Red, Green, Yellow).
These enumerators are scoped under TrafficLightState and not accessible directly by
their name alone.
To access them, you must use
TrafficLightState::Red
TrafficLightState::Green

Key Points:
Strongly-Typed: enum class ensures that the values are not just treated as simple integers, preventing accidental misuse or type mixing.
Scoped: The enumerators belong to the enum class and must be qualified with the enum name, reducing the risk of name collisions.

2. No Implicit Conversion
--------------------------
In a traditional enum, you can implicitly convert an enumerator to an integer.
However, with enum class, there is no implicit conversion.
If you want to treat an enumerator as an integer, you must explicitly cast it.

{
    TrafficLightState state = TrafficLightState::Red;

    // This line would cause an error because enum class values are not implicitly convertible to int:
    // int value = state; // Error

    // Instead, we need to use an explicit cast:
    int value = static_cast<int>(state);  // Works fine, value becomes 0 because Red corresponds to 0
}

3. Scoped Enumerators
----------------------
Enumerators are scoped within the enum class and do not pollute the surrounding namespace.

enum class TrafficLightState {
    Red,
    Green,
    Yellow
};

enum class OtherState {
    Red,   // No conflict with TrafficLightState::Red
    Blue
};

int main() {
    TrafficLightState state = TrafficLightState::Red;  // Access Red within TrafficLightState
    OtherState other = OtherState::Red;                // Access Red within OtherState
}

In this example:
-----------------
Both TrafficLightState and OtherState have an enumerator named Red,
but they don’t conflict because they are scoped within their respective enum classes.

To access Red from TrafficLightState, you need to use TrafficLightState::Red.
Similarly, to access Red from OtherState, you use OtherState::Red.

Key Points:
------------
No Name Conflicts:
Even if different enum class types have the same enumerator names (like Red),
they won’t conflict because they are scoped within their enum.

Cleaner Code:
You avoid naming clashes and the need for unique enumerator names across different enums.

4. Type Safety:
----------------
Strong type safety prevents mixing of enumerators from different enum class types.

enum class TrafficLightState {
    Red,
    Green,
    Yellow
};

enum class OtherState {
    Red,
    Blue
};

int main() {
    TrafficLightState state = TrafficLightState::Red;

    // This would cause an error because we cannot assign an enumerator from OtherState to TrafficLightState:
    // state = OtherState::Red;  // Error: Incompatible types
}

In this example, you cannot assign OtherState::Red to TrafficLightState state,
even though both enums have an enumerator named Red. The compiler enforces this,
ensuring that enumerators from different enum class types aren’t mixed up, which greatly reduces potential bugs.

Key Points:
-----------
Type Safety: You cannot assign or compare enumerators from different enum class types, which prevents logical errors in the code.
Safer Comparisons: Comparisons between enumerators from different enum class types are not allowed unless explicitly cast.

//=============================================================
Use traditional enum when:
---------------------------
1. You need the enumerators to be implicitly convertible to integers.
2. You are working with legacy code or systems where traditional enum is already in use.
----------------------------
Use enum class when:
----------------------------
You want strong type safety and scoped enumerators.
You want to avoid name clashes and ensure explicit type conversions.
You are designing new systems and prefer modern C++ practices.

Feature	of enum class
=======================
Definition	==> Strongly-typed and scoped enumeration
Implicit Conversion	==> No implicit conversion to int
Scope of Enumerators ==> Scoped within the enum class
Type Safety ==>	Strong type safety, cannot mix enumerators
Requires scoped access (e.g., TrafficLightState::Red)

This scoped and strongly-typed nature of enum class helps in writing more robust, less error-prone code in C++.
