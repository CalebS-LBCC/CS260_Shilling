#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include "Hashtable.hh"

int main(){
    Hashtable<int> h(100);
    int success = 1;
    char key[5] = "test";

    // Test 1: Add a value to the hashtable.

    if(!h.insert(key, 55))
        success = 0;

    // Test 2: Check if the value was added properly.

    if(h.peek(key, -1) == -1)
        success = 0;

    printf("Results: %d\n", success);
    return success;
}