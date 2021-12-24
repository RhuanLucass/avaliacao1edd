//
// Created by rhuan on 06/11/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"
#include "item.h"

#define FLAG_ERRO -1
#define VERDADEIRO 1
#define FALSO 0

struct lista_sequencial{
    unsigned int qtd, comp_inserir_sequencial, atr_inserir_sequencial, comp_busca_sequencial, atr_busca_sequencial;
    Item *dados[N];
};


Lista_Sequencial *criar_lista_sequencial() {
    Lista_Sequencial  *l = (Lista_Sequencial *) malloc(sizeof(Lista_Sequencial));
    if(l == NULL)
        return FLAG_ERRO;
    l->qtd = 0;
    l->atr_inserir_sequencial=0;
    l->comp_inserir_sequencial=0;
    l->atr_busca_sequencial=0;
    l->comp_busca_sequencial=0;
    return l;
}

int lista_sequencial_cheia(Lista_Sequencial *l) {
    if (l == NULL)
        return FLAG_ERRO;
    if (l->qtd > N)
        return VERDADEIRO;
    else
        return FALSO;
}

int lista_sequencial_vazia(Lista_Sequencial *l) {
    if (l == NULL)
        return FLAG_ERRO;
    return (l->qtd == 0);
}

int lista_sequencial_tamanho(Lista_Sequencial *l) {
    if (l != NULL)
        return l->qtd;
    else
        return  FLAG_ERRO;
}

int inserir_fim_lista_sequencial(Lista_Sequencial *l, Item *i) {

    if(lista_sequencial_cheia(l)) { // São feitas duas comparações tanto para retornar verdadeiro quanto para falso
        l->comp_inserir_sequencial+=3;
        l->atr_inserir_sequencial+=2;
        return FALSO;
    }
    else{
        l->dados[l->qtd] = i;
        l->qtd++;
        l->comp_inserir_sequencial+=3;
        l->atr_inserir_sequencial+=4;
        return VERDADEIRO;
    }
}

int inserir_inicio_lista_sequencial(Lista_Sequencial *l, Item *i) {
    if(lista_sequencial_cheia(l))
        return FALSO;
    for (int j = l->qtd; j > 0; j--)
        l->dados[j] = l->dados[j-1];
    l->dados[0] = i;
    l->qtd++;
    return VERDADEIRO;
}

void exibir_lista_sequencial(Lista_Sequencial *l) {
    if(l == NULL)
        return;
    for (int i = 0; i < l->qtd; i++) {
        imprimir_item(l->dados[i]);
    }
}

int inserir_meio_lista_sequencial(Lista_Sequencial *l, Item *i, unsigned int k) {
    if(lista_sequencial_cheia(l) || k >= l->qtd)
        return FALSO;

    for (int j = l->qtd; j > k ; j--)
        l->dados[j] = l->dados[j-1];
    l->dados[k] = i;
    l->qtd++;
    return VERDADEIRO;
}

int remover_inicio_lista_sequencial(Lista_Sequencial *l) {
    if(lista_sequencial_vazia(l))
        return FALSO;

    liberar_item(&(l->dados[0]));
    for (int j = 1; j < l->qtd; j++)
        l->dados[j-1] = l->dados[j];
    l->qtd--;
    return VERDADEIRO;
}

int remover_meio_lista_sequencial(Lista_Sequencial *l, unsigned int k) {
    if(lista_sequencial_vazia(l))
        return FALSO;

    for (int j = k; j < l->qtd; j++)
        l->dados[j-1] = l->dados[j];
    l->qtd--;

    return VERDADEIRO;
}

int remover_fim_lista_sequencial(Lista_Sequencial *l) {
    if(lista_sequencial_vazia(l))
        return FALSO;
    liberar_item(&(l->dados[l->qtd-1]));
    l->qtd--;
    return VERDADEIRO;
}

void esvaziar_lista_sequencial(Lista_Sequencial *l) {
    while(!lista_sequencial_vazia(l))
        remover_fim_lista_sequencial(l);
}

void liberar_lista_sequencial(Lista_Sequencial **l) {
    esvaziar_lista_sequencial(*l);
    free(*l);
    *l = NULL;
}

int buscar_elemento_lista_sequencial(Lista_Sequencial *l, unsigned int lado) {
    if (l->qtd == 0){
        //printf("Lista Vazia!\n");
        l->comp_busca_sequencial++;
        l->atr_busca_sequencial+=2;
        return FALSO;
    }
    int i = 0;
    while(i < l->qtd && get_itemlado(l->dados[i]) != lado) {
        i++;
        l->comp_busca_sequencial+=3;
        l->atr_busca_sequencial+=3;
    }
    if(i == l->qtd){
        //printf("ERRO: Nenhum quadrado possui lado igual a %d!\n", lado);
        l->comp_busca_sequencial+=3; // Se i == l->qtd, get_itemlado(l->dados[i]) != lado não será comparado
        l->atr_busca_sequencial+=2;
        return FALSO;
    }

    l->comp_busca_sequencial+=4;
    l->atr_busca_sequencial+=3;
    //imprimir_item(l->dados[i]);
    return VERDADEIRO;
}

Lista_Sequencial *concatenar_lista_sequencial(Lista_Sequencial *l1, Lista_Sequencial *l2) {
    Lista_Sequencial *list;
    list = criar_lista_sequencial();

    for(int i = 0; i < l1->qtd; i++){
        list->dados[list->qtd] = l1->dados[i];
        list->qtd++;
    }

    for(int j = 0; j < l2->qtd; j++){
        list->dados[list->qtd] = l2->dados[j];
        list->qtd++;
    }
    return list;
}

void imprimir_inserir_sequencial(Lista_Sequencial *l) {
    printf("   INSERIR FIM - SEQUENCIAL\nNumero de comparacoes: %d\nNumero de atribuicoes: %d\n\n", l->comp_inserir_sequencial, l->atr_inserir_sequencial);
}

void imprimir_busca_sequencial(Lista_Sequencial *l) {
    printf("   BUSCA - SEQUENCIAL\nNumero de comparacoes: %d\nNumero de atribuicoes: %d\n\n", l->comp_busca_sequencial, l->atr_busca_sequencial);
}

