//
// Created by rhuan on 06/11/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "lista_ordenada.h"
#include "item.h"

#define FLAG_ERRO -1
#define VERDADEIRO 1
#define FALSO 0

struct lista_ordenada{
    unsigned int qtd, comp_inserir_ordenada, atr_inserir_ordenada, comp_busca_ordenada, atr_busca_ordenada;
    Item *dados[N];
};

Lista_Ordenada *criar_lista_ordenada() {
    Lista_Ordenada  *l = (Lista_Ordenada *) malloc(sizeof(Lista_Ordenada));
    if(l == NULL)
        return FLAG_ERRO;
    l->qtd = 0;
    l->comp_busca_ordenada=0;
    l->atr_busca_ordenada=0;
    l->comp_inserir_ordenada=0;
    l->atr_inserir_ordenada=0;
    return l;
}

int lista_ordenada_cheia(Lista_Ordenada *l) {
    if (l == NULL)
        return FLAG_ERRO;
    if (l->qtd > N)
        return VERDADEIRO;
    else
        return FALSO;
}

int lista_ordenada_vazia(Lista_Ordenada *l) {
    if (l == NULL)
        return FLAG_ERRO;
    return (l->qtd == 0);
}

int lista_ordenada_tamanho(Lista_Ordenada *l) {
    if (l != NULL)
        return l->qtd;
    else
        return  FLAG_ERRO;
}

int inserir_ordenada(Lista_Ordenada *l, Item *i) {
    if(lista_ordenada_cheia(l)) {
        l->comp_inserir_ordenada+=3; // São feitas duas comparações tanto para retornar verdadeiro quanto para falso e outra nesse if
        l->atr_inserir_ordenada+=2;
        return FALSO;
    }
    int j;
    for (j = 0; j < l->qtd; j++){
        l->comp_inserir_ordenada+=2; //Referente a j < lista_ordenada_t+amanho(l) quando o resultado é verdadeiro e o próximo if
        l->atr_inserir_ordenada+=3; //Referente a j++, l->comp_inserir_ordenada++ e o próprio l->atr_inserir_ordenada
        if(get_itemlado(l->dados[j]) > get_itemlado(i)){
            l->comp_inserir_ordenada++; //Referente a k > j do próximo for
            l->atr_inserir_ordenada+=3; //Referente a k = lista_ordenada_tamanho(l)
            for (int k = l->qtd; k > j; k--) {
                l->dados[k] = l->dados[k-1];
                l->comp_inserir_ordenada++; //Referente a k > j
                l->atr_inserir_ordenada+=4; //Referente a k--, l->dados[j + 1] = l->dados[j], l->comp_inserir_ordenada++ e o próprio l->atr_inserir_ordenada
            }
            break;
        }
    }
    l->dados[j] = i;
    l->qtd++;
    l->comp_inserir_ordenada+=4; //Referente a última comparação de j < lista_ordenada_tamanho(l) quando o resultado é falso e o primeiro if
    l->atr_inserir_ordenada+=5; //Referente a j = 0 quando retorna false,  l->dados[j] = i,  l->qtd++, l->comp_inserir_ordenada++ e o próprio l->atr_inserir_ordenada
    return VERDADEIRO;
}

void exibir_lista_ordenada(Lista_Ordenada *l) {
    if(l == NULL)
        return;
    for (int i = 0; i < l->qtd; i++) {
        imprimir_item(l->dados[i]);
    }
}

int remover_inicio_lista_ordenada(Lista_Ordenada *l) {
    if(lista_ordenada_vazia(l))
        return FALSO;

    liberar_item(&(l->dados[0]));
    for (int j = 1; j < l->qtd; j++)
        l->dados[j-1] = l->dados[j];
    l->qtd--;
    return VERDADEIRO;
}

int remover_meio_lista_ordenada(Lista_Ordenada *l, unsigned int k) {
    if(lista_ordenada_vazia(l))
        return FALSO;

    for (int j = k; j < l->qtd; j++)
        l->dados[j-1] = l->dados[j];
    l->qtd--;

    return VERDADEIRO;
}

int remover_fim_lista_ordenada(Lista_Ordenada *l) {
    if(lista_ordenada_vazia(l))
        return FALSO;
    liberar_item(&(l->dados[l->qtd-1]));
    l->qtd--;
    return VERDADEIRO;
}

void esvaziar_lista_ordenada(Lista_Ordenada *l) {
    while(!lista_ordenada_vazia(l))
        remover_fim_lista_ordenada(l);
}

void liberar_lista_ordenada(Lista_Ordenada **l) {
    esvaziar_lista_ordenada(*l);
    free(*l);
    *l = NULL;
}

int busca_binaria_lista_ordenada(Lista_Ordenada *l, unsigned int lado) {
    int inicio = 0;
    int fim = lista_ordenada_tamanho(l);
    int meio = 1;
    int maior = fim;

    l->comp_busca_ordenada+=2; // A lista_ordenada_tamanho(l) realiza uma comparação e a última comparação do while com resultado falso
    l->atr_busca_ordenada+=6;

    while (meio <= maior && meio > 0){
        meio = (fim + inicio) / 2;

        l->comp_busca_ordenada+=2;
        l->atr_busca_ordenada+=3;

        if(meio == lista_ordenada_tamanho(l)){ //Como a lista vai de 0 a 999, o elemento de posição 1000 não existe
            l->comp_busca_ordenada+=2; // A lista_ordenada_tamanho(l) realiza uma comparação e a outra do if
            l->atr_busca_ordenada+=2;
            return FALSO;
        }

        if (get_itemlado(l->dados[meio]) == lado) {
            //imprimir_item(l->dados[meio]);
            l->comp_busca_ordenada+=2; //Referente aos dois ifs
            l->atr_busca_ordenada += 2;
            return VERDADEIRO;
        }
        else if (get_itemlado(l->dados[meio]) > lado) {
            fim = meio - 1;

            l->comp_busca_ordenada += 3; //Referente aos ifs e o else if
            l->atr_busca_ordenada += 3; //Referente a fim = meio - 1, l->comp_inserir_ordenada++ e o próprio l->atr_inserir_ordenada
        }
        else {
            inicio = meio + 1;

            l->comp_busca_ordenada += 3;//Referente aos ifs e o else if
            l->atr_busca_ordenada += 3; //Referente a inicio = meio + 1, l->comp_inserir_ordenada++ e o próprio l->atr_inserir_ordenada
        }
    }

    //printf("Elemento nao encontrado!\n");
    return  FALSO;
}

Lista_Ordenada *merge(Lista_Ordenada *l1, Lista_Ordenada *l2) {
    Lista_Ordenada *list;
    list = criar_lista_ordenada();

    for(int a = 0; a < lista_ordenada_tamanho(l1); a++){
        inserir_ordenada(list, l1->dados[a]);
    }

    for(int b = 0; b < lista_ordenada_tamanho(l2); b++){
        inserir_ordenada(list, l2->dados[b]);
    }

    return list;
}

int busca_sequencial_ordenada(Lista_Ordenada *l, unsigned int chave) {
    if(l == NULL )
        return FALSO;
    for(int i = 0; i < lista_ordenada_tamanho(l); i++){
        if(get_chave(l->dados[i]) == chave) {
            imprimir_item(l->dados[i]);
            return VERDADEIRO;
        }
    }
    return FALSO;
}

void imprimir_inserir_ordenada(Lista_Ordenada *l) {
    printf("   INSERIR FIM - ORDENADA\nNumero de comparacoes: %d\nNumero de atribuicoes: %d\n\n", l->comp_inserir_ordenada, l->atr_inserir_ordenada);
}

void imprimir_busca_ordenada(Lista_Ordenada *l) {
    printf("   BUSCA BINARIA - ORDENADA\nNumero de comparacoes: %d\nNumero de atribuicoes: %d\n\n", l->comp_busca_ordenada, l->atr_busca_ordenada);
}


