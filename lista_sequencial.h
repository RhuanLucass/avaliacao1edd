//
// Created by rhuan on 06/11/2021.
//

#ifndef QUADRADO_LISTA_SEQUENCIAL_H
#define QUADRADO_LISTA_SEQUENCIAL_H

#include "item.h"
#define N 1000

typedef struct lista_sequencial Lista_Sequencial;

Lista_Sequencial  *criar_lista_sequencial();
int lista_sequencial_cheia(Lista_Sequencial *l);
int lista_sequencial_vazia(Lista_Sequencial *l);
int lista_sequencial_tamanho(Lista_Sequencial *l);
int inserir_inicio_lista_sequencial(Lista_Sequencial *l, Item *i);
int inserir_fim_lista_sequencial(Lista_Sequencial *l, Item *i);
int inserir_meio_lista_sequencial(Lista_Sequencial *l, Item *i, unsigned int k);
int remover_inicio_lista_sequencial(Lista_Sequencial *l);
int remover_meio_lista_sequencial(Lista_Sequencial *l, unsigned int k);
int remover_fim_lista_sequencial(Lista_Sequencial *l);
void exibir_lista_sequencial(Lista_Sequencial *l);
void liberar_lista_sequencial(Lista_Sequencial **l);
void esvaziar_lista_sequencial(Lista_Sequencial *l);
int buscar_elemento_lista_sequencial(Lista_Sequencial *l, unsigned  int lado);
Lista_Sequencial *concatenar_lista_sequencial(Lista_Sequencial *l1, Lista_Sequencial *l2);
void imprimir_inserir_sequencial(Lista_Sequencial *l);
void imprimir_busca_sequencial(Lista_Sequencial *l);

#endif //QUADRADO_LISTA_SEQUENCIAL_H
