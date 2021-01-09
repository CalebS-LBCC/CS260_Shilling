Interesting Data Structures and Functions:

Simple sorting algorithms can be quick and simple for small data sets, but for
larger sets, a simple 3 line sort is incredibly inefficent. How do you sort a
list that contains a billion elements?

Stacks appear to be a simple way to store data that needs to be read in a
particular order without iterating through a list. Creating a stack class with
appropriate functions could allow a programmer to iterate through an entire
stack with only a while loop checking for the end of the stack without even
knowing the length of the stack.
https://en.wikipedia.org/wiki/Stack_(abstract_data_type)

Binary trees allow a program to look for stored data in an efficient way.
Data is stored in a way where search time is proportional to the log of the
number of nodes instead of proportional to just the number of nodes.
https://en.wikipedia.org/wiki/Binary_search_tree#Searching

One of the future things in this class I really want to learn about is hashing
as it seems very useful for database storage, but I don't really understand
the functions that go alongside it.
https://searchsqlserver.techtarget.com/definition/hashing#:~:text=Hashing%20is%20the%20transformation%20of,it%20using%20the%20original%20value.

I have used singleton design patterns for the implementation of mechanical
systems with a handful of subsystems that required crosstalk between the two.
Having only one instance of each class makes the workflow smoother as there
is no need to send data up and down chains of functions just to deliver a
single value from one subsystem to another: the subsystem can simply ask the
other subsystem for the needed value.
https://en.wikipedia.org/wiki/Singleton_pattern

Difficult Concepts:

Recursion- Going beyond surface-level knowledge to develop simple and
efficient solutions to a task.

Pointers- Pointers are valuable and important to use in languages that
support them. I need more experience with dynamic allocation of pointers and
how to make pointer functions simpler.

Image Processing- Cameras capable of capturing images for image processing is
an essential step up from traditional mechanical sensors. Image processing can
be reprogrammed on the fly to search for completely different data, but
knowledge of how these algorithms work is very niche.

Data Transfer: How is data copied from place to place? What processes have to
occur to transfer data across a continent?

Compilers: Code must be transformed into a format that a human can read into
an executable. This is either done using a compiler to convert code into an
executable as is done in C/C++, or a runtime engine to convert code to
instructions on-the-fly as is done in Java or Python.
