#include <stdlib.h>
#include <iostream>
#include <vector>
#include "Node.h"

/**
 * @brief A simple Binary Search Tree.
 * @author Caleb Shilling
 * @date 1/20/2021
 */ 
class BST{
public:

    /**
     * Binary Search Tree constructor.
     * 
     * @param init  The value used to initalize the first node of the BST.
     */ 
    BST(int init){
        start_node->value = init;
        initalized = 1;
    }

    /**
     * Adds a value to the binary tree. Addition is right-heavy.
     * 
     * @param input Value to be added to the right tree.
     * @return      Location where the value was added.
     */ 
    std::vector<char> add(int input){

        out.clear();

        // Locates the position where the new leaf should be added and creates it.
        found = 0;
        current_node = start_node;
        while(!found){

            // Determine which direction the tree should move in.
            if(!initalized){
                start_node->value = input;
                initalized = 1;
            }else if(input < current_node->value){
                // Moves left if possible. If not, creates new leaf with new value.
                out.push_back('L');  
                if(current_node->left){
                    current_node = current_node->left;
                }else{
                    Node* new_node = new Node;
                    current_node->left = new_node;
                    new_node->value = input;
                    new_node->parent = current_node;
                    new_node->id = -1;
                    found = 1;
                }
            }else{
                // Moves right if possible. If not, creates new leaf with new value.
                out.push_back('R');
                if(current_node->right){
                    current_node = current_node->right;
                }else{
                    Node* new_node = new Node;
                    current_node->right = new_node;
                    new_node->value = input;
                    new_node->parent = current_node;
                    new_node->id = 1;
                    found = 1;
                }
            }
        }
        return out;
    }

    /**
     * Removes a value from the binary tree.
     * 
     * @param target    The value set to be removed.
     * @return          The value set to be swapped with the target.
     *                  Returns INT_MAX if no value is being swapped.
     */ 
    int remove(int target){
        //https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/

        // Find the node with the target value.
        current_node = getNode(target);
        if(!current_node or !initalized){
            // Return INT_MAX if the value doesn't exist.
            return INT_MAX;
        }

        // If node has no children, remove the node.
        if(!current_node->left and !current_node->right){
            struct Node* parent;
            if(current_node->id == 1){
                parent = current_node->parent;
                parent->right = nullptr;
            }else if(current_node->id == -1){
                parent = current_node->parent;
                parent->left = nullptr;
            }else{
                initalized = 0;
                return INT_MAX;
            }
            
            free(current_node);
            return INT_MAX;

        }else if(!current_node->left and current_node->right){

            // If a node has one child, set the node to the child and remove the child
            struct Node* child = current_node->right;
            found = child->value;
            current_node->value = child->value;
            current_node->left = child->left;
            current_node->right = child->right;
            free(child);

        }else if(current_node->left and !current_node->right){

            // If a node has one child, set the node to the child and remove the child
            struct Node* child = current_node->left;
            found = child->value;
            current_node->value = child->value;
            current_node->left = child->left;
            current_node->right = child->right;
            free(child);

        }else if(current_node->left and current_node->right){ 

            //http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/9-BinTree/BST-delete2.html

            // If a node has 2 children, find the inorder successor
            struct Node* successor = current_node->right;

            if(!successor->left){
                current_node->value = successor->value;
                current_node->right = successor->right;
                free(successor);
                return current_node->value;
            }

            while(successor->left)
                successor = successor->left;

            current_node->value = successor->value;
            (successor->parent)->left = successor->right;
            free(successor);           
        }

        return current_node->value;
    }


private:
    Node* start_node = new Node;
    struct Node* current_node;
    struct Node* output;
    std::vector<char> out = {};
    int initalized = 0;
    int found = 0;

    /**
     * Gets the target node.
     * 
     * This is safer to use than just Preorder() as it resets some values
     * before calling Preorder().
     * 
     * @param target    The value of the node to return.
     * @return          The node
     */ 
    Node* getNode(int target){
        //https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
        found = 0;
        output = nullptr;
        preorder(start_node, target);
        return output;
    }

    /**
     * Node-finding function.
     * 
     * @param current   The root node passed through recursively.
     * @param target    The value of the node to return.
     */
    void preorder(Node* current, int target){

        if(current->value == target){
            output = current;
            found = 1;
        }

        if(found)
            return;

        if(current->left)
            preorder(current->left, target);

        if(current->right)
            preorder(current->right, target);
    }
};