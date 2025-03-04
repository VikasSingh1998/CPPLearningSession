Theory+Code
-----------
The mkfifo command in Linux creates a FIFO (First-In-First-Out) special file that allows processes to communicate with each other. 

What does mkfifo do? 
==> Creates a FIFO file, Sets permissions for the FIFO file, and Creates intermediate directories if needed. 
--------------------------------------------------------------------------------------------------------------------------------------
🔹 Named Pipes (FIFO) Example
================================
Unlike unnamed pipes (pipe()), Named Pipes (FIFO) allow communication between any two processes, even unrelated ones.

✅ How Named Pipes Work
A named pipe (FIFO) is created using mkfifo().
One process writes to the FIFO.
Another process reads from the FIFO.
Works like a file – processes open it using open(), write data, and close it.

🔹 Example: Communication Between Two Separate Processes
We will create two programs:
Writer (fifo_writer.cpp) → Writes data to FIFO
Reader (fifo_reader.cpp) → Reads data from FIFO
--------------------------------------------------------------------------------------
Step 1: Create Named Pipe (FIFO)
Before running the programs, create a named pipe using the command:==> mkfifo myfifo
This creates a special file myfifo, which acts as a pipe.
---------------------------------------------------------------------------------------
🔹 1️⃣ FIFO Writer (fifo_writer.cpp)
This program writes data to the FIFO.
Code: 
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

int main() {
    int fd = open("myfifo", O_WRONLY); // Open FIFO for writing
    if (fd == -1) {
        perror("open");
        return 1;
    }

    const char* msg = "Hello from Writer!";
    write(fd, msg, strlen(msg) + 1); // Write message
    std::cout << "Message sent: " << msg << std::endl;

    close(fd); // Close FIFO
    return 0;
}
✅ This program writes the message "Hello from Writer!" into the FIFO file.
-------------------------------------------------------------------------
🔹 2️⃣ FIFO Reader (fifo_reader.cpp)
This program reads data from the FIFO.

Code: 
#include <iostream>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("myfifo", O_RDONLY); // Open FIFO for reading
    if (fd == -1) {
        perror("open");
        return 1;
    }

    char buffer[100];
    read(fd, buffer, sizeof(buffer)); // Read message
    std::cout << "Message received: " << buffer << std::endl;

    close(fd); // Close FIFO
    return 0;
}
✅ This program reads the message from myfifo and prints it.
-------------------------------------------------------------------------
🔹 Running the Programs
Step 1: Create FIFO (if not already created)
==> mkfifo myfifo
-------------------------------------------------------------------------
Step 2: Run the Reader First (it waits for data)
g++ fifo_reader.cpp -o reader
./reader

Note: (It will wait until the writer sends data.)
-------------------------------------------------------------------------
Step 3: Run the Writer in another terminal
g++ fifo_writer.cpp -o writer
./writer
-------------------------------------------------------------------------
🔹 Output in Reader Terminal:
Message received: Hello from Writer!
  
🔹 Output in Writer Terminal:
Message sent: Hello from Writer!
-------------------------------------------------------------------------
🔹 Summary
✅ Named Pipes (FIFO) allow any two processes to communicate.
✅ Works like a file – processes open, read, and write.
✅ Persistent – remains in the system until deleted (rm myfifo).




