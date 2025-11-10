// fila.c - Implementacao dinamica sequencial de fila (circular)

#include "fila.h"
// Observacao: As funcoes do seu fila.h original foram movidas para ca.

Fila fila(int m) {
   Fila F = malloc(sizeof(struct fila));
   if (F == NULL) { /* Tratar erro de alocacao */ } 
   
   F->max    = m;
   F->total  = 0;
   F->inicio = 0;
   F->final  = 0; 
   F->item   = malloc(m*sizeof(Itemf));
   if (F->item == NULL) { /* Tratar erro de alocacao */ }
   
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