#include <iostream>
#include <stdlib.h>
#include "LinkedQueue.h"
#include <chrono>

int main(){
    /**
     * Tests will include:
     * Queue 5 objects and ensure the objects are in the queue using peek().
     * Ensure the length of the list is now 5.
     * Dequeue the 5 objects and ensure they are the same objects.
     * Ensure the length of the list is now 0.
     */ 
    int passed = 1;
    LinkedQueue<int> q;

    // Test 1: Queue 5 objects and ensure they are loaded using peek().
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    if(q.peek(0) != 1)
        passed = 0;
    if(q.peek(1) != 2)
        passed = 0;
    if(q.peek(2) != 3)
        passed = 0;
    if(q.peek(3) != 4)
        passed = 0;
    if(q.peek(4) != 5)
        passed = 0;

    // Test 2: Ensure the length of the list is 5.
    if(q.size != 5)
        passed = 0;

    // Test 3: Dequeue the 5 objects and ensure they are the same.
    if(q.dequeue() != 1)
        passed = 0;
    if(q.dequeue() != 2)
        passed = 0;
    if(q.dequeue() != 3)
        passed = 0;
    if(q.dequeue() != 4)
        passed = 0;
    if(q.dequeue() != 5)
        passed = 0;
  
    // Test 4: Ensure the length of the list is 0.
    if(q.size != 0)
        passed = 0;

    printf("The tests ended with the following result: %d\n", passed);
    return passed;
}


