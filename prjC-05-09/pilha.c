// pilha.c - Implementacao dinamica sequencial de pilha

#include "pilha.h"

Pilha pilha(int m) {
   Pilha P = (Pilha)malloc(sizeof(struct pilha));
   if (P == NULL) { puts("Erro de alocacao para a pilha."); abort(); }
   P->max  = m;
   P->topo = 0;
   P->item = (Itemp *)malloc(m * sizeof(Itemp));
   if (P->item == NULL) { puts("Erro de alocacao para itens da pilha."); free(P); abort(); }
   return P;
}

int vaziap(Pilha P) {
   return ( P->topo == 0 );
}

int cheiap(Pilha P) {
   return ( P->topo == P->max );
}

void empilha(Itemp x, Pilha P) {
   if( cheiap(P) ) { puts("pilha cheia!"); abort(); }
   P->item[P->topo] = x;
   P->topo++;
}

Itemp desempilha(Pilha P) {
   if( vaziap(P) ) { puts("pilha vazia!"); abort(); }
   P->topo--;
   return P->item[P->topo];
}

void destroip(Pilha *P) {
   free((*P)->item);
   free(*P);
   *P = NULL;
}