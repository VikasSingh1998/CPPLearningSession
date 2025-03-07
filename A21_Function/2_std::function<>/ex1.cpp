1️⃣ What is std::function<>?
🔹 std::function<> is a general-purpose function wrapper that can store:
==> Lambda functions
==> Function pointers
==> Functor (Function objects)
==> Member functions (with std::bind)
==> Any callable entity with a matching signature

🔹 Basic Syntax:
std::function<return_type(parameter_types)> func_name;
---------------------------------------------------------------------------
2️⃣ Why Use std::function<>?
Without std::function<>, we would be limited to using function pointers or lambdas directly. std::function<> allows:

✅ Flexibility: You can change the function dynamically.
✅ Uniformity: Works with lambdas, function pointers, functors, and member functions.
✅ Storing Callables in Containers: Can store multiple function types in STL containers like std::vector.
✅ Callbacks: Used in event-driven programming.
---------------------------------------------------------------------------
4️⃣ Summary: When to Use std::function<>?
------------------------------------------
Feature	                                       std::function<>
-----------------------------------------------------------------
Store function pointers                           ✅ Yes
Store lambda functions                            ✅ Yes
Store functors (objects with operator())        	✅ Yes
Store member functions (std::bind)	              ✅ Yes
Change function dynamically	                      ✅ Yes
Useful for callbacks	                            ✅ Yes
---------------------------------------------------------------------------
