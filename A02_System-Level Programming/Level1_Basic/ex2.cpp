What is fork()
Understanding pid_t pid = fork(); 
-----------------------------------
fork() is a system call used to create a new process (child process) by duplicating the current process (parent process).

🔹 What happens when you call fork()?
--> A new child process is created.
--> The child process is an exact copy of the parent (with a few differences).
--> fork() returns different values in the parent and child:

        Context                             fork() Returns
       ------------------       ----------------------------------
        Parent Process	         Child's PID (Positive Integer)
        Child Process	                      0
        If fork() fails	                -1 (Error)
---------------------------------------------------------------------
=====================================================================
#include <iostream>
#include <unistd.h>
#include <cstring>
using namespace std;

int main()
{
    int fd[2];// File descriptors for pipe
    
    if(pipe(fd) == -1)
    {
        cerr<<"pipe cration fail!!"<<endl;
        return 1;
    }
    cout<<"Pipe is created successfully!!!"<<endl;
    
    //now pipe is created.
    pid_t pid = fork();
    cout<<pid<<endl;

    return 0;
}
/*
Pipe is created successfully!!!
54573
0
*/
--------------------------------------------------------------------------
Explanation:
-------------
🔹 Possible Outputs
Case 1: Successful fork()
--------------------------
If fork() succeeds, two processes execute:
==> Parent process prints PID of the child process (e.g., 12345).
==> Child process prints 0.

Example Output:
PID: 12345  (Printed by Parent Process)
PID: 0      (Printed by Child Process)

Case 2: fork() Fails
----------------------
If fork() fails (e.g., due to system resource limits), it returns -1, and no child is created.

Output:
PID: -1
----------------------------------------------------------------------------------------------------
🔹 Key Observations
1️⃣ Both parent and child execute the same code after fork()!
2️⃣ We can't predict the exact order of execution (depends on OS scheduler).
3️⃣ Parent gets child's PID, child gets 0 (always).
4️⃣ If fork() fails, it returns -1 and no child is created.
=====================================================================================================
