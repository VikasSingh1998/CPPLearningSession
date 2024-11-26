Template:
=========
Template allows you to write the generic code.
We can create a single function or class which can work with different data types.
Main purpose → reusability and flexibility.
Types of templates 
Function template ⇒ Used to define a single function that can operate on different data types.
Class template ⇒ Used to define a class that can handle various data types.
===============================================================================================================
Function Templates
—------------------
Syntax:

template <typename T> 
T FunctionName(T parameter1, T parameter2, ...) 
{ 
  // Function body 
  // Use T as the data type within the function 
}
Key Points:
template <typename T>: Declares a template where T is a placeholder for a data type.
You can also use template <class T> (both typename and class work the same in this context).

T: Represents the generic data type that is replaced with a specific type when the function is called.
ReturnType: The return type can also use T or any other type.
The function can use T for its parameters, return type, or even inside the body.
—-------------------------------------------------------------------------------------------------------------------------


