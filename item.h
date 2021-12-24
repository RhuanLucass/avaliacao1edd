//
// Created by rhuan on 06/11/2021.
//

#ifndef QUADRADO_ITEM_H
#define QUADRADO_ITEM_H

#include "quadrado.h"
typedef struct item Item;

Item *criar_Item(unsigned int c, float x, float y, float lado);
void liberar_item(Item **i);
void imprimir_item(Item *i);
unsigned int get_chave(Item *i);
int get_itemx(Item *i);
int get_itemy(Item *i);
int get_itemlado(Item *i);


#endif //QUADRADO_ITEM_H
