// fila.c - Implementacao dinamica sequencial de fila (circular)

#include <stdlib.h>
#include <stdio.h>
#include "fila.h" // Inclui os protótipos

// A macro avanca(i) deve estar definida em fila.h
// #define avanca(i) (i = (i+1) % F->max)

Fila fila(int m) {
   Fila F = malloc(sizeof(struct fila));
   if (F == NULL) { puts("Erro de alocacao para a Fila."); abort(); }
   
   F->max    = m;
   F->total  = 0;
   F->inicio = 0;
   F->final  = 0; 
   
   F->item   = malloc(m*sizeof(Itemf));
   if (F->item == NULL) { free(F); puts("Erro de alocacao para itens da Fila."); abort(); }
   
   return F;
}

int vaziaf(Fila F) {
   return ( F->total == 0 );
}

int cheiaf(Fila F) {
   return ( F->total == F->max );
}

void enfileira(Itemf x, Fila F) {
   if( cheiaf(F) ) { puts("fila cheia!"); abort(); }
   
   F->item[F->final] = x;
   avanca(F->final);
   F->total++;
}

Itemf desenfileira(Fila F) {
   if( vaziaf(F) ) { puts("fila vazia!"); abort(); }
   
   Itemf x = F->item[F->inicio];
   avanca(F->inicio);
   F->total--;
   
   return x;
}

void destroif(Fila *G) {
   free((*G)->item);
   free(*G);
   *G = NULL;
}