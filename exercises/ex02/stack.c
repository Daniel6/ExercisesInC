/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;

    // Note: as discussed below, a possible fix would be to malloc the array as such:
    int *array = malloc(SIZE);
    // int array[SIZE]; // create a local array

    printf("%p\n", array); // display the memory address of this local array

    for (i=0; i<SIZE; i++) { // set all elements of this local array to 42
	array[i] = 42;
    }
    return array; // return the memory address of local array
}

void bar() {
    int i;
    int array[SIZE]; // create a local array

    // display the memory address of this local array. It is the same as the address of the local array in foo()
    printf("%p\n", array); 

    for (i=0; i<SIZE; i++) { // set the elements of this array to 0, 1, 2, ...
	array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo(); // create a pointer pointing at the memory address of the local array created in foo()
    bar(); // create and set elements of local array in bar()

    // One would expect that this would print 42 repeatedly, however, since array points to a local variable
    // in a function that has exited, the array has long since been cleaned up. Thus by reading the data that
    // is now at the address where the array used to be, we have undefined behavior.
    for (i=0; i<SIZE; i++) {
	   printf("%d\n", array[i]);
    }

    // If using malloc to prevent this issue, one must also remember to free the resources allocated or risk
    // memory leakage
    free(array);

    return 0;
}
