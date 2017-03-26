/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
 * 
 * val: value to store in the node.
 * next: pointer to the next node
 *
 * returns: pointer to a new node
 */
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
 * 
 * list: pointer to pointer to Node
 */
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
 * 
 * list: pointer to pointer to Node
 *
 * returns: int or -1 if the list is empty
 */
int pop(Node **list) {
    // FILL THIS IN!
    return 0;
}


/* Adds a new element to the beginning of the list.
 * 
 * list: pointer to pointer to Node
 * val: value to add
 */
void push(Node **list, int val) {
    Node *newNode = malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = *list;
    *list = newNode;
}


/* Removes the first element with the given value
 * 
 * Frees the removed node.
 *
 * list: pointer to pointer to Node
 * val: value to remove
 *
 * returns: number of nodes removed
 */
int remove_by_value(Node **list, int val) {
    Node *currNode = *list;
    if (currNode->val == val) {
        if (currNode->next == NULL) {
            currNode = NULL;
            return 1;
        }
    }

    Node *prevNode = currNode;
    currNode = currNode->next;
    while (currNode != NULL) {
        if (currNode->val == val) {
            prevNode->next = currNode->next;
            return 1;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}


/* Reverses the elements of the list.
 *
 * Does not allocate or free nodes.
 * 
 * list: pointer to pointer to Node
 */
void reverse(Node **list) {
    Node *prevNode = NULL;
    Node *currNode = *list;
    Node *nextNode = currNode->next;

    while (nextNode != NULL) {
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
        nextNode = currNode->next;
    }

    currNode->next = prevNode;
    *list = currNode;
}


int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);

    Node **list = &head;
    print_list(list);

    int retval = pop(list);
    print_list(list);

    push(list, retval+10);
    print_list(list);

    remove_by_value(list, 3);
    print_list(list);

    remove_by_value(list, 7);
    print_list(list);

    reverse(list);
    print_list(list);
}
