/* Example code for Exercises in C.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void free_anything(int *p) {
    free(p);
}

int read_element(int *array, int index) {
    int x = array[index];
    return x;
}

int main ()
{
    int never_allocated;
    int *free_twice = malloc (sizeof (int));
    int *use_after_free = malloc (sizeof (int));
    int *never_free = malloc (sizeof (int));
    int array1[100];
    int *array2 = malloc (100 * sizeof (int));

    // valgrind does not bounds-check static arrays
    read_element(array1, 0);
    read_element(array1, 99);
    // array 1 not malloc'ed so dont free

    // but it does bounds-check dynamic arrays
    read_element(array2, 0);
    read_element(array2, 99);

    // don't need array 2 anymore
    free(array2);

    // and it catches use after free
    *use_after_free = 17;
    free(use_after_free);
    
    // never_free is definitely lost
    *never_free = 17;

    // the following line would generate a warning
    // free(&never_allocated);

    // but this one doesn't
    // dont need to free a non-allocated thing
    // free_anything(&never_allocated);
    
    free(free_twice);
    // dont free twice
    // free(free_twice);

    free(never_free); // I know it says to never free it but really
    return 0;
}
