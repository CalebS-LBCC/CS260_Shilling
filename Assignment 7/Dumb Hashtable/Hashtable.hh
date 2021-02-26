#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include "Hashnode.hh"

/**
 * Dumb hashtable without collision avoidance.
 * @author Caleb Shilling
 * @date 2-25-2021
 */
template<typename T>
class Hashtable{
public:

    int capacity = 0; // The capacity of the hashtable.
    
    /** Constructor. Sets the size of the hashtable. */
    Hashtable(int capacity){
        this->capacity = capacity;
        table.resize(capacity);
    }

    /**
     * Inserts a value into the hashtable. Overwrites any value found.
     * 
     * This could be done with less code, but both my compiler and autocomplete
     * weren't having it.
     * 
     * @param key   Key for the hashtable.
     * @param value Value to inject into the table.
     * @returns     If the operation was successful.
     */
    int insert(char key[5], T value){
        int index = hashIndex(key);
        Hashnode<T> node = table.at(index);
        node.value = value;
        node.filled = 1;
        table.at(index) = node;
        return 1;
    }

    /**
     * Peeks at the value. Returns a default value if none found.
     * 
     * @param key   Key for the hashtable.
     * @param def   Default failure value.
     * @returns     The value at the key if successful, def otherwise.
     */
    T peek(char key[5], T def){
        int index = hashIndex(key);
        Hashnode<T> node = table.at(index);
        if(node.filled == 0){
            return def;
        }
        return node.value;    
    }
private:

    std::vector<Hashnode<T>> table; // Vector for holding the hashtable and internal nodes

    /**
     * Returns the index for a hash key.
     * 
     * @param key   The key to hash.
     * @returns     The index for that hash.
     */
    int hashIndex(char key[5]){
        int hash = 0;
        for(int i = 0; i < key[0]*3+4; i++){
            hash = hash + key[i%4]*key[(i+1)%4];
        }
        return hash % capacity;
    }
};