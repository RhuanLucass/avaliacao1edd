//
// Created by rhuan on 06/11/2021.
//

#include "item.h"
#include <stdlib.h>
#include <stdio.h>

struct item{
    Quadrado *quad;
    unsigned int chave;
};

Item *criar_Item(unsigned int c, float x, float y, float lado) {
    Item *i = (Item*) malloc(sizeof(Item));
    if(i == NULL)
        return NULL;

    i->quad = criar_quadrado(x, y, lado);
    if(i->quad == NULL)
        return NULL;

    i->chave = c;
    return i;
}

void liberar_item(Item **i) {
    liberar_quadrado(&(*i)->quad);
    free(*i);
    i = NULL;
}

void imprimir_item(Item *i) {
    printf("Item: %d\n", i->chave);
    exibir_quadrado(i->quad);
    printf("\n");
}

unsigned int get_chave(Item *i) {
    return i->chave;
}

int get_itemx(Item *i) {
    return get_x(i->quad);
}

int get_itemy(Item *i) {
    return get_y(i->quad);
}

int get_itemlado(Item *i) {
    return get_lado(i->quad);
}
