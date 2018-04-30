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
  char buffer[MAX_WORD_LENGTH];
  struct list lists[27];
  lists[24].length = 1;
  lists[24].entries[0] = (list_entry){.is_string = 0, .num = 0};
  lists[26].entries[0] = (list_entry){.is_string = 1, .string = "START"};
  do
    lists[26].entries[++lists[26].length] = (list_entry){.is_string = 1};
  while (fscanf(in, " %s", lists[26].entries[lists[26].length].string));
  lists[1].length = 1;
  lists[1].entries[0] = (list_entry){.isString = 1, .string = ":"};
  while (++list[24].entries[0].num <= list[26].length)
    /*TODO*/;
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
