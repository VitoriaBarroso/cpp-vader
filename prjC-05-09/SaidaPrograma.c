#include <stdio.h>
#include "fila.h" 

int main(void){
    Fila F = fila(5);
    // enfileira 4 itens
    for(int i = 0; i<= 3; i++)
        enfileira('A' + i, F);
    // desenfileira e imprime todos os itens
    while(!vaziaf(F))
        printf("%c\n", desenfileira(F));
    destroif(&F);
    return 0;
}