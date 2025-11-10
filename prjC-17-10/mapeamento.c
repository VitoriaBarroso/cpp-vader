#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1 ao 6 
typedef int Chave; 
typedef char Valor[22];
typedef struct map{
    Chave chave;
    Valor valor;
    struct map *prox;
} *Map;


Map no_map(Chave c, const char *v, Map p){
    Map n = (Map) malloc(sizeof(struct map));
    if(n == NULL) exit(EXIT_FAILURE);
    n -> chave = c;
    strcpy(n -> valor, v);
    n -> prox = p;
    return n;
}

void insm(Chave c, const char *v, Map *M){
    while(*M&& c>(*M)->chave)
    M = &(*M)->prox;
    if(*M && c == (*M)->chave)
        strcpy((*M)->valor, v);
    else
        *M = no_map(c, v, *M);
}

void exibem (Map M) { 
    printf("["); 
    while (M) { 
        printf("(%d,%s)",M->chave, M->valor); 
        if (M->prox) printf(","); 
        M = M->prox; 
    }
    printf("]\n");
}

void remm (Chave c, Map *M) { 
    while( *M && c>(*M)->chave ) 
        M = &(*M)->prox; 

    if(*M==NULL || c!=(*M)->chave ) return; 

    Map n = *M; 
    *M = n->prox; 
    free(n); 
}


int pertm (Chave c, Valor v, Map M) { 
    while (M && c>M->chave )
        M=M->prox;
    if( M && c==M->chave ) 
        strcpy(v,M->valor); 
    return (M && c==M->chave);
}

// Exercicio 2 
void insmr (Chave c, const char *v, Map *M) {
    if (*M == NULL || c < (*M)->chave) {
        *M = no_map(c, v, *M);
    } else if (c == (*M)->chave) {
        strcpy((*M)->valor, v);
    } else {
        insmr(c, v, &(*M)->prox);
    }
}
// Exercicio 4
void remmr (Chave c, Map *M) { 
    if (*M == NULL || c < (*M)->chave) {
        return; 
    }
    if (c == (*M)->chave) {
        Map n = *M;
        *M = n->prox;
        free(n);
        return;
    }
    remmr(c, &(*M)->prox);
}
// Exercicio 6
int pertmr(Chave c, Valor v, Map M) { 
    if (M == NULL || c < M->chave) {
        return 0;
    }
    if (c == M->chave) {
        strcpy(v, M->valor);
        return 1; 
    }
    return pertmr(c, v, M->prox);
}
// Exercicio 7
void destroim(Map*M){
    Map p = *M;
    while(p != NULL){
        Map n = p->prox;
        free(p);
        p = n;
    }
    *M = NULL;
}
// Exercicio 8
void destroimr(Map *M) { 
    if (*M == NULL) {
        return;
    }
    destroimr(&(*M)->prox); 
    free(*M);
    *M = NULL;
}
// Exercicio 1,3 e 5

int main(void) {
    Map I = NULL;
    Valor w;
    printf("---  ---\n");
    
    insm(36,"Leo",&I);
    insm(15,"Ivo", &I);
    insm(42, "Eva",&I);
    insm(29,"Ana",&I);
    
    exibem (I); 
    
    insm (29, "Bia",&I); 
    
    exibem (I);

    destroim(&I); 

    
    printf("\n---  ---\n");
    
    insm(36,"Leo", &I);
    insm(42, "Eva", &I);
    insm(15,"Ivo",&I);
    insm(29, "Ana",&I);

    printf("Estado inicial: ");
    exibem (I); 
    
    remm(29,&I); 
    
    printf("Após remm(29): ");
    exibem (I); 
    
    remm(42,&I); 
    
    printf("Após remm(42): ");
    exibem (I); 

    destroim(&I); 
    printf("\n--- ---\n");

    insm(36,"Leo",&I); 
    insm(15,"Ivo",&I); 
    insm(42,"Eva",&I); 

    printf("Estado inicial: ");
    exibem(I); 

    if( pertm(42,w,I) ) {
        printf("Valor da chave 42: %s\n",w); 
    } else {
        puts("Chave 42 inexistente!");
    }
    
    if( pertm(10,w,I) ) {
        printf("Valor da chave 10: %s\n",w);
    } else {
        puts("Chave 10 inexistente!");
    }

    destroim(&I);

    return 0;
}