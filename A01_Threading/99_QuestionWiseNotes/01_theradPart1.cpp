1. Process kya hai?
Ans ==> 
Process ek independent program hota hai jo system me run ya execute ho raha hota hai.
--> Har process ka apna memory space hota hai (code, data, stack, heap).
--> Har process ke paas apna CPU registers, program counter, aur resources hote hain.
--> Processes ek dusre se independent hote hain. Ek process crash ho jaye toh doosre process par koi effect nahi hota.
--> Process create karna ya switch karna heavyweight hota hai (zyada resources lagte hain).
--> Agar do processes ek dusre se baat karna chahein, toh IPC (Inter-Process Communication) ka use karna padta hai (pipes, sockets, message queue).
Example: Chrome aur VS Code dono ek saath run kar rahe hain — ye dono alag-alag processes hain.
---------------------------------------------------------------------------------------------------------------------------
2. Thread
Ans ==> 
Thread ko “lightweight process” bhi kaha jaata hai.
Reason:
--> Thread ek process ke andar chalta hai, aur process ke resources share karta hai (jaise memory, files).
--> Thread ka apna stack aur program counter hota hai, lekin heap aur global memory share hoti hai.
--> Thread create karna aur switch karna fast aur cheap hota hai, isliye lightweight kehte hain.
--> Agar process crash ho jaye, toh uske saare threads bhi terminate ho jaate hain.
Example: Browser ke andar rendering thread, network thread, aur UI thread ek hi process ke threads hain.
----------------------------------------------------------------------------------------------------------------------------



  


















  
