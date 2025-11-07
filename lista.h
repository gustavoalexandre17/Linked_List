#ifndef LISTA_H
#define LISTA_H

// Incluído para definições como NULL
#include <stddef.h>

// DEFINIÇÃO DAS ESTRUTURAS
typedef struct No {
  void *valor;
  struct No *proximo;
} No;

typedef struct Lista {
  No *inicio;
} Lista;

// PROTÓTIPOS DAS FUNÇÕES
// (Nomes padronizados para bater com seu main.c)

Lista *criar_lista();

void inserir_lista_inicio(Lista *L, void *valor, int tamanho);

void inserir_lista_final(Lista *L, void *valor, int tamanho);

void visualizar_lista(Lista *L, int tamanho);

void free_lista(Lista *L);

No *buscar_elemento(Lista *L, void *valor, int tamanho);

void remover_elemento(Lista *L, void *valor, int tamanho);

#endif
