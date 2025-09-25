🔹 set क्या है?
-----------------------------------------------------------------------------------
set C++ STL (Standard Template Library) का एक container है।
इसमें unique elements store होते हैं (duplicate नहीं आते)।
Elements हमेशा sorted order में रहते हैं (by default ascending order)।
Internally ये Balanced Binary Search Tree (Red-Black Tree) पर based है।

🔹 Syntax
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;   // integer type का set
    return 0;
}

🔹 Basic Operations on set
1. Insert elements
s.insert(10);
s.insert(20);
s.insert(10); // duplicate ignore होगा


👉 अब set में सिर्फ {10, 20} होगा।

2. Traverse (iterate)
for(auto x : s) {
    cout << x << " ";
}

3. Find an element
if(s.find(20) != s.end()) {
    cout << "20 found\n";
}

4. Erase elements
s.erase(20);   // 20 delete हो जाएगा

5. Size
cout << "Size: " << s.size();
--------------------------------------------------
🔹 Example Program
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;

    // insert
    s.insert(5);
    s.insert(1);
    s.insert(10);
    s.insert(5);  // duplicate ignore

    // print
    cout << "Set elements: ";
    for(auto x : s) cout << x << " ";
    cout << endl;

    // find
    if(s.find(10) != s.end()) cout << "10 is present\n";

    // erase
    s.erase(1);

    cout << "After erase: ";
    for(auto x : s) cout << x << " ";
    cout << endl;

    return 0;
}

Output:
Set elements: 1 5 10
10 is present
After erase: 5 10
