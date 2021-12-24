//
// Created by rhuan on 05/11/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quadrado.h"

struct quadrado{
    float x, y, lado;
};

Quadrado *criar_quadrado(float x, float y, float lado) {
    Quadrado  *q = malloc(sizeof(Quadrado));

    if(q == NULL)
        return NULL;

    q->x = x;
    q->y = y;
    q->lado = lado;

    return q;
}

void exibir_quadrado(Quadrado *q) {
    printf("O quadrado possui lados de tamanho: %.2f\n", q->lado);
    printf("Seu ponto central eh: (%.2f, %.2f)\n", q->x, q->y);
}

void liberar_quadrado(Quadrado **q) {
    free(*q);
    *q = NULL;
}

void mover(Quadrado *q, float x, float y) {
    if(q->x != x || q->y != y){
        q->x = x;
        q->y = y;
        printf("O quadrado foi movido corretamente!\n");
    }
    else
        printf("O quadrado nao foi movido, o ponto passado ja eh sua localizacao atual\n");
}

void calcular_area(Quadrado *q) {
    float area = pow(q->lado, 2);
    printf("A area do quadrado eh: %.2f\n", area);
}

void calcular_perimetro(Quadrado *q) {
    float perimetro = q->lado * 4;
    printf("O perimetro do quadrado eh: %.2f\n", perimetro);
}

void verificar_ponto(Quadrado *q, float x, float y) {
    float vertices[4];
    float l = q->lado/2;
    vertices[0] = q->x-l;
    vertices[1] = q->x+l;
    vertices[2] = q->y-l;
    vertices[3] = q->y+ l;

    if(x >= vertices[0] && x <= vertices[1] && y >= vertices[2] && y <= vertices[3])
        printf("O ponto (%.2f, %.2f) esta dentro do quadrado!\n", x, y);
    else
        printf("O ponto (%.2f, %.2f) NAO esta dentro do quadrado!\n", x, y);
}

void distancia_origem(Quadrado *q) {
    float distancia = sqrtf(pow(q->x, 2) + pow(q->y, 2));
    printf("A distancia do centro do quadrado ate a origem eh: %.2f\n", distancia);
}

int get_x(Quadrado *q) {
    return q->x;
}

int get_y(Quadrado *q) {
    return q->y;
}

int get_lado(Quadrado *q) {
    return q->lado;
}


