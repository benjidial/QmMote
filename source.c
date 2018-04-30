#include <stdio.h>
#include <string.h>
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
  lists[1].entries[0] = (list_entry){.is_string = 1, .string = ":"};
  lists[19].length = 1;
  lists[19].entries[0] = (list_entry){.is_string = 1, .string = " "};
  while (++lists[24].entries[0].num <= list[26].length)
    #define INSTR lists[26].entries[lists[24].entries[0].num].string
    #define LIST lists[/*TODO*/]
    #define FACE lists[/*TODO*/]
    switch (INSTR[strlen(INSTR - 1)]) {
      case 'O':
        /*TODO*/
        break;
      case 'C':
        /*TODO: insert (list_entry){.is_string = 0, .num = FACE.length} in front of LIST.entries*/
        break;
      case '<':
        /*TODO*/
        break;
      case '>':
        FACE.entries[FACE.length++] = LIST.entries[--LIST.length];
      case '[':
        /*TODO*/
        break;
      case ']':
        FACE.entries[FACE.length++] = LIST.entries[LIST.length - 1];
        break;
      case 'V':
        /*TODO*/
        break;
      case 'D':
        /*TODO*/
        break;
      case '@':
        /*TODO*/
        break;
      case 'P':
        if (FACE.entries[0].is_string)
          printf("%s", FACE.entries[0].string);
        else
          printf("%d", FACE.entries[0].num);
        break;
      case 'Q':
      case '7':
      case 'L':
      case '#':
      case '$':
      case '{':
      case '}':
      case '\\':
      case '/':
      case '(':
      case ')':
      case '|':
      case '3':
      case 'E':
      default:
        int n = atoi(INSTR);
        if (n || INSTR[0] = '0')
          LIST.entries[LIST.length++] = (list_entry){.is_string = 0, .num = n};
        else
          LIST.entries[LIST.length++] = (list_entry){.is_string = 1, .string = INSTR};
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
