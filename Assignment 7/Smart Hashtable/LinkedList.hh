#include <stdlib.h>
#include <string.h>
#include "node.hh"

/**
 * @brief A linked list class with basic memory management.
 * @author Caleb Shilling
 * @date 1/20/2021
 */ 
template<typename T>
class LinkedList{
public:
    int size = 0; // Length of the queue.
  
    /**
     * Inserts a value at the end of the list.
     * 
     * Creates a new node and ties the rest of the list into it. Will
     * automatically set out of bounds values to the last value in the
     * list.
     * 
     * @param input_value   The value the new list postition will have.
     * @param key           The key to be saved in the list.
     */ 
    void append(T input_value, char key[5]){

        if(size == 0){
            start_node = new Node<T>;
            (start_node)->value = input_value;
            strcpy(start_node->key, key);
        }else{      
            Node<T>* new_node = new Node<T>;
            strcpy(new_node->key, key);
            new_node->value = input_value;
            while(next());
            current_node->next_node = new_node;
        }
        size++;
    }

    /**
     * Overwrites the data at the current node location.
     * 
     * @param value The value that will be written over the previous value.
     */
    void overwrite(T value){
        current_node->value = value;
    }

    /**
     * Peek the value in the current node and return it.
     * @returns     The value at the current node.
     */
    T peek(){
        return current_node->value;
    }

    /**
     * Checks if the key of the current node is equal to a user input.
     * 
     * @param key   The key to compare to the stored key.
     * @returns     If the keys are equal.
     */
    int checkKey(char key[5]){
        if(strcmp(key, current_node->key) == 0)
            return 1;
        return 0;
    }

    /**
     * Moves the current node down one position in the list.
     * 
     * @returns If there was a next node.
     */ 
    int next(){
        if(current_node->next_node){
            current_node = current_node->next_node;
            return 1;
        }
            return 0;
    }

    /**
     * Sets the current node to the start node.
     * 
     * @returns If the list has been initiated.
     */
    int reset(){
        if(size == 0)
            return 0;
        current_node = start_node;
        return 1;
    }

private:
    struct Node<T>* start_node;
    struct Node<T>* current_node;   
};