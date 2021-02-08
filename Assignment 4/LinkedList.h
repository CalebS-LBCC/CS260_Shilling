#include <stdlib.h>
#include "node.h"

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
     * Inserts a value at an index in the list.
     * 
     * Creates a new node and ties the rest of the list into it. Will
     * automatically set out of bounds values to the last value in the
     * list.
     * 
     * @param input_value   The value the new list postition will have.
     * @param index         The index the value will be placed at.
     */ 
    void insert(T input_value, int index){

        if(index > size or index < 0){
            index = size;
        }

        if(size == 0){
            start_node = new Node<T>;
            (start_node)->value = input_value;
        }else{      
            Node<T>* new_node = new Node<T>;
            new_node->value = input_value;

            if(index == 0){    
                new_node->next_node = start_node;
                start_node = new_node;
            }else if(index == size){
                to(index);
                current_node->next_node = new_node;
            }else{
                to(index-1);
                Node<T>* prev_node = current_node;
                next();
                prev_node->next_node = new_node;
                new_node->next_node = current_node;
            }            
        }
        size++;
    }

    /**
     * Deletes the value at an index and returns it.
     * 
     * Removes the node and ties in the rest of the list if possible.
     * 
     * @param index The index to delete.
     * @return      The value at the deleted index.
     */ 
    T remove(int index){

        if(index > size-1 or index < 0){
            index = size-1;
        }

        if(size == 0){
            throw "Attempted to remove from an empty list";
        }

        T out;

        if(size == 0){
            to(0);
            out = start_node->value;
            free(start_node);
        }else if(index == 0){
            to(1);
            out = start_node->value;
            free(start_node);
            start_node = current_node;
        }else if(index == size){
            to(size-1);
            out = current_node->value;
            free(current_node);
        }else{
            to(index-1);
            Node<T>* prev_node = current_node;
            next();
            prev_node->next_node = current_node->next_node;
            out = current_node->value;
            free(current_node);
        }

        size--;
        return out;
    }

    /**
     * Peek the value at an index and return it.
     * 
     * @param index The index to peek.
     * @returns     The value at the index.
     */
    T peek(int index){
        if(index > size-1 or index < 0){
            index = size-1;
        }
        to(index);
        return current_node->value;
    }

    void printto(int pos){
        current_node = start_node;
        for(int i = 0; i < pos and i < size-1; i++){
            printf("%d\n", current_node->value);
            if(current_node->next_node != nullptr){
                current_node = current_node->next_node;
            }          
        }
        printf("%d\n", current_node->value);
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
                if(current_node->next_node != nullptr){
                    current_node = current_node->next_node;
                }   
            }
        }
    }

    /**
     * Moves the current node down one position in the list.
     */ 
    void next(){
        current_node = current_node->next_node;
    }
};