
#include <stdio.h>
#include "coloracao.h" 
void exiba(int I[DIM][DIM]) {
   printf("\n--- Imagem Atual ---\n");
   // Exibe os indices das colunas
   printf("  "); 
   for(int j=0; j<DIM; j++) {
      printf("%d ", j);
   }
   printf("\n");
   
   for (int i = 0; i < DIM; i++) {
      printf("%d ", i);
      for (int j = 0; j < DIM; j++) {
         printf("%d ", I[i][j]); 
      }
      printf("\n"); 
   }
   printf("--------------------\n");
}

// EXERCÍCIO 2: SOLUÇÃO PARA LER DO ARQUIVO
// Funcao para inicializar a matriz lendo dados de um arquivo
void inicia(int I[DIM][DIM], char *nome_arquivo) {
   FILE *a = fopen(nome_arquivo, "r");
   if (a == NULL) {
      printf("ERRO: Nao foi possivel abrir o arquivo '%s'. Inicializando com zeros.\n", nome_arquivo);
      for (int i = 0; i < DIM; i++) {
         for (int j = 0; j < DIM; j++) {
            I[i][j] = 0;
         }
      }
      return;
   }
   
   printf("Lendo imagem de '%s'...\n", nome_arquivo);
   for (int i = 0; i < DIM; i++) {
      for (int j = 0; j < DIM; j++) {
         if (fscanf(a, "%d", &I[i][j]) != 1) {
             printf("AVISO: Fim de arquivo inesperado ou erro de leitura em (%d,%d).", i, j);
             fclose(a);
             return;
         }
      }
   }
   fclose(a);
}
int main(void) {
   int I[DIM][DIM];
   int i, j, nova_cor;
   char nome_arquivo[256];
   printf("Digite o nome do arquivo da imagem (ex: imagem.txt): ");
   if (scanf("%s", nome_arquivo) != 1) {
       return 1;
   }
   inicia(I, nome_arquivo); 
   while (1) {
      exiba(I);
      printf("\nNova cor (0 a 9, ou -1 para sair)? ");
      
      if (scanf("%d", &nova_cor) != 1) {
          int c; while ((c = getchar()) != '\n' && c != EOF); 
          continue;
      }
      
      if (nova_cor < 0) {
          break;
      }
      
      if (nova_cor > 9) nova_cor = 9;
      if (nova_cor < 0) nova_cor = 0;

      do {
         printf("Posicao de clique (linha,coluna, 0-%d)? ", DIM-1);
         if (scanf("%d,%d", &i, &j) != 2) {
             int c; while ((c = getchar()) != '\n' && c != EOF); 
             continue;
         }
      } while (i < 0 || i >= DIM || j < 0 || j >= DIM);
      colorir(I, i, j, nova_cor);
   }

   return 0;
}