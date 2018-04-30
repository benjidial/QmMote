#include <stdio.h>
#define MAX_WORD_LENGTH 255
#define MAX_LIST_LENGTH 64

struct list_entry {
  int is_string;
  union {
    int num;
    char string[MAX_WORD_LENGTH];
  };
};

struct list {
  int length = 0;
  struct list_entry entries[MAX_LIST_LENGTH];
};

void run(FILE *in) {
  char buffer[MAX_WORD_LENGTH + 1];
  struct list lists[27];
  while (fscanf(in, " %s", buffer) != EOF) {
    /*TODO*/
  }
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
