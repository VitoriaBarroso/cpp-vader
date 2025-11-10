#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

// função vetor exercicios 1,2,3,4 e 5 de 12
void exibe(int v[], int n){
    printf("{"); 
    for(int i = 0; i< n; i++){
        printf("%d", v[i]);
        if(i<n - 1){
            printf(", ");
        }
    }
    printf("}\n");
}

// troca dois elementos bsort e empurra
void troca(int v[], int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

//exercicios de ordenação por troca bubble sort (Exercício 1)
void bsort(int v[], int n){
    for(int i = 0; i < n -1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(v[j] > v[j + 1]){
                troca (v, j, j + 1);
            }
        }
    }
}


// função para empurrar o item máximo para a posição u (Exercício 2)
void empurra(int v[], int u) {
    if (u <= 0) {
        return;
    }
    if (v[u - 1] > v[u]) {
        troca(v, u - 1, u);
    }
    empurra(v, u - 1);
}

void bsr(int v[], int n) {
    if (n <= 1) {
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            troca(v, i, i + 1);
        }
    }
    bsr(v, n - 1);
}

// exercícios de Ordenação por Intercalação merge Sort (Exercício 4)
void intercala(int v[], int p, int m, int u) {
    int n = u - p + 1;
    int *w = (int *)malloc(n * sizeof(int));
    if (w == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        return;
    }
    int i = p, j = m + 1, k = 0;
    while (i <= m && j <= u) {
        if (v[i] <= v[j]) {
            w[k++] = v[i++];
        } else {
            w[k++] = v[j++];
        }
    }
    while (i <= m) {
        w[k++] = v[i++];
    }
    while (j <= u) {
        w[k++] = v[j++];
    }
    for (k = 0; k < n; k++) {
        v[p + k] = w[k];
    }
    free(w);
}

// função Merge Sort (recursiva) (Parte do Exercício 5)
void msort_recursivo(int v[], int p, int u) {
    if (p < u) {
        int m = (p + u) / 2;
        msort_recursivo(v, p, m);
        msort_recursivo(v, m + 1, u);
        intercala(v, p, m, u);
    }
}

// função Merge Sort (chamada principal) (Exercício 5)
void msort(int v[], int n) {
    msort_recursivo(v, 0, n - 1);
}

void preenche(int v[], int n, int s) {
    srand(s);
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 1000; 
    }
}


// exercícios de Busca
// busca Linear (lsearch) (Exercício 9)
// retorna 1 se 'x' está em 'v', 0 caso contrário.
int lsearch(int x, int v[], int n) {
    for (int i = 0; i < n; i++) {
        if (v[i] == x) {
            return 1; 
        }
    }
    return 0; 
}
int busca_binaria(int x, int v[], int n) {
    int p = 0;
    int u = n - 1;
    while (p <= u) {
        int m = (p + u) / 2;
        if (x == v[m]) {
            return 1;
        }
        if (x < v[m]) {
            u = m - 1;
        } else {
            p = m + 1;
        }
    }
    return 0; 
}

// versão Recursiva de Busca Linear (rlsearch) (Exercício 11)
// determina se 'x' está em 'v' de tamanho 'n'.
// retorna 1 se 'x' está em 'v', 0 caso contrário.
int rlsearch(int x, int v[], int n) {
    if (n == 0) {
        return 0;
    }
    
    if (v[n - 1] == x) {
        return 1; 
    }
    
    return rlsearch(x, v, n - 1);
}

// versão Recursiva de Busca Binária (rbsearch) (Exercício 12)
// determina se 'x' está em 'v' no intervalo [p, u].
// retorna 1 se 'x' está em 'v', 0 caso contrário.
int rbsearch(int x, int v[], int p, int u) { 
    if (p > u) {
        return 0;
    }
    int m = (p + u) / 2;
    if (x == v[m]) {
        return 1;
    }
    if (x < v[m]) {
        return rbsearch(x, v, p, m - 1);
    }
    else {
        return rbsearch(x, v, m + 1, u);
    }
}

int main() {
    printf("====================================================\n");
    printf("EXERCICIOS DIA 26-09\n");
    printf("====================================================\n\n");

    
    // (Bubble Sort)


    printf("--- EXERCICIOS DE BUBBLE SORT ---\n\n");

    // EXERCÍCIO 1: Teste da função bsort()
    printf("Exercicio 1: bsort()\n");
    int v1[10] = {83, 31, 91, 46, 27, 20, 96, 25, 96, 80};
    int n1 = 10;
    printf("Vetor original: ");
    exibe(v1, n1);
    bsort(v1, n1);
    printf("Vetor ordenado: ");
    exibe(v1, n1);
    printf("\n");


    printf("Exercicio 2: empurra()\n");
    int v2[9] = {51, 82, 38, 99, 75, 19, 69, 46, 27};
    int n2 = 9;
    printf("Vetor original: ");
    exibe(v2, n2);
    empurra(v2, 8);
    printf("Vetor após empurra(v, 8): ");
    exibe(v2, n2);
    printf("Saida esperada: {51, 38, 82, 75, 19, 69, 46, 27, 99}\n\n");

    printf("Exercicio 3: bsr()\n");
    int v3[9] = {51, 82, 38, 99, 75, 19, 69, 46, 27};
    int n3 = 9;
    printf("Vetor original: ");
    exibe(v3, n3);
    bsr(v3, n3);
    printf("Vetor ordenado por bsr: ");
    exibe(v3, n3);
    printf("\n");

    
    // (Merge Sort)
 

    printf("--- EXERCICIOS DE MERGE SORT ---\n\n");
    printf("Exercicio 4: intercala()\n");
    
    int v4_1[8] = {31, 48, 60, 80, 19, 27, 52, 75};
    printf("Teste 1 Original: ");
    exibe(v4_1, 8);
    intercala(v4_1, 0, 3, 7);
    printf("Teste 1 Intercalado: ");
    exibe(v4_1, 8);
    printf("\n");

    int v4_2[9] = {10, 82, 27, 38, 41, 53, 60, 75, 99};
    printf("Teste 2 Original: ");
    exibe(v4_2, 9);
    intercala(v4_2, 0, 1, 8);
    printf("Teste 2 Intercalado: ");
    exibe(v4_2, 9);
    printf("\n");

    // EXERCÍCIO 5: Teste da função msort()
    printf("Exercicio 5: msort()\n");
    int v5[10] = {83, 31, 91, 46, 27, 20, 96, 25, 96, 80};
    int n5 = 10;
    printf("Vetor original: ");
    exibe(v5, n5);
    msort(v5, n5);
    printf("Vetor ordenado por msort: ");
    exibe(v5, n5);
    printf("\n");

    // EXERCÍCIO 6: Preenchimento aleatório (preenche)
    printf("Exercicio 6: preenche()\n");
    int v6[10];
    int n6 = 10;
    int s6 = 123; 
    preenche(v6, n6, s6);
    printf("Vetor preenchido com semente %d: ", s6);
    exibe(v6, n6);
    printf("\n");

    // EXERCÍCIO 7: Comparação entre bsort() e msort()
    printf("Exercicio 7: Comparação de Desempenho (bsort vs. msort)\n");
    
    int N_BSORT = 10000;
    int *v7_b = (int *)malloc(N_BSORT * sizeof(int));
    int *v7_m = (int *)malloc(N_BSORT * sizeof(int));
    if (!v7_b || !v7_m) {
        fprintf(stderr, "Erro de alocacao no Ex 7.\n");
        return 1;
    }
    preenche(v7_b, N_BSORT, 456);
    for (int i = 0; i < N_BSORT; i++) v7_m[i] = v7_b[i];
    clock_t start_b = clock();
    bsort(v7_b, N_BSORT);
    clock_t end_b = clock();
    double time_b = (double)(end_b - start_b) / CLOCKS_PER_SEC * 1000.0;
    clock_t start_m = clock();
    msort(v7_m, N_BSORT);
    clock_t end_m = clock();
    double time_m = (double)(end_m - start_m) / CLOCKS_PER_SEC * 1000.0;
    
    printf("Tamanho do vetor: %d\n", N_BSORT);
    printf("Tempo bsort (b): %.2f ms\n", time_b);
    printf("Tempo msort (m): %.2f ms\n", time_m);
    
    free(v7_b);
    free(v7_m);
    printf("\n");

    // EXERCÍCIO 8: Desempenho de msort() para vetores muito grandes
    printf("Exercicio 8: Desempenho de msort() para vetores grandes\n");
    
    int N_MSORT_LARGE = 1000000; 
    int *v8 = (int *)malloc(N_MSORT_LARGE * sizeof(int));
    if (!v8) {
        fprintf(stderr, "Erro de alocação de memória no Ex 8. Tente um N menor.\n");
        return 1;
    }
    preenche(v8, N_MSORT_LARGE, 789);
    clock_t start_large = clock();
    msort(v8, N_MSORT_LARGE);
    clock_t end_large = clock();
    double time_large = (double)(end_large - start_large) / CLOCKS_PER_SEC * 1000.0;
    printf("Tamanho do vetor (N): %d\n", N_MSORT_LARGE);
    printf("Tempo msort (m): %.2f ms\n", time_large);
    free(v8);
    printf("\n");


    printf("--- EXERCICIOS DE BUSCA ---\n\n");

    int v_lsearch[8] = {66, 80, 31, 48, 27, 75, 19, 52};
    int n_busca = 8;
    int v_bsearch[8] = {19, 27, 31, 48, 52, 66, 75, 80}; 

    // EXERCÍCIO 9: Teste da função lsearch()
    printf("Exercicio 9: lsearch() (Busca Linear)\n");
    printf("Vetor: "); exibe(v_lsearch, n_busca);
    printf("27: %d (1 = Encontrado)\n", lsearch(27, v_lsearch, n_busca));
    printf("51: %d (0 = Nao Encontrado)\n", lsearch(51, v_lsearch, n_busca));
    printf("\n");

    // EXERCÍCIO 10: Teste da função busca_binaria()
    printf("Exercicio 10: bsearch() (Busca Binária)\n");
    printf("Vetor: "); exibe(v_bsearch, n_busca);
    printf("27: %d (1 = Encontrado)\n", busca_binaria(27, v_bsearch, n_busca));
    printf("51: %d (0 = Nao Encontrado)\n", busca_binaria(51, v_bsearch, n_busca));
    printf("\n");

    // EXERCÍCIO 11: Versão recursiva de busca linear (rlsearch)
    printf("Exercicio 11: rlsearch() (Busca Linear Recursiva)\n");
    printf("Vetor: "); exibe(v_lsearch, n_busca);
    printf("27: %d (1 = Encontrado)\n", rlsearch(27, v_lsearch, n_busca));
    printf("51: %d (0 = Nao Encontrado)\n", rlsearch(51, v_lsearch, n_busca));
    printf("\n");

    // EXERCÍCIO 12: Versão recursiva de busca binária (rbsearch)
    printf("Exercicio 12: rbsearch() (Busca Binaria Recursiva)\n");
    printf("Vetor: "); exibe(v_bsearch, n_busca);
    printf("27: %d (1 = Encontrado)\n", rbsearch(27, v_bsearch, 0, n_busca - 1));
    printf("51: %d (0 = Nao Encontrado)\n", rbsearch(51, v_bsearch, 0, n_busca - 1));
    printf("80: %d (1 = Encontrado)\n", rbsearch(80, v_bsearch, 0, n_busca - 1));
    printf("\n");

    printf("====================================================\n");
    printf(" FIM!!!!\n"); 
    printf("====================================================\n");

    return 0;
}