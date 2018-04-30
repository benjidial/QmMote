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

void remove_left(struct list *list) {
  for (int i = 1; i < list->length; i++)
    (*list)[i - 1] = (*list)[i];
  list->length--;
}

void insert_left(struct list *list, struct list_entry entry) {
  for (int i = list->length; i >= 0; )
    (*list)[i] = (*list)[--i];
  (*list)[0] = entry;
}

void run(FILE *in, int close_when_done) {
  char buffer[MAX_WORD_LENGTH];
  struct list lists[27];
  lists[24].length = 1;
  lists[24].entries[0] = (struct list_entry){.is_string = 0, .num = 0};
  lists[26].entries[0] = (struct list_entry){.is_string = 1, .string = "START"};
  do
    lists[26].entries[++lists[26].length] = (struct list_entry){.is_string = 1};
  while (fscanf(in, " %s", lists[26].entries[lists[26].length].string));
  if (close_when_done)
    fclose(in);
  lists[1].length = 1;
  lists[1].entries[0] = (struct list_entry){.is_string = 1, .string = ":"};
  lists[19].length = 1;
  lists[19].entries[0] = (struct list_entry){.is_string = 1, .string = " "};
  while (++lists[24].entries[0].num <= list[26].length)
    if (!strcmp(INSTR, "^_^"))
      /*TODO*/;
    else {
      #define INSTR lists[26].entries[lists[24].entries[0].num].string
      int id = lists[1].entries[0].string[0] - ('A' - 1);
      if (id == ':' - 'A' + 1)
        id = 0;
      struct *_list = *(lists[id]);
      #define &LIST _list
      #define LIST (*_list)
      id = INSTR[0] - ('A' - 1);
      if (id == ':' - 'A' + 1)
        id = 0;
      struct *_face = *(lists[id]);
      #define &FACE _face
      #define FACE (*_face)
      switch (INSTR[strlen(INSTR - 1)]) {
      case 'O':
        /*TODO*/
        break;
      case 'C':
        struct list_entry tmp = {.is_string = 0, .num = FACE.length};
        insert_left(&LIST, tmp);
        break;
      case '<':
        if (LIST.entries[0].is_string) {
          struct list_entry tmp;
          tmp.is_string = 1;
          strcpy(tmp.string, LIST.entries[0].string);
          insert_left(&FACE, tmp);
        }
        else
          insert_left(&FACE, LIST.entries[0]);
        remove_left(&LIST);
        break;
      case '>':
        FACE.entries[FACE.length++] = LIST.entries[--LIST.length];
        break;
      case '[':
        if (LIST.entries[0].is_string) {
          struct list_entry tmp;
          tmp.is_string = 1;
          strcpy(tmp.string, LIST.entries[0].string);
          insert_left(&FACE, tmp);
        }
        else
          insert_left(&FACE, LIST.entries[0]);
        break;
      case ']':
        FACE.entries[FACE.length++] = LIST.entries[LIST.length - 1];
        break;
      case 'V':
        /*TODO*/
        break;
      case 'D':
        FACE.length = LIST.length;
        for (int i = 0; i < FACE.length; i++)
          FACE.entries[i] = LIST.entries[i];
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
        if (FACE.entries[0].is_string)
          printf("%s", FACE.entries[0].string);
        else
          printf("%d", FACE.entries[0].num);
        remove_left(&FACE);
        break;
      case '7':
        /*TODO*/
        break;
      case 'L':
        /*TODO*/
        break;
      case '#':
        /*TODO*/
        break;
      case '$':
        /*TODO*/
        break;
      case '{':
        /*TODO*/
        break;
      case '}':
        /*TODO*/
        break;
      case '\\':
        /*TODO*/
        break;
      case '/':
        /*TODO*/
        break;
      case '(':
        /*TODO*/
        break;
      case ')':
        /*TODO*/
        break;
      case '|':
        /*TODO*/
        break;
      case '3':
        /*TODO*/
        break;
      case 'E':
        /*TODO*/
        break;
      default:
        int n = atoi(INSTR);
        if (n || INSTR[0] = '0')
          LIST.entries[LIST.length++] = (struct list_entry){.is_string = 0, .num = n};
        else {
          LIST.entries[LIST.length].is_string = 1;
          strcpy(LIST.entries[LIST.length++].string, INSTR);
        }
      }
    }
}

int main(int argc, char **argv) {
  if (argc == 1) {
    run(stdin, 0);
    return 0;
  }
  FILE *fptr;
  int (i = 1; i <= argc; i++)
    if (fptr = fopen(argv[i], "r"))
      run(fptr, 1);
    else
      fprintf(stderr, "Could not open file '%s'.\n", argv[i]);
  return 0;
}
