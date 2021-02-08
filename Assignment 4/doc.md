Insert:
The program will attempt to insert a value at the index specified.
Index 0: insert at front
Index n+1: insert at back

insert at front: Create a new start node, assign value to it, point it to the old start node
insert at back: navigate to the back of the list, create a new node, assign value, point previous node to new node
insert elswhere: navigate to n-1, save it, navigate to n. Create new node, assign value,
point previous node to new node, point new node to next node.

Remove:
The program will attempt to remove a value at the index specified.
Index 0: delete front and set front to next node
remove the back: navigate to back, free back, decrement size.=
remove n: navigate to n-1, save it, navigate to n, set the next node of n-1 to n+1, free n.

Delete front: load next, delete front, set front to loaded node
Delete back: navigate to back, free back
