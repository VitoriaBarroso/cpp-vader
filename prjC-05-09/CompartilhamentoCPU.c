
#include <stdio.h>
#include "fila.h" /

#define TIMESLICE 3

int main(void) {
   int x, p, t;

   Fila F = fila(5);
   enfileira(17,F); // Processo 1, 7s
   enfileira(25,F); // Processo 2, 5s
   enfileira(39,F); // Processo 3, 9s
   enfileira(46,F); // Processo 4, 6s

   while(!vaziaf(F)) {
      x = desenfileira(F); 
      p = x/10;           
      t = x%10;          
      
      if(t > TIMESLICE) {
         t -= TIMESLICE; 
         enfileira(p*10 + t, F); 
      } else {
         printf("Processo %d concluido\n",p);
      }
   }
   
   destroif(&F);
   return 0;
}