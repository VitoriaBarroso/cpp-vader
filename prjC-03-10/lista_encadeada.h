#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H




#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//definições de tipos//
typedef int Item;
typedef struct no{
    Item item;
    struct no *prox;
}*Lista;

//protótipos das funções//
Lista no(Item x, Lista p);
Item min_item(Item a, Item b);
void destroi(Lista *L);

void exibe(Lista L);
void exibe_formatado(Lista L);
int tamanho(Lista L);
Item soma(Lista l);
Lista aleatoria(int n, int m);
Lista intervalo_simples(int n);
void anexa(Lista *A, Lista b);
Item ultimo(Lista L);
Item maximo(Lista l);
int pertence(Item x, Lista L);
Lista inversa(Lista L);
Lista intervalo(Item p, Item u);

int len(Lista L);                                   
Item sum(Lista L);                                  
Lista clone(Lista L);                               
Lista rnd(int n, int m);                            
Item last(Lista L);    // Retorna -1 em caso de erro                            
int in(Item x, Lista L);                            
Item nth(int n, Lista L); // Retorna -1 em caso de erro                          
Item minimum(Lista L); // Retorna -1 em caso de erro                           
int sorted(Lista L);                                
int equal(Lista A, Lista B);                        
int count(Item x, Lista L);                         
void replace(Item x, Item y, Lista L);

#endif // LISTA_ENCADEADA_H