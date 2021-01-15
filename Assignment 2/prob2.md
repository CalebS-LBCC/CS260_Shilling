A queue needs many functions for it to function properly:
The queue must be able to add a value to the end of the queue with an enqueue function.
The queue must be able to remove a value from the front of the queue with a dequeue function.
A function to "peek" at the top of the queue may be worthwile to implement as well.

However, every time an object is removed from the queue, the rest of the queue must be moved
up to compensate. This makes dequeuing an object far more time consuming than adding one.

The queue also must be smart enough to allocate enough memory to hold enough data and reallocate
when something is added or removed.

In order to make these functions work, the class will need to keep track of the number of objects
in the queue as well as the pointer where the queue starts.