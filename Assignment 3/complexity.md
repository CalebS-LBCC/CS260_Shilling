Analyze the complexity of your implementations (at least the run-time of the add, remove, and peek methods).
My enqueue method requires the program to scroll through the entire list to
append a value to the end. The time to enqueue a value increases linearly as
the size of the dataset does. This means it grows at a rate of O(n).
My dequeue method removes the value from the front of the list. The length
of this function does not depend on the size of the dataset. Therefore, the
function is described by O(1).
Peek is similar to enqueue, where it must scroll to the postition of the index.
Therefore, the time required is equivalent to O(n).