#include "lista_encadeada.h"


// Função base para criar um novo nó (tratamento de erro na alocação)
Lista no(Item x, Lista p) {
    Lista n = (Lista)malloc(sizeof(struct no));
    if (n == NULL) {
        fprintf(stderr, "Erro: Falha na alocacao de memoria.\n");
        exit(1); 
    }
    n->item = x;
    n->prox = p;
    return n;
}

// Função auxiliar para calcular o mínimo entre dois itens
Item min_item(Item a, Item b) {
    return (a < b) ? a : b;
}

// Implementação do Exemplo 8 (Destruição)
void destroi(Lista *L) {
    while( *L ) {
        Lista n = *L;
        *L = n->prox;
        free(n);
    }
}

// EXERCÍCIO 1: Exibição Simples
void exibe(Lista L) { 
    while( L != NULL ) {
        printf("%d\n", L->item);
        L = L->prox;
    }
}

// EXERCÍCIO 2: Exibição Formatada [i1,i2,...] -
void exibe_formatado(Lista L) { 
    printf("[");
    while( L != NULL ) {
        printf("%d", L->item);
        L = L->prox;
        if (L != NULL) {
            printf(",");
        }
    }
    printf("]");
}

// EXERCÍCIO 3: Tamanho (Iterativa)
int tamanho(Lista L) { 
    int t = 0;
    while( L ) { 
        t++;
        L = L->prox;
    }
    return t;
}

// EXERCÍCIO 4: Soma dos itens da lista (Iterativa)
Item soma(Lista L) {
    Item total = 0;
    while( L ) {
        total += L->item;
        L = L->prox;
    }
    return total;
}

// EXERCÍCIO 5: Lista Aleatória (Iterativa)
Lista aleatoria(int n, int m) { 
    Lista L = NULL;
    while( n > 0 ) {
        L = no(rand() % m, L); 
        n--;
    }
    return L;
}

// EXERCÍCIO 6: Criação de lista contendo um intervalo (1 até n)
Lista intervalo_simples(int n) { 
    Lista L = NULL;
    int i;
    for (i = n; i >= 1; i--) { 
        L = no(i, L);
    }
    return L;
}

// EXERCÍCIO 7: Anexação de listas
void anexa(Lista *A, Lista B) {
    if( !B ) return; 
    while( *A ) { 
        A = &(*A)->prox;
    }
    *A = B; 
}

// EXERCÍCIO 8: Último item (Retorna -1 se vazia)
Item ultimo(Lista L) {
    if (L == NULL) {
        fprintf(stderr, "\nERRO 8: Lista vazia na funcao ultimo().\n");
        return -1; 
    }
    while (L->prox != NULL) {
        L = L->prox;
    }
    return L->item;
}

// EXERCÍCIO 9: Item máximo (Retorna -1 se vazia)
Item maximo(Lista L) {
    if (L == NULL) {
        fprintf(stderr, "\nERRO 9: Lista vazia na funcao maximo().\n");
        return -1; 
    }
    Item max = L->item;
    L = L->prox;
    while (L != NULL) {
        if (L->item > max) {
            max = L->item;
        }
        L = L->prox;
    }
    return max;
}

// EXERCÍCIO 10: Pertinência (Iterativa)
int pertence(Item x, Lista L) { 
    while (L != NULL) {
        if (L->item == x) {
            return 1; 
        }
        L = L->prox;
    }
    return 0; 
}

// EXERCÍCIO 11: Inversão (Cria e devolve uma CÓPIA invertida)
Lista inversa(Lista L) { 
    Lista nova = NULL;
    Lista p = L;
    while (p != NULL) {
        nova = no(p->item, nova); 
        p = p->prox;
    }
    return nova;
}

// EXERCÍCIO 12: Intervalo (p até u)
Lista intervalo(Item p, Item u) { 
    Lista L = NULL;
    if (p > u) {
        return NULL; 
    }
    Item i;
    for (i = u; i >= p; i--) {
        L = no(i, L);
    }
    return L;
}


// (13-24)

// EXERCÍCIO 13: Tamanho (Recursiva)
int len(Lista L) {
    if (L == NULL) {
        return 0;
    }
    return 1 + len(L->prox);
}

// EXERCÍCIO 14: Soma (Recursiva)
Item sum(Lista L) {
    if (L == NULL) {
        return 0;
    }
    return L->item + sum(L->prox);
}

// EXERCÍCIO 15: Clone (cópia recursiva)
Lista clone(Lista L) {
    if (L == NULL) {
        return NULL;
    }
    return no(L->item, clone(L->prox));
}

// EXERCÍCIO 16: Aleatória (Recursiva)
Lista rnd(int n, int m) {
    if (n == 0) {
        return NULL;
    }
    return no(rand() % m, rnd(n - 1, m));
}

// EXERCÍCIO 17: Último item (Retorna -1 se vazia)
Item last(Lista L) {
    if (L == NULL) {
        fprintf(stderr, "\nERRO 17: Lista vazia na funcao last().\n");
        return -1; 
    }
    if (L->prox == NULL) {
        return L->item; 
    }
    return last(L->prox);
}

// EXERCÍCIO 18: Pertinência (Recursiva)
int in(Item x, Lista L) {
    if (L == NULL) {
        return 0;
    }
    if (L->item == x) {
        return 1;
    }
    return in(x, L->prox);
}

// EXERCÍCIO 19: Enésimo item (Retorna -1 se inválido)
Item nth(int n, Lista L) {
    if (L == NULL || n <= 0) {
        fprintf(stderr, "\nERRO 19: Posicao invalida ou fora do limite na funcao nth().\n");
        return -1; 
    }
    if (n == 1) {
        return L->item; 
    }
    return nth(n - 1, L->prox);
}

// EXERCÍCIO 20: Mínimo (Retorna -1 se vazia)
Item minimum(Lista L) {
    if (L == NULL) {
        fprintf(stderr, "\nERRO 20: Lista vazia na funcao minimum().\n");
        return -1; 
    }
    if (L->prox == NULL) {
        return L->item; 
    }
    return min_item(L->item, minimum(L->prox));
}

// EXERCÍCIO 21: Ordenada (Recursiva)
int sorted(Lista L) {
    if (L == NULL || L->prox == NULL) {
        return 1; 
    }
    if (L->item > L->prox->item) {
        return 0; 
    }
    return sorted(L->prox);
}

// EXERCÍCIO 22: Igualdade (Recursiva)
int equal(Lista A, Lista B) {
    if (A == NULL && B == NULL) {
        return 1; 
    }
    if (A == NULL || B == NULL || A->item != B->item) {
        return 0; 
    }
    return equal(A->prox, B->prox);
}

// EXERCÍCIO 23: Contagem de ocorrências (Recursiva)
int count(Item x, Lista L) {
    if (L == NULL) {
        return 0;
    }
    int incremento = (L->item == x) ? 1 : 0;
    return incremento + count(x, L->prox);
}

// EXERCÍCIO 24: Substituição (Recursiva)
void replace(Item x, Item y, Lista L) {
    if (L == NULL) {
        return;
    }

    if (L->item == x) { 
        L->item = y;
    }
    
    replace(x, y, L->prox);
}