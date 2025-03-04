🔹 2. Message Queues
============================================================
✅ Use Case: Communication between any processes.
Uses message queue identifiers to send/receive messages.
Messages are stored in the queue until read (persistent).
------------------------------------------------------------
📌 Inter-Process Communication (IPC) Using Message Queues in C++
Message queues provide a way for unrelated processes to communicate by sending and receiving structured messages. 
Unlike pipes, message queues persist even after a process terminates until explicitly removed.

🔹 1️⃣ Understanding Message Queues
✔ Persistent: Messages remain in the queue until read.
✔ Multi-Process Communication: Any process with the correct key can access the queue.
✔ Message Types: Each message has a type identifier to help processes filter messages.
✔ System Calls:

msgget(): Create/Get message queue
msgsnd(): Send message
msgrcv(): Receive message
msgctl(): Control (delete) message queue
-------------------------------------------------------------------------------------------
