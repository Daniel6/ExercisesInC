/*
  C implementation of the 'tee' unix command

  Daniel Bishop
*/

#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char** argv) {
  char *output_file;
  int i;
  unsigned int append = 0;
  for (i = 0; i < argc; i++) {
    if (strcmp(argv[i], "-a") == 0) {
      append = 1;
    } else { // needs some sort of check for valid file names
      output_file = argv[i];
    }
  }

  if (output_file != NULL) {
    FILE *f = fopen(output_file, "w"); // check if you cant open the file for some reason
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, stdin)) != -1) { 
      // could be forked here to write simultaneously to stdout and file
      fprintf(stdout, "%s", line);
      fprintf(f, "%s\n", line);
    }

    fclose(f);
    free(line);
  }
  return 0;
}