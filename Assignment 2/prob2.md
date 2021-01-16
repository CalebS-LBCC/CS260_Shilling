A queue needs many functions for it to function properly:
The queue must be able to add a value to the end of the queue with an enqueue function.
The queue must be able to remove a value from the front of the queue with a dequeue function.
A function to "peek" at the top of the queue may be worthwile to implement as well.

In a linked queue, each node stores the location of the next node. Therefore, the only values
we must store is the pointer position of the first node and the number of nodes in the queue.

Enqeue:
Navigate to the final node in the queue. This is the start of the queue.
Create a new node and store the new queue value in it
Set the location of the new node in the old final node.
Increment the length of the queue.

Deqeue:
Load the data in the first node
Change the first node in the queue to the location of the second node
Free the first node
Decrement the length of the queue.

Peek:
Load the first node
Return the value contained in the first node.