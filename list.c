#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
List *new_list() {
  List *list = (List *)malloc(sizeof(List));
  if (list == NULL)
    return NULL;

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

int list_append(List *list, void *data, int len,
                void (*print_func)(void *data)) {
  Node *no = (Node *)malloc(sizeof(Node));
  if (no == NULL)
    return 0; // error

  no->data = malloc(len);
  if (no->data == NULL) {
    free(no);
    return 0;
  }

  memcpy(no->data, data, len);
  no->next = NULL;
  no->print_func = print_func;

  if (list->size == 0) {
    list->head = no;
    list->tail = no;
  } else {
    list->tail->next = no;
    list->tail = no;
  }
  list->size++;
  return 1;
}

void print(List *list) {
  Node *no = list->head;
  printf("[ ");
  while (no != NULL) {
    no->print_func(no->data);
    no = no->next;
    if (no != NULL)
      printf(" --> ");
  }
  printf(" ]\n");
}

void print_int(void *data) { printf("        %d      ", *(int *)data); }
void print_float(void *data) { printf("    %f   ", *(float *)data); }
void print_string(void *data) { printf("    %s    ", (char *)data); }

void free_list(List *list) {
  if (list == NULL)
    return;

  Node *actual = list->head;
  Node *to_free;
  while (actual != NULL) {
    to_free = actual;
    actual = actual->next;
    free(to_free->data);
    free(to_free);
  }
  free(list);
}
