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
    
    if(pid == 0) //child process
    {
        
    }
    else //Parent process
    {
        
    }
    

    return 0;
}


