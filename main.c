#include "lista.h"
#include <stdio.h>
int main() {

  Lista *minha_lista = criar_lista();
  inserir_lista_inicio(minha_lista, 10);
  inserir_lista_inicio(minha_lista, 20);
  inserir_lista_inicio(minha_lista, 30);
  inserir_lista_final(minha_lista, 100);
  visualizar_lista(minha_lista);

  int valor;
  /*
    printf("Valor a ser removido: ");
    scanf("%d", &valor);

    remover_elemento(minha_lista, valor);
    visualizar_lista(minha_lista);
  */
  free_lista(minha_lista);
  return 0;
}
