#include "list.h"

int main() {
  int valor1 = 12;
  float valor2 = 12.123;
  char valor3[] = "ai dento";
  float valor4 = 129.78;

  List *list = new_list();

  list_append(list, &valor1, sizeof(valor1), print_int);
  list_append(list, &valor2, sizeof(valor2), print_float);
  list_append(list, &valor3, sizeof(valor3), print_string);
  list_append(list, &valor4, sizeof(valor4), print_float);

  print(list);
  free_list(list);
}
