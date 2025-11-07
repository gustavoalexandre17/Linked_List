#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Lista *criar_lista() {
  Lista *nova_lista = (Lista *)malloc(sizeof(Lista));

  if (nova_lista != NULL) {
    nova_lista->inicio = NULL; // significa que a lista esta vazia
  }
  return nova_lista;
}

/*
void inserir_lista_inicio(Lista *L, void* valor) {
  No *novo_no = (No *)malloc(sizeof(No));

  if (novo_no != NULL) {
    novo_no->valor = valor;
  }

  novo_no->proximo = L->inicio;
  L->inicio = novo_no;
}
*/

void inserir_lista_final(Lista *L, void *valor, int tamanho) {
  No *novo_no = (No *)malloc(sizeof(No));
  if (novo_no != NULL) {
    memcpy((void *)novo_no->valor, valor, tamanho);
  }

  // percorrendo a lista
  No *aux = L->inicio;
  while (aux->proximo != NULL) {
    aux = aux->proximo;
  }
  aux->proximo = novo_no;
  novo_no->proximo = NULL; // fim da lista
}

/*
No *buscar_elemento(Lista *L, void* valor, int tamanho) {
  No *atual = L->inicio;
  while (atual != NULL) {
    if (atual->valor == valor) {
      return atual;
    }
    atual = atual->proximo;
  }
  return NULL; // nao foi encontrado
}
*/

void visualizar_lista(Lista *L, int tamanho) {
  No *aux = L->inicio;

  while (aux != NULL) {
    printf("%d ", aux->valor);
    aux = aux->proximo;
  }
  printf("\n");
}

/*
void remover_elemento(Lista *L, int valor) {
  No *atual = (L->inicio)->proximo;
  No *anterior = L->inicio;

  while (atual != NULL) {
    if (atual->valor == valor) {
      anterior->proximo = atual->proximo;
      free(atual);
    } else {
      anterior = atual;
      atual = atual->proximo;
    }
  }
}
*/

void free_lista(Lista *L) {
  if (L == NULL)
    return;

  No *atual = L->inicio;
  while (atual != NULL) {
    No *a_liberar = atual;
    atual = atual->proximo;
    free(a_liberar);
  }
  free(L);
}
