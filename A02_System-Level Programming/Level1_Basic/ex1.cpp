/*
Introduction to Pipes in C++ (Inter-Process Communication - IPC)
----------------------------------------------------------------
🔹 What are Pipes?
--------------------
Ans ==> 
A pipe is a mechanism that allows data transfer between two processes. 
It works like a tunnel where one process writes data, and another process reads that data. 
Pipes are one of the simplest forms of Inter-Process Communication (IPC).

🔹 How Pipes Work?
---------------------
Think of a pipe as a one-way communication channel:
--> One process writes data into the pipe.
--> Another process reads data from the pipe.
--> The two processes must be related (like a parent-child relationship).

pipe() Takes an array of two integers (fd[2]) as an argument.
Returns:
  0 on success.
  -1 on failure (sets errno to indicate the error).
File Descriptors (fd[2]):
  fd[0] → Read end of the pipe.
  fd[1] → Write end of the pipe.

🔹 Pipe Characteristics
--------------------------
Unidirectional – Data flows in only one direction.
Requires a common ancestor – The communicating processes must be related (parent-child processes).
Uses File Descriptors – Pipes are treated like files, where:
fd[0] → Used for reading.
fd[1] → Used for writing.
*/
// ========================================================================================================
// Example:
// -------------------
#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
    int fd[2];// File descriptors for pipe
    
    if(pipe(fd) == -1)
    {
        cerr<<"pipe cration fail!!"<<endl;
        return 1;
    }
    else
    {
        cout<<"Pipe is created successfully!!"<<endl;
    }

    return 0;
}
// -----------------------------------------------------------------





















