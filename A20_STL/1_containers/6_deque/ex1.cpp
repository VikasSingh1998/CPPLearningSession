// deque<int> dq; ==> create an empty deque.
// deque<int> dq(4,5); ==> create a deque of size 4 and all the elements are initialized with 5.
// deque<int> dq(iterator begin,iterator end); ==> copy [begin,end-1] from other contianer like vector and list.
// deque<int> dq(dq1)==> copy the content of another deque to this deque.
//======================================================================
// iteraotrs ==> are present in the deque
// begin,end and rbegin,rend
//----------------------------------------------------------------------
// Accessing the element
// by using the index ==> dq[index]
// by using the at() function ==> dq.at(index)
//-------
// dq.front() ==> return the front value.
// dq.back() ==> return the back value.
//=======================================================================
// Modifier function
//  --------------------
//  dq.assign({1,2,3}); ==> initially if the dq contain something then all the value will be removed and assigned with new value.
// dq.push_back(value) ==> push the value from the back.
// dq.push_front(value) ==> push the value from the front.
//  dq.pop_back() ==> remove the value from back,but not return
//  dq.pop_front() ==> remove the value from front,but not return
//========================================================================
//  insert(iterator) ==>
//  erase(iterator) ==>
//------------
//  dq.clear() ==> clear the deque
//  dq.swap(dq1) ==> swap both the deque.

