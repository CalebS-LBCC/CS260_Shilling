#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include "Hashtable.hh"
#include <chrono>
using namespace std::chrono;

int lazy_random(size_t max){
    // Obtain the current time since the epoch in milliseconds
    // https://stackoverflow.com/questions/19555121/how-to-get-current-timestamp-in-milliseconds-since-1970-just-the-way-java-gets
    int epoch_time = duration_cast<milliseconds>(
        system_clock::now().time_since_epoch()
    ).count();
    // Return the remainder of the epoch time divided by the maximum value.
    return epoch_time % max;
}

int main(){
    Hashtable<int> h(100);
    int success = 1;
    int val1;
    int val2;
    char randkey[5];

    /**
     * These tests are a little more complicated than what I have used in the
     * past.
     * 
     * Firstly, the test repeats 500 times with random keys each time. In
     * theory, this means that all positions in the hashtable will be
     * filled and one will have at least 5 members.
     * 
     * The tests generate 2 different integer values in addition to the key.
     * A table position for a particular key is created and a value is stored.
     * This value is then checked, then overwriten with a new value, then checked
     * again. The testing system then moves onto 2 new values with a new key to
     * be hashed.
     */
    for(int i = 0; i < 500; i++){
        // Generate a new key
        for(int i = 0; i <= 3; i++){
            randkey[i] = lazy_random(128);
        }
        randkey[4] = '\0';

        val1 = lazy_random(100);
        val2 = lazy_random(100);
        // Ensure val2 doesn't equal val1
        while(val2 == val1){
            val2 = lazy_random(100);
        }

        // Test 1: Add a value to the hashtable and check it.
        if(!h.insert(randkey, val1))
            success = 0;

        if(h.peek(randkey, -1) != val1)
            success = 0;

        // Test 2: Replace the value and check it.
        if(!h.insert(randkey, val2))
            success = 0;

        if(h.peek(randkey, -1) != val2)
            success = 0;      
    }

    printf("Results: %d\n", success);    
    return success;
}