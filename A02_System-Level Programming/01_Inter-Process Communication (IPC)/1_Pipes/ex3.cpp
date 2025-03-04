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
    
    if(pid == 0) //Child Process (Writes Data)
    {
        close(fd[0]);//child only write the data, so close the read end.
        const char* msg = "Hello Vikas, Good Morning!!";
        write(fd[1],msg,strlen(msg)+1);
        close(fd[1]);//After writing the data, close the write end.
    }
    else //Parent Process (Reads Data)
    {
        close(fd[1]);//Parent only read the data, so close the write end.
        char msg[50];//crate one char array to store the data after reading.
        read(fd[0],msg,sizeof(msg));// Read data from pipe
        cout<<"Parent: "<<msg<<endl;
        close(fd[0]);//After reading, close the read end.
    }
    
    return 0;
}
//==========================================================================
🔹 Code Execution Flow
Parent process creates a pipe.
Parent process forks a child process.
Child writes a message into the pipe.
Parent reads the message from the pipe.
Both processes close their respective pipe ends.
----------------------------------------------------------------------------
