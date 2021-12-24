//
// Created by rhuan on 05/11/2021.
//

#ifndef QUADRADO_QUADRADO_H
#define QUADRADO_QUADRADO_H

typedef struct quadrado Quadrado;

Quadrado *criar_quadrado(float x, float y, float lado);
void exibir_quadrado(Quadrado *q);
void liberar_quadrado(Quadrado **q);
void mover(Quadrado *q, float x, float y);
void calcular_area(Quadrado *q);
void calcular_perimetro(Quadrado *q);
void verificar_ponto(Quadrado *q, float x, float y);
void distancia_origem(Quadrado *q);
int get_x(Quadrado *q);
int get_y(Quadrado *q);
int get_lado(Quadrado *q);


#endif //QUADRADO_QUADRADO_H
