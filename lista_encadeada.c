//
// Created by rhuan on 06/11/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista_encadeada.h"
#include "item.h"

#define FLAG_ERRO -1
#define VERDADEIRO 1
#define FALSO 0

struct celula{
    Item *i;
    struct celula *prox;
};

struct lista_encadeada{
    Celula *primeiro, *ultimo;
    int tam, comp_inserir_encadeada, atr_inserir_encadeada, comp_busca_encadeada, atr_busca_encadeada;
};

Lista_Encadeada *criar_lista_encadeada() {
    Lista_Encadeada  *l = (Lista_Encadeada *) malloc(sizeof(Lista_Encadeada));
    if(l == NULL)
        return NULL;
    l->primeiro = (Celula *) malloc(sizeof(Celula));
    if(l->primeiro == NULL) {
        //liberar_lista(&l);
        return NULL;
    }
    l->tam = 0;
    l->ultimo = l->primeiro;
    l->primeiro->prox = NULL;
    l->comp_inserir_encadeada = 0;
    l->atr_inserir_encadeada = 0;
    l->comp_busca_encadeada = 0;
    l->atr_busca_encadeada = 0;
    return l;
}

int lista_encadeada_vazia(Lista_Encadeada *l) {
    return (l->primeiro == l->ultimo);
}

void exibir_lista_encadeada(Lista_Encadeada *l) {
    Celula *aux = l->primeiro->prox;
    if(aux == NULL)
        return;
    printf("   Lista: \n");
    while(aux != NULL){
        imprimir_item(aux->i);
        aux = aux->prox;
    }
}

int inserir_inicio_lista_encadeada(Lista_Encadeada *l, Item *i) {
    Celula *aux = (Celula *) malloc(sizeof(Celula));
    if(aux == NULL)
        return FALSO;
    if(lista_encadeada_vazia(l))
        l->ultimo = aux;
    aux->i = i;
    aux->prox = l->primeiro->prox;
    l->primeiro->prox = aux;
    l->tam++;
}

int inserir_meio_lista_encadeada(Lista_Encadeada *l, Item *i, unsigned int k) {
    if(k == 0)
        inserir_inicio_lista_encadeada(l, i);
    else{
        Celula *atual = l->primeiro, *anterior;

        for(int j = 0; atual != NULL && j <= k; j++){
            anterior = atual;
            atual = atual->prox;
        }
        if(atual == l->primeiro)
            inserir_inicio_lista_encadeada(l, i);
        else{
            Celula *aux = (Celula*) malloc(sizeof(Celula));
            if(aux == NULL)
                return FALSO;
            aux->i = i;
            aux->prox = anterior->prox;
            anterior->prox = aux;
            l->tam++;
        }
    }
    return VERDADEIRO;
}

int inserir_fim_lista_encadeada(Lista_Encadeada *l, Item *i) {
    Celula *aux = (Celula*) malloc(sizeof(Celula));
    if(aux == NULL) {
        l->comp_inserir_encadeada++;
        l->atr_inserir_encadeada+=3; //Contando com a Celula *aux
        return FALSO;
    }

    aux->i = i;
    aux->prox = NULL;

    if(lista_encadeada_vazia(l)) {
        l->primeiro = aux;
        l->tam++;
        l->comp_inserir_encadeada+=3; // lista_encadeada_vazia faz uma comparação e o if outra
        l->atr_inserir_encadeada+=4;
    }
    else{
        Celula *tmp = l->primeiro;
        while(tmp->prox != NULL){
            tmp = tmp->prox;
            l->comp_inserir_encadeada++;
            l->atr_inserir_encadeada+=3;
        }
        tmp->prox = aux;
        l->tam++;

        l->comp_inserir_encadeada+=2;
        l->atr_inserir_encadeada+=5;
    }

    l->atr_inserir_encadeada+=4;
    return  VERDADEIRO;
}

int remover_fim_lista_encadeada(Lista_Encadeada *l) {
    if(lista_encadeada_vazia(l))
        return FALSO;
    Celula *atual = l->primeiro;
    Celula *anterior = atual->prox;
    while(atual->prox != NULL) {
        anterior = atual;
        atual = atual->prox;
    }
    if(atual == l->primeiro){
        free(atual);
        l->primeiro = NULL;
    }
    else{
        free(atual);
        anterior->prox = NULL;
    }
    l->tam--;
    return VERDADEIRO;
}

int remover_inicio_lista_encadeada(Lista_Encadeada *l) {
    if(l->primeiro == NULL)
        return FALSO;
    Celula *aux = l->primeiro;
    l->primeiro = aux->prox;
    free(aux);
    l->tam--;
    return VERDADEIRO;
}

int remover_meio_lista_encadeada(Lista_Encadeada *l, unsigned int k) {
    Celula *anterior;
    Celula *atual = l->primeiro;

    while(atual != NULL && get_chave(atual->i) != k){
        anterior = atual;
        atual = atual->prox;
    }
    if(atual == NULL)
        return FALSO;
    else if(atual == l->primeiro)
        l->primeiro = atual->prox;
    else
        anterior->prox = atual->prox;
    free(atual);
    l->tam--;
}

void liberar_celula_lista_encadeada(Celula **c) {
    liberar_item(&(*c)->i);
    free(*c);
    *c = NULL;
}

void liberar_lista_encadeada(Lista_Encadeada **l) {
    Celula *aux;
    while((*l)->primeiro->prox != NULL) {
        aux = (*l)->primeiro->prox->prox;
        liberar_celula_lista_encadeada(&(*l)->primeiro->prox);
        (*l)->primeiro->prox = aux;
    }
    free((*l)->primeiro);
    (*l)->primeiro = NULL;
    free(*l);
    *l = NULL;
}

int lista_encadeada_tamanho(Lista_Encadeada *l) {
    return l->tam;
}

int buscar_elemento_lista_encadeada(Lista_Encadeada *l, unsigned int lado) {
    Celula *atual = l->primeiro;

    while(atual != NULL && get_itemlado(atual->i) != lado){
        atual = atual->prox;

        l->comp_busca_encadeada+=2;
        l->atr_busca_encadeada+=3;
    }
    if(atual == NULL){
        //printf("Elemento nao encontrado!\n");
        l->comp_busca_encadeada+=2;
        l->atr_busca_encadeada+=3; //Referente a *atual = l->primeiro, l->comp_busca_encadeada+=2 e l->atr_busca_encadeada+=2
        return FALSO;
    }

    l->comp_busca_encadeada+=3;
    l->atr_busca_encadeada+=3;
    //imprimir_item(atual->i);
    return VERDADEIRO;
}

Lista_Encadeada *concatenar_lista_encadeada(Lista_Encadeada *l1, Lista_Encadeada *l2) {
    l1->ultimo->prox = l2->primeiro->prox;
    l1->tam += l2->tam;
}

void imprimir_inserir_encadeada(Lista_Encadeada *l) {
    printf("   INSERIR FIM - ENCADEADA\nNumero de comparacoes: %d\nNumero de atribuicoes: %d\n\n", l->comp_inserir_encadeada, l->atr_inserir_encadeada);
}

void imprimir_busca_encadeada(Lista_Encadeada *l) {
    printf("   BUSCA - ENCADEADA\nNumero de comparacoes: %d\nNumero de atribuicoes: %d\n\n", l->comp_busca_encadeada, l->atr_busca_encadeada);
}
