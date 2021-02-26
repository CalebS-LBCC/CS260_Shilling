A few from https://en.wikipedia.org/wiki/Hash_table

Separate chaining with linked lists
By having collisions reduced to linked lists, it allows a simple
and reasonably fast solution. Complexity is the same as a linked
list, being O(n).

Open Addressing
With a large enough hashtable, you can just "mode down" a slot
if there is a collision. This requires the hashtable to be large than
a chained table, and could cause the hashtable to stop working. However,
this method can be much faster than chaining if the table is sufficently large.

Double Hashing
Double hashing is used in conjunction with Open Addressing, with a second hash
representing the index offset used.