Structure
==========
1. Structure is a user-defined datatype in c/c++.
2. A structure creates a data type that can be used to group items of possibly different types into a single type.
3. The ‘struct’ keyword is used to create a structure. 
4. The general syntax to create a structure is as shown below:  
        struct structureName
        {
            member1;
            member2;
            member3;
            .
            .
            .
            memberN;
        };

5. Structures in C++ can contain two types of members:  
Data Member: These members are normal C++ variables. We can create a structure with variables of different data types in C++.
Member Functions: These members are normal C++ functions. Along with variables, we can also include functions inside a structure declaration.
-----------------------------------------------------------------------------
How to Declare the Structure Variable ?
=================================
A structure variable can either be declared with structure declaration or as a separate declaration like basic types. 
-------------------------------------------------------------------
A variable declaration with structure declaration.
struct Point
{
int x, y;
} p1; // The variable p1 is declared with structure 'Point'
-------------------------------------------------------------------
struct Point
{
int x, y;
} p2,p3,p4; // We can declare the multiple variable
-------------------------------------------------------------------
struct Point
{
int x, y;
};
int main()
{
struct Point p1; // The variable p1 is declared like a normal variable
}
====================================================================










