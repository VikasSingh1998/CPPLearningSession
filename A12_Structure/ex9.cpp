// Complex structure with pointers example

#include <iostream>
#include <string>
using namespace std;

// Structure for a Skill
struct Skill {
    string name;
    int level; // 1 to 10

    Skill(string n = "", int l = 0) : name(n), level(l) {}
};

// Structure for an Employee
struct Employee {
    string name;
    int id;
    int skillCount;
    Skill* skills; // Dynamic array of skills

    Employee(string n, int i, int sc) : name(n), id(i), skillCount(sc) {
        skills = new Skill[skillCount]; // Allocate memory for skills
    }

    // Destructor to free memory
    ~Employee() {
        delete[] skills;
    }
};
//=======================================================================================================
Q: Skill* skills; // Dynamic array of skills 
this is the structure pointer so this can point to the array which contains the structure of this type??

Ans ==> 
Yes, that's correct! 
Skill* skills; // Dynamic array of skills
declares a structure pointer that can point to a dynamically allocated array of Skill structures.

What Happens Here:
Pointer Declaration:
---------------------
Skill* skills; declares skills as a pointer to a Skill type.
It does not allocate memory yet; it only creates the pointer.

Dynamic Array:
-------------
When memory is dynamically allocated using new, the pointer (skills) can point to the first element of an array of Skill structures.

Pointer and Array Relationship:
-------------------------------
In C++, an array's name acts as a pointer to the first element of the array.
Similarly, a pointer (Skill*) can point to the first element of a dynamically allocated array of Skill structures.
------------------------------------------------------------------------------------------------------------------------
Example:
#include <iostream>
#include <string>
using namespace std;

struct Skill {
    string name;
    int level;

    // Constructor to initialize Skill
    Skill(string n = "", int l = 0) : name(n), level(l) {}
};

int main() {
    int skillCount = 3; // Number of skills

    // Declare a structure pointer
    Skill* skills;

    // Dynamically allocate memory for an array of Skill structures
    skills = new Skill[skillCount];

    // Initialize the array elements
    skills[0] = Skill("C++", 8);
    skills[1] = Skill("Python", 7);
    skills[2] = Skill("Java", 6);

    // Access elements using the pointer
    for (int i = 0; i < skillCount; ++i) {
        cout << "Skill: " << skills[i].name << ", Level: " << skills[i].level << endl;
    }

    // Free the dynamically allocated memory
    delete[] skills;

    return 0;
}
====================================================================================
Q: Can it point to any other array of different data types?
Ans ==> 
No, a pointer declared to point to a specific data type, such as Skill*, 
cannot directly point to an array of a different data type. In C++, 
pointers are type-specific, meaning:
# A Skill* pointer can only point to memory locations containing Skill objects.
# Attempting to assign it to an array of a different data type (e.g., int[] or double[]) will result 
  in a type mismatch error or undefined behavior if forced through a cast.
------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
struct Skill {
    string name;
    int level;
};

int main() {
    Skill* skills;
    skills = new int[6];//error: cannot convert ‘int*’ to ‘Skill*’ in assignment
    skills = new Skill[5];//Correct

    return 0;
}
----------------------------------------------------------------------------------------------------
Q: What If You Really Need to Point to a Different Data Type?
Ans ==> 
  You can use void pointers (void*) if you want a generic pointer that can point to any data type. 
  However, you lose type safety and need to cast the pointer back to the correct type before use.
-----------------------------------------------------------------------------------------------------








  
