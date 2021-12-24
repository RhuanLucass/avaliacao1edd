//
// Created by rhuan on 06/11/2021.
//

#ifndef QUADRADO_LISTA_ENCADEADA_H
#define QUADRADO_LISTA_ENCADEADA_H

#include "item.h"
#define N 1000

typedef struct celula Celula;

typedef struct lista_encadeada Lista_Encadeada;

Lista_Encadeada  *criar_lista_encadeada();
void liberar_lista_encadeada(Lista_Encadeada **l);
void exibir_lista_encadeada(Lista_Encadeada *l);
int lista_encadeada_vazia(Lista_Encadeada *l);
int lista_encadeada_tamanho(Lista_Encadeada *l);
int inserir_inicio_lista_encadeada(Lista_Encadeada *l, Item *i);
int inserir_fim_lista_encadeada(Lista_Encadeada *l, Item *i);
int inserir_meio_lista_encadeada(Lista_Encadeada *l, Item *i, unsigned int k);
int remover_inicio_lista_encadeada(Lista_Encadeada *l);
int remover_meio_lista_encadeada(Lista_Encadeada *l, unsigned int k);
int remover_fim_lista_encadeada(Lista_Encadeada *l);
void liberar_celula_lista_encadeada(Celula **c);
int buscar_elemento_lista_encadeada(Lista_Encadeada *l, unsigned int lado);
Lista_Encadeada *concatenar_lista_encadeada(Lista_Encadeada *l1, Lista_Encadeada *l2);
void imprimir_inserir_encadeada(Lista_Encadeada *l);
void imprimir_busca_encadeada(Lista_Encadeada *l);

#endif //QUADRADO_LISTA_ENCADEADA_H
