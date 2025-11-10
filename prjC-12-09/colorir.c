
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "coloracao.h"

#define CODIFICA(i, j) ((i) * DIM + (j))
#define DECODIFICA_LINHA(cod) ((cod) / DIM)
#define DECODIFICA_COLUNA(cod) ((cod) % DIM)

void colorir(int I[DIM][DIM], int i, int j, int nova_cor) {
   // EXERCÍCIO 1: CORREÇÃO
   // Se a posicao inicial ja tem a nova cor, retorna imediatamente
   if (I[i][j] == nova_cor) {
      return; 
   }

   int cor_antiga = I[i][j];
   
   Fila F = fila(DIM * DIM); 
   enfileira(CODIFICA(i, j), F);

   I[i][j] = nova_cor; 

   while (!vaziaf(F)) {
      int cod = desenfileira(F);
      int cur_i = DECODIFICA_LINHA(cod);
      int cur_j = DECODIFICA_COLUNA(cod);

      
      int vizinhos[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

      for (int k = 0; k < 4; k++) {
         int viz_i = cur_i + vizinhos[k][0];
         int viz_j = cur_j + vizinhos[k][1];

         if (viz_i >= 0 && viz_i < DIM && 
             viz_j >= 0 && viz_j < DIM &&
             I[viz_i][viz_j] == cor_antiga) 
         {
            I[viz_i][viz_j] = nova_cor;
            enfileira(CODIFICA(viz_i, viz_j), F);
         }
      }
   }

   destroif(&F);
}