#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Quadrado.h"
#include "item.h"
#include "lista_sequencial.h"
#include "lista_ordenada.h"
#include "lista_encadeada.h"

int preencher_listas_crescente(Lista_Sequencial *ls, Lista_Ordenada *lo, Lista_Encadeada *le,  int quantidade) {
    if(ls == NULL || lo == NULL || le == NULL)
        return 0;
    int chave;
    float lado, x, y;
    for(int i=1; i <= quantidade; i++){
        chave = i;
        lado = i;
        x = rand() % 100;
        y = rand() % 100;

        inserir_fim_lista_sequencial(ls, criar_Item(chave, x, y, lado));
        inserir_ordenada(lo, criar_Item(chave, x, y, lado));
        inserir_fim_lista_encadeada(le, criar_Item(chave, x, y, lado));
    }
    return 1;
}

int preencher_listas_decrescente(Lista_Sequencial *ls, Lista_Ordenada *lo, Lista_Encadeada *le,  int quantidade) {
    if(ls == NULL || lo == NULL || le == NULL)
        return 0;
    int chave, k=0;
    float lado, x, y;
    for(int i=quantidade; i >= 1; i--){
        chave = k;
        lado = i;
        x = rand() % 100;
        y = rand() % 100;
        k++;

        inserir_fim_lista_sequencial(ls, criar_Item(chave, x, y, lado));
        inserir_ordenada(lo, criar_Item(chave, x, y, lado));
        inserir_fim_lista_encadeada(le, criar_Item(chave, x, y, lado));

    }
    return 1;
}

void swap (float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void randomize (float arr[], int n ) {
    srand ( time(NULL) );
    for (int i = n-1; i > 0; i--)
    {
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
    }
}


int preencher_listas_aleatorio(Lista_Sequencial *ls, Lista_Ordenada *lo, Lista_Encadeada *le, int quantidade) {
    if(ls == NULL || lo == NULL || le == NULL)
        return 0;

    float vet[quantidade];
    for(int i=1; i <= quantidade; i++){
        vet[i-1] = i;
    }


    randomize(vet, quantidade);

    /*for(int i=1; i<=quantidade;i++){
        printf("%.0f, ", vet[i-1]);
    }*/

    int chave;
    float lado, x, y;
    for(int i=1; i <= quantidade; i++){
        chave = vet[i];
        lado = i;
        x = rand() % 100;
        y = rand() % 100;

        inserir_fim_lista_sequencial(ls, criar_Item(chave, x, y, lado));
        inserir_ordenada(lo, criar_Item(chave, x, y, lado));
        inserir_fim_lista_encadeada(le, criar_Item(chave, x, y, lado));
    }
    return 1;
}

int buscas(Lista_Sequencial *ls, Lista_Ordenada *lo, Lista_Encadeada *le, unsigned int lado, unsigned int quantidade){
    for(int i=0; i < quantidade; i++){
        buscar_elemento_lista_sequencial(ls, lado);
        //busca_binaria_lista_ordenada(lo, lado);
        buscar_elemento_lista_encadeada(le, lado);
    }

    if(buscar_elemento_lista_sequencial(ls, lado))
        printf("Elemento de lado %d encontrado na Lista Sequencial!\n", lado);
    else
        printf("Elemento de lado %d NAO encontrado na Lista Sequencial!\n", lado);

    if(busca_binaria_lista_ordenada(lo, lado))
        printf("Elemento de lado %d encontrado na Lista Ordenada!\n", lado);
    else
        printf("Elemento de lado %d NAO encontrado na Lista Ordenada!\n", lado);

    if(buscar_elemento_lista_encadeada(le, lado))
        printf("Elemento de lado %d encontrado na Lista Encadeada!\n", lado);
    else
        printf("Elemento de lado %d NAO encontrado na Lista Encadeada!\n", lado);


    imprimir_busca_sequencial(ls);
    imprimir_busca_ordenada(lo);
    imprimir_busca_encadeada(le);
}

int main() {
    //Para as atribuições contei também a própria atribuição da variável utilizada para esta função
    Lista_Sequencial *ls = criar_lista_sequencial();
    Lista_Ordenada *lo = criar_lista_ordenada();
    Lista_Encadeada *le = criar_lista_encadeada();

    Lista_Sequencial *ls2 = criar_lista_sequencial();
    Lista_Ordenada *lo2 = criar_lista_ordenada();
    Lista_Encadeada *le2 = criar_lista_encadeada();

    Lista_Sequencial *ls3 = criar_lista_sequencial();
    Lista_Ordenada *lo3 = criar_lista_ordenada();
    Lista_Encadeada *le3 = criar_lista_encadeada();

    //2-
    preencher_listas_crescente(ls, lo, le, 1000);

    printf("    2- a) utilizando o metodo inserir_fim() da Lista Linear Sequencial\n");
    imprimir_inserir_sequencial(ls);

    printf("    2- b) utilizando o metodo inserir_ordenado() da Lista Ordenada\n");
    imprimir_inserir_ordenada(lo);

    printf("    2- c) utilizando o metodo inserir_fim() da Lista Encadeada\n");
    imprimir_inserir_encadeada(le);

    //3-
    printf("    3- a) Quadrados com lado 1\n");
    buscas(ls, lo, le, 1, 100);

    printf("    3- b) Quadrados com lado 1001\n");
    buscas(ls, lo, le, 1001, 100);

    printf("    3- c) Quadrados com lado 500\n");
    buscas(ls, lo, le, 500, 100);

    printf("    3- d) Quadrados com lado 1000\n");
    buscas(ls, lo, le, 1000, 100);


    //4-
    preencher_listas_decrescente(ls2, lo2, le2, 1000);

    printf("    4- a) utilizando o metodo inserir_fim() da Lista Linear Sequencial\n");
    imprimir_inserir_sequencial(ls);

    printf("    4- b) utilizando o metodo inserir_ordenado() da Lista Ordenada\n");
    imprimir_inserir_ordenada(lo);

    printf("    4- c) utilizando o metodo inserir_fim() da Lista Encadeada\n");
    imprimir_inserir_encadeada(le);

    printf("    4- a) Quadrados com lado 1\n");
    buscas(ls, lo, le, 1, 100);

    printf("    4- b) Quadrados com lado 1001\n");
    buscas(ls, lo, le, 1001, 100);

    printf("    4- c) Quadrados com lado 500\n");
    buscas(ls, lo, le, 500, 100);

    printf("    4- d) Quadrados com lado 1000\n");
    buscas(ls, lo, le, 1000, 100);

    //5-
    preencher_listas_aleatorio(ls3, lo3, le3, 1000);

    printf("    5- a) utilizando o metodo inserir_fim() da Lista Linear Sequencial\n");
    imprimir_inserir_sequencial(ls3);

    printf("    5- b) utilizando o metodo inserir_ordenado() da Lista Ordenada\n");
    imprimir_inserir_ordenada(lo3);

    printf("    5- c) utilizando o metodo inserir_fim() da Lista Encadeada\n");
    imprimir_inserir_encadeada(le3);


    printf("    5- a) Quadrados com lado 1\n");
    buscas(ls3, lo3, le3, 1, 100);

    printf("    5- b) Quadrados com lado 1001\n");
    buscas(ls3, lo3, le3, 1001, 100);

    printf("    5- c) Quadrados com lado 500\n");
    buscas(ls3, lo3, le3, 500, 100);

    printf("    5- d) Quadrados com lado 1000\n");
    buscas(ls3, lo3, le3, 1000, 100);

    return 0;
}
