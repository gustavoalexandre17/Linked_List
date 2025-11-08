#ifndef LISTA_H
#define LISTA_H
#include <stddef.h>

typedef struct Node {
  void *data;
  struct Node *next;
  void (*print_func)(void *data);
} Node;

typedef struct List {
  Node *head;
  Node *tail;
  int size;
} List;

List *new_list();

int list_append(List *list, void *data, int len,
                void (*print_func)(void *data));

void free_list(List *L);

void print_int(void *data);
void print_float(void *data);
void print_string(void *data);

void print(List *L);

#endif
