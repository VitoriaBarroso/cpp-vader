// CadeiasPalindromas.c - Solucao do Exercício 1
#include <stdio.h>
#include <ctype.h>
#include "pilha.h"
#include "fila.h"

int main(void) {
   char s[256];
   Fila F = fila(256);
   Pilha P = pilha(256); 

   printf("\nFrase? ");
   // Uso de fgets() para leitura segura
   if (fgets(s, 256, stdin) == NULL) {
      destroif(&F);
      destroip(&P);
      return 1;
   }
   
   for(int i = 0; s[i]; i++) {
      if (s[i] == '\n') continue;

      if (isalpha(s[i])) {
         char c = toupper(s[i]); 
         enfileira(c, F);
         empilha(c, P);
      }
   }
   while(!vaziaf(F) && desenfileira(F) == desempilha(P));
   
   if(vaziaf(F)) 
      puts("A frase e palindroma");
   else 
      puts("A frase nao e palindroma");

   destroif(&F);
   destroip(&P); 
   
   return 0;
}