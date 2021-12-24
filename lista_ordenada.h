//
// Created by rhuan on 06/11/2021.
//

#ifndef QUADRADO_Lista_Ordenada_H
#define QUADRADO_Lista_Ordenada_H

#include "item.h"
#define N 1000

typedef struct lista_ordenada Lista_Ordenada;

Lista_Ordenada  *criar_lista_ordenada();
void liberar_lista_ordenada(Lista_Ordenada **l);
void exibir_lista_ordenada(Lista_Ordenada *l);
int lista_ordenada_cheia(Lista_Ordenada *l);
int lista_ordenada_vazia(Lista_Ordenada *l);
int lista_ordenada_tamanho(Lista_Ordenada *l);
int inserir_ordenada(Lista_Ordenada *l, Item *i);
int remover_inicio_lista_ordenada(Lista_Ordenada *l);
int remover_meio_lista_ordenada(Lista_Ordenada *l, unsigned int k);
int remover_fim_lista_ordenada(Lista_Ordenada *l);
void esvaziar_lista_ordenada(Lista_Ordenada *l);
int busca_sequencial_ordenada(Lista_Ordenada *l, unsigned int chave);
int busca_binaria_lista_ordenada(Lista_Ordenada *l, unsigned int lado);
Lista_Ordenada *merge(Lista_Ordenada *l1, Lista_Ordenada *l2);
void imprimir_inserir_ordenada(Lista_Ordenada *l);
void imprimir_busca_ordenada(Lista_Ordenada *l);

#endif //QUADRADO_Lista_Ordenada_H
