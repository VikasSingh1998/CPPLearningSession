🔹 Bi-Directional Communication Using Named Pipes (FIFO)
In the previous example, communication was one-way (writer → reader). Now, we will implement two-way communication where two processes can both send and receive messages.

1️⃣ How to Achieve Bi-Directional Communication?
To enable both processes to send and receive data, we need two FIFOs:

"fifo1" → Used by Process A to send data to Process B.
"fifo2" → Used by Process B to send data to Process A.


==================================================================
Do later, not necessary for the interview.
