#include <iostream>
#include "BinTree.h"

int main(){
    BST bst(30);
    int succeed = 1;
    std::vector<char> buffer;

    // Test 1: Add the values 30, 10, 5, 15, 50, 40, 50, in that order.

    buffer = {'L'};
    if(bst.add(10) != buffer)
        succeed = 0;

    buffer = {'L', 'L'};
    if(bst.add(5) != buffer)
        succeed = 0;

    buffer = {'L', 'R'};
    if(bst.add(15) != buffer)
        succeed = 0;

    buffer = {'R'};
    if(bst.add(50) != buffer)
        succeed = 0;

    buffer = {'R', 'L'};
    if(bst.add(40) != buffer)
        succeed = 0;

    buffer = {'R', 'R'};
    if(bst.add(51) != buffer)
        succeed = 0;

    //printf("%d\n", succeed);

    // Test 2: Delete the tree by deleting the top node until no nodes remain

    // Removing 30 replaces with 40
    if(bst.remove(30) != 40)
        succeed = 0;

    // Removing 40 replaces with 50
    if(bst.remove(40) != 50)
        succeed = 0;

    // Removing 50 replaces with 51
    if(bst.remove(50) != 51)
        succeed = 0;


    // Removing 51 replaces with 10
    if(bst.remove(51) != 10)
        succeed = 0;

    // Removing 10 replaces with 15
    if(bst.remove(10) != 15)
        succeed = 0;

    // Removing 15 replaces with 5
    if(bst.remove(15) != 5)
        succeed = 0;

    // Removing 5 returns INT_MAX (fallback value)
    if(bst.remove(5) != INT_MAX)
        succeed = 0;

    // Removing 5 returns INT_MAX (anit-crash value)
    if(bst.remove(5) != INT_MAX)
        succeed = 0;

    printf("%d\n", succeed);
    return succeed;
}