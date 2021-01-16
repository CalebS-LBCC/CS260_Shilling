A linked list structure needs the following abilities:
Add a value at any point in the list
Change a value at any point in the list
Remove a value at any point in the list
Peek at any value in the list

A linked list is made up of nodes where each node links to the next node.
This means that we only need to keep track of the first node in the list
and the length of the list.

To add a value at the end of the list:
Create a new node
Load the final node in the list
Set the final node to point to the new node
Load the new data into the new node

To add a value at the start of the list:
Create a new node
Load the location of the previous first node
Point the new node towards the old node
Load data into the new node
Set the stored first node as the new node.

To add a value at any other point in the list, the list needs to:
Create a new node
Load the node before insertion
Load the node after insertion
Set the node before insertion to point to the new node
Set the new node to point to the node after the insertion
Load a value into the new node
Increment the number of nodes by one

To change a value in the list:
Navigate to the node to change
Swap the data in the node with the new data to be loaded

To peek at any point in the list:
Navigate to the target node
Read the data in the target node

To remove a value at the end of the list:
Load the final node
Free the final node
Decrement the number of nodes by one

To remove the value at the start of the list
Load the first node
Set the stored first node location to be the second node
Free the first node

To remove a value at any other point in the list:
Load the node to be removed
Load the node before the removed node
Load the node after the removed node
Point the previous node to the next node
Free the node to be removed
Decrement the number of nodes by one