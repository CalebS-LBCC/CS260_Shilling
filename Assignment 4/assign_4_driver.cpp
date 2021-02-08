#include <iostream>
#include <stdlib.h>
#include "LinkedList.h"
#include <vector>
#include <chrono>

int main(){

    int passed = 1;
    LinkedList<int> list;
    
    // Test 1/2: Add 4 values to the back and insert one at index 1
    // and ensure the values are added in the proper order.
    std::vector<int> t1val = {1,5,2,3,4};
    list.insert(1,-1);
    list.insert(2,-1);
    list.insert(3,-1);
    list.insert(4,-1);
    list.insert(5,1);
    
    for(int i = 0; i < list.size-1; i++){
        if(t1val.at(i) != list.peek(i))
            passed = 0;
    }

    // Test 3/4: Remove the 5 values from the midpoint of the list
    // and ensure they come out properly
    /**
     * I should clarify the expected behavior here:
     * As we are taking values from index 2, numbers will be taken from that index
     * until the index no longer exists. Once this occurs, the back position will
     * be the default, and the remaining objects will be taken from the back.
     * This returns 2,3,4,5,1.
     */ 
    std::vector<int> t2val = {2,3,4,5,1};
    for(int i = 0; i < t2val.size()-1; i++){
        if(t2val.at(i) != list.remove(2))
            passed = 0;
    }

    printf("%d\n", passed);
    return passed;
}


