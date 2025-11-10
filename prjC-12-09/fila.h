// fila.h - Interface da Fila

#include <stdlib.h>
#include <stdio.h> // Para puts e abort

// Macro para avancar o indice de forma circular
#define avanca(i) (i = (i+1) % F->max)

typedef int Itemf;

typedef struct fila {
   int   max;
   int   total;
   int   inicio;
   int   final;
   Itemf *item;
} *Fila;

// Prototipos das funcoes (a implementacao esta em fila.c)
Fila fila(int m);
int vaziaf(Fila F);
int cheiaf(Fila F);
void enfileira(Itemf x, Fila F);
Itemf desenfileira(Fila F);
void destroif(Fila *G);