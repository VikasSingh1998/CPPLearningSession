// In Java, the default behavior of PriorityQueue is indeed to use a min-heap,
// where the smallest element is always at the front of the queue.
// This means that when you remove elements from the priority queue, you'll get them in ascending order (from smallest to largest).
//-------------------------------------------
// On the other hand, in C++, the default behavior of std::priority_queue is to use a max - heap,
// where the largest element is at the front of the queue.
// Consequently, when you remove elements from the C++ priority_queue, you get them in descending order(from largest to smallest).
//-------------------------------------------
// However,it's essential to note that both Java and C++ allow you to customize the behavior of their priority queue implementations.
// In Java, you can specify a custom comparator to create a max-heap instead of a min-heap.
// Similarly, in C++, you can provide a custom comparison function to achieve the same effect.
//--------------------------------------------
//============================================
// bool empty() ==> return true if the queue is empty.
// push(val) ==> push the value into the priority_queue.
// void pop() ==> remove the top element of the priority_queue.
// int top() ==> return the top element of the priority_queue.
// pq1.swap(pq2) ==> swap the two priority queue.
//=============================================
// priority_queue<int> pq; ==> create an empty priotity queue(By default it is maxHeap in CPP).
// we don't have iterators on the priority queue.
//----------
// while creating our own comparator --> to create the minHeap, we have to give the container also,where we have to sotre the value.
//

