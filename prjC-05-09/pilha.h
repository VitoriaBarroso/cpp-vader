// pilha.h - Prototipos e definicoes de tipos para a Pilha

#include <stdlib.h>
#include <stdio.h>

typedef int Itemp;

typedef struct pilha {
   int   max;
   int   topo;
   Itemp *item;
} *Pilha;

// Prototipos das funcoes
Pilha pilha(int m);
int vaziap(Pilha P);
int cheiap(Pilha P);
void empilha(Itemp x, Pilha P);
Itemp desempilha(Pilha P);
void destroip(Pilha *P);