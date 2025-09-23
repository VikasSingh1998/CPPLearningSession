1. Process kya hai?
Ans ==> 
Process ek independent program hota hai jo hamare system me run ye execute hota hai.
Har process ka apna memory space hota hai (code, data, stack, heap).

Har process ke paas apna CPU registers, program counter, aur resources hote hain.

Processes ek dusre se independent hote hain. Ek process crash ho jaye toh doosre process par koi effect nahi hota.

Process create karna ya switch karna heavyweight hota hai (zyada resources lagte hain).

Agar do processes ek dusre se baat karna chahein, toh IPC (Inter-Process Communication) ka use karna padta hai (pipes, sockets, message queue).

Example: Chrome aur VS Code dono ek saath run kar rahe hain — ye dono alag-alag processes hain.
