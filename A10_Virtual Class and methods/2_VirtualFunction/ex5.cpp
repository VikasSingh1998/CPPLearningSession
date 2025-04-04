/*
Base *ptrb = &(Base()); in C++ is problematic and could lead to undefined behavior. Here's why:

Explanation:
============
Temporary Object:
-------------------
Base() creates a temporary object of type Base.
Temporary objects in C++ are destroyed at the end of the full expression in which they are created, typically at the end of the statement.

Address of Temporary Object:
-----------------------------
& is used to take the address of the temporary object created by Base().
ptrb is then assigned the address of this temporary object.

Lifetime of the Temporary Object:
----------------------------------
The temporary object created by Base() is destroyed immediately after the statement ends, leaving ptrb pointing to an invalid memory location (a dangling pointer).

Why It's Problematic:
---------------------
Dangling Pointer: After the statement Base *ptrb = &(Base()); completes, ptrb points to memory that is no longer valid, leading to undefined behavior if you try to dereference ptrb or use it in any way.
Undefined Behavior: Accessing or using a dangling pointer can cause crashes, data corruption, or other unpredictable behavior.
============================================================================================================================
Correct Approach:
------------------
If you want ptrb to point to a valid Base object, you should allocate the object on the heap (using new)
or use an automatic (stack-allocated) variable.
------------------
1. using the new

Base *ptrb = new Base(); // Dynamically allocated object
// Don't forget to delete ptrb when done:
delete ptrb;
-------------------
2. Using an Automatic Variable:

Base baseObj;            // Automatic (stack) allocation
Base *ptrb = &baseObj;   // Pointer to the stack-allocated object
==========================================================================
Summary:
Base *ptrb = &(Base()); results in a dangling pointer because it takes the address of a temporary object that is immediately destroyed.
To avoid this, either dynamically allocate the object with new or use an automatic (stack-allocated) object and take its address.
*/

