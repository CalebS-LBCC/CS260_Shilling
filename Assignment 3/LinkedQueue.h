#include <stdlib.h>
#include "node.h"

/**
 * @brief A linked queue class with basic memory management.
 * @author Caleb Shilling
 * @date 1/20/2021
 */ 
template<typename T>
class LinkedQueue{
public:
    int size = 0; // Length of the queue.
    /**
     * Creates a node at the end of the list of type T and fills it. 
     * 
     * If the list is empty, a starting node is defined. If the list is not 
     * empty, the list scrolls to the final entry and points it to the new 
     * node. All nodes are created through malloc.
     * 
     * @param inputValue    The value to place in the new node.
     */ 
    void enqueue(T input_value){   
        if(size == 0){
            start_node = (struct Node<T>*)std::malloc(sizeof(Node<T>));
            (start_node)->value = input_value;
        }else{
            to(size-1);
            struct Node<T>* new_node = (struct Node<T>*)std::malloc(sizeof(struct Node<T>));
            new_node->value = input_value;
            current_node->next_node = new_node;
        }   
        size++;
    }
    /**
     * Dequeue the first position in the queue.
     * 
     * Checks if the list is empty. Throws error if empty, otherwise loads the
     * value in the first node. Frees the first node, then promote the second
     * node to first node if the list is longer than one entry.
     * 
     * @return  Returns the value of the first node.
     */
    T dequeue(){
        if(size == 0){
            throw "Attempted to dequeue a list with no entries.";
        }

        T out = start_node->value;
        if(size != 1){
            current_node = start_node->next_node;
            free(start_node);
            start_node = current_node;
        }else{
            free(start_node);
        }
        
        size--;
        return out;  
    }
    /**
     * Looks at the value at the selected index.
     * 
     * Moves the current node to the node at the index, and returns the value
     * there. The list is zero indexed, so 0 is the index of the first value.
     * 
     * @param index The index to peek at.
     * @return      The value at the index.
     */ 
    T peek(int index){
        to(index);
        return current_node->value;
    }

private:
    struct Node<T>* start_node;
    struct Node<T>* current_node;
    /**
     * Sets the current node to the node at the specified index.
     * 
     * @param pos   The index to move to.
     */ 
    void to(int pos){
        current_node = start_node;
        if(size != 1){
            for(int i = 0; i < pos; i++){
                current_node = current_node->next_node;
            }
        }
    }
};