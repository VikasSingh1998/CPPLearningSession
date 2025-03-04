🔹 2️⃣ Example: Message Queue Communication (Sender & Receiver)
We will create two separate programs for sending and receiving messages.
--------------------------------------------------------------------------
✅ Step 1: Create a Message Structure
Each message consists of:
==> A message type (long type, required).
==> A message text (character array for actual data).

struct message 
{
    long type;       // Required for message queues
    char text[100];  // Message data
};
-------------------------------------------------------------------------
✅ Step 2: Implement the Message Sender
The sender process will:
==> Create/Access the message queue.
==> Send a message with a specific type.

🚀 sender.cpp (Process A)
Code: 
-----
#include <iostream>
#include <sys/ipc.h>  // For ftok()
#include <sys/msg.h>  // For msgget(), msgsnd(), msgrcv(), msgctl()
#include <cstring>    // For strcpy()

// Define message structure
struct message {
    long type;       // Message type (must be long)
    char text[100];  // Message content
};

int main() {
    // Generate a unique key (same for both sender and receiver)
    key_t key = ftok("queuefile", 65);

    // Create or access an existing message queue
    int msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget failed");
        return 1;
    }

    message msg;
    msg.type = 1;  // Message type (used to categorize messages)
    strcpy(msg.text, "Hello from Sender!");  // Copy message text

    // Send message to queue
    if (msgsnd(msgid, &msg, sizeof(msg), 0) == -1) {
        perror("msgsnd failed");
        return 1;
    }

    std::cout << "Sender: Message Sent!" << std::endl;
    return 0;
}
-------------------------------------------------------------------------------
✅ Step 3: Implement the Message Receiver
The receiver process will:
==> Access the message queue.
==> Read the message from the queue.
==> Delete the queue after receiving the message.

🚀 receiver.cpp (Process B) 
Code: 
----
#include <iostream>
#include <sys/ipc.h>  // For ftok()
#include <sys/msg.h>  // For msgget(), msgsnd(), msgrcv(), msgctl()

// Define message structure
struct message {
    long type;       // Message type
    char text[100];  // Message content
};

int main() {
    // Generate the same key as the sender
    key_t key = ftok("queuefile", 65);

    // Access the existing message queue
    int msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget failed");
        return 1;
    }

    message msg;

    // Receive the message (only messages of type 1)
    if (msgrcv(msgid, &msg, sizeof(msg), 1, 0) == -1) {
        perror("msgrcv failed");
        return 1;
    }

    std::cout << "Receiver: Received Message - " << msg.text << std::endl;

    // Remove the message queue after receiving the message
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
----------------------------------------------------------------------------
🔹 3️⃣ Running the Programs
1️⃣ Compile both sender and receiver:
g++ sender.cpp -o sender
g++ receiver.cpp -o receiver

2️⃣ Run the receiver first (waiting for messages):
./receiver
  
3️⃣ Run the sender to send the message:
./sender

4️⃣ Receiver will display the message and delete the queue.

🔹 4️⃣ Expected Output
🔹 In Receiver Terminal
Receiver: Received Message - Hello from Sender!
  
🔹 In Sender Terminal
Sender: Message Sent!

--------------------------------------------------------------------------------
🔹 6️⃣ Why Use Message Queues?
✅ Advantages:
✔ Can communicate between multiple processes.
✔ Messages are persistent (remain in the queue until read).
✔ Can send structured messages (not just byte streams like pipes).

❌ Disadvantages:
✖ More overhead than pipes due to system calls.
✖ Requires explicit message queue management (msgctl()).

🔹 7️⃣ Summary
✔ Message Queues allow multiple processes to communicate via persistent messages.
✔ Each message has a type, making it easy to filter messages.
✔ System calls: msgget(), msgsnd(), msgrcv(), msgctl().
✔ Used when multiple processes need structured communication.

---------------------------------------------------------------------------------
























