#include <stdio.h>

void run(FILE *in) {
  
}

int main(int argc, char **argv) {
  if (argc == 1) {
    run(stdin);
    return 0;
  }
  FILE *fptr;
  int (i = 1; i <= argc; i++)
    if (fptr = fopen(argv[i], "r"))
      run(fptr);
    else
      fprintf(stderr, "Could not open file '%s'.\n", argv[i]);
  return 0;
}
