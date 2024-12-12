Inserting Elements in a Map in C++
=====================================
hm.insert({k,v});
==> It will insert the k-v pair in the hm(hash map).
==> IF the key is already present ,even if value is different then it will do nothing.
==> Not good for updating the value.
----------------------------------------------------
If you want to overwrite the value for an existing key:
You can use the subscript operator [] or the at() method:

Ex:
hm[key] = value;
hm.at(key) = value;
----------------------------------------------------
Key Takeaway:
insert() is for adding new elements only; it will not update an existing key-value pair.
Use [] or at() if you need to update the value for an existing key.
=======================================================================================
hm.emplace(key,value);
==> The map emplace() method is similar to map insert() but it inserts the element in-place 
i.e. the construction of the pair takes place inside the map itself avoiding extra copies of the element.
==> We don’t enclose the key-value pair in {} braces.
==> The emplace method in std::unordered_map or std::map does not update the value if the key is already present. 
Instead, it leaves the existing key-value pair unchanged. 
This is because emplace checks if the key already exists before attempting to insert, and it avoids overwriting existing entries.
=======================================================================================

