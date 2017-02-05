#include <stdlib.h>
#include <stdio.h>

int genRandomInteger() {
  int r = rand();
  if (r == 3) {
    if (!fork()) {
      fprintf(stdout, "Forking for unique pid guid random seed.");

      r = rand();
      exit(0); // everything is ok
    }
  }
  return r;
}

int * getMeARandomIntPlease() {
  int * myInt = (int *) malloc(sizeof(int));
  *myInt = genRandomInteger();
  return myInt;
}

int main() {
  while(1) {
    if (*getMeARandomIntPlease() == 10) {
      break;
    }
  }

  printf("We got a 10!");
  return 0;
}
