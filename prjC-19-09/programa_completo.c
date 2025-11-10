#include <stdio.h>
#include <stdlib.h>
#include <malloc.h> // Necessário para a função intercala (merge sort)

// ====================================================================
// I. FUNÇÕES AUXILIARES (Necessárias para todos os exercícios)
// ====================================================================

/**
 * Função Auxiliar: troca
 * Troca os valores das posições i e j de um vetor v.
 */
void troca(int v[], int i, int j) {
    int x = v[i];
    v[i] = v[j];
    v[j] = x;
}

/**
 * Função Auxiliar: exibe
 * Exibe o conteúdo de um vetor v de tamanho n.
 */
void exibe(int v[], int n) {
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) {
            printf(",");
        }
    }
    printf("}\n");
}

// ====================================================================
// II. ORDENAÇÃO (Exercícios 1, 2 e 3)
// ====================================================================

/**
 * Ex. 1: bsort() - Bubble Sort Iterativo
 */
void bsort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (v[j] > v[j + 1]) {
                troca(v, j, j + 1);
            }
        }
    }
}

/**
 * Ex. 2: empurra() - Passada de Bubble Sort Recursiva
 *Esta função usa 'troca', que está definida acima.
 */
void empurra(int v[], int u) {
    if (u <= 0) {
        return;
    }

    if (v[u - 1] > v[u]) {
        troca(v, u - 1, u);
    }
    empurra(v, u - 1);
}

/**
 * Ex. 3: bsr() - Bubble Sort Recursivo
 * OBS: Esta função usa 'troca', que está definida acima.
 */
void bsr(int v[], int n) {
    if (n <= 1) {
        return;
    }

    // Passagem do Bubble Sort para fixar o maior elemento em v[n-1]
    for (int j = 0; j < n - 1; j++) {
        if (v[j] > v[j + 1]) {
            troca(v, j, j + 1);
        }
    }

    // Chama recursivamente para o subvetor de tamanho n-1
    bsr(v, n - 1);
}


// ====================================================================
// III. ORDENAÇÃO (Merge Sort - Exercícios 4, 5 e 6)
// ====================================================================

/**
 * Ex. 4: intercala() - Merge
 */
void intercala(int v[], int p, int m, int u) {
    int *w = malloc((u - p + 1) * sizeof(int));
    if (w == NULL) {
        // Tratar erro de alocação, se necessário
        return; 
    }
    int i = p, j = m + 1, k = 0;

    while (i <= m && j <= u) {
        w[k++] = (v[i] < v[j]) ? v[i++] : v[j++];
    }

    while (i <= m) {
        w[k++] = v[i++];
    }
    while (j <= u) {
        w[k++] = v[j++];
    }

    for (k = 0; k <= u - p; k++) {
        v[p + k] = w[k];
    }
    free(w);
}

/**
 * Ex. 5: merge_sort() - Merge Sort Recursivo
 */
void mergeSort(int v[], int p, int u) {
    if (p < u) {
        int m = p + (u - p) / 2; // Ponto médio

        mergeSort(v, p, m);
        mergeSort(v, m + 1, u);

        intercala(v, p, m, u);
    }
}


// ====================================================================
// IV. BUSCA (Exercícios 7 a 12)
// ====================================================================

/**
 * Ex. 7: busca_linear_rec() - Busca Linear Recursiva
 *

 */
int busca_linear_rec(int v[], int n, int x) {
    if (n == 0) {
        return -1;
    }

    // Verifica o último elemento da sub-chamada
    if (v[n - 1] == x) {
        return n - 1;
    }

    // Chama recursivamente para o restante do vetor
    return busca_linear_rec(v, n - 1, x);
}

/**
 * Ex. 9: busca_binaria_rec() - Busca Binária Recursiva
 * 
 */
int busca_binaria_rec(int v[], int p, int u, int x) {
    if (p > u) {
        return -1;
    }

    int m = p + (u - p) / 2;

    if (v[m] == x) {
        return m;
    }

    if (v[m] > x) {
        return busca_binaria_rec(v, p, m - 1, x);
    }

    return busca_binaria_rec(v, m + 1, u, x);
}

/**
 * Ex. 11: busca_primeiro_rec() - Busca Binária da Primeira Ocorrência
 * 
 */
int busca_primeiro_rec(int v[], int p, int u, int x) {
    if (p > u) {
        return -1;
    }

    int m = p + (u - p) / 2;
    int resultado;

    if (v[m] == x) {
       
        resultado = busca_primeiro_rec(v, p, m - 1, x);
        

        return (resultado != -1) ? resultado : m;
    }

    if (v[m] > x) {
        return busca_primeiro_rec(v, p, m - 1, x);
    }

    return busca_primeiro_rec(v, m + 1, u, x);
}

/**
 * Ex. 12: busca_menor_rec() - Busca do Elemento Menor que x (Piso)

 */
int busca_menor_rec_aux(int v[], int p, int u, int x, int candidato) {
    if (p > u) {
        return candidato;
    }

    int m = p + (u - p) / 2;

    if (v[m] < x) {
        return busca_menor_rec_aux(v, m + 1, u, x, m);
    } else { 
        return busca_menor_rec_aux(v, p, m - 1, x, candidato);
    }
}

int busca_menor_rec(int v[], int p, int u, int x) {
    return busca_menor_rec_aux(v, p, u, x, -1);
}

// ====================================================================
// V. FUNÇÃO MAIN PARA TESTES (Corrigida para main())
// ====================================================================

int main(void) {
    printf("--- Solucoes dos Exercicios de Ordenacao e Busca ---\n\n");

    // ==================================
    // TESTES DE ORDENACAO
    // ==================================

    // Ex. 1 (Bubble Sort Iterativo)
    int v1[10] = {83, 31, 91, 46, 27, 20, 96, 25, 96, 80};
    printf("Exercicio. I - Bubble Sort Iterativo:\n");
    printf("Original: "); exibe(v1, 10);
    bsort(v1, 10);
    printf("Ordenado: "); exibe(v1, 10); 
    
    // Ex. 3 (Bubble Sort Recursivo)
    int v3[9] = {51, 82, 38, 99, 75, 19, 69, 46, 27};
    printf("\nExercicio. III - Bubble Sort Recursivo:\n");
    printf("Original: "); exibe(v3, 9);
    bsr(v3, 9);
    printf("Ordenado: "); exibe(v3, 9);

    // Exercicio. VI - Merge Sort Recursivo
    int v6[8] = {66, 31, 48, 80, 27, 75, 52, 19};
    printf("\nExercicio. VI - Merge Sort Recursivo:\n");
    printf("Original: "); exibe(v6, 8);
    mergeSort(v6, 0, 7);
    printf("Ordenado: "); exibe(v6, 8);
    
    // ==================================
    // TESTES DE BUSCA (Requer vetor ordenado)
    // ==================================
    int v_busca[10] = {19, 27, 31, 48, 52, 66, 75, 80, 83, 99};
    
    // Ex. 8 (Busca Linear Recursiva)
    printf("\nExercicio. VIII - Busca Linear Recursiva:\n");
    printf("Busca 75: %d\n", busca_linear_rec(v_busca, 10, 75)); // Esperado: 6
    printf("Busca 98: %d\n", busca_linear_rec(v_busca, 10, 98)); // Esperado: -1

    // Exercicio. 10 (Busca Binária Recursiva)
    printf("\nExercicio. X - Busca Binária Recursiva:\n");
    printf("Busca 52: %d\n", busca_binaria_rec(v_busca, 0, 9, 52)); // Esperado: 4
    printf("Busca 50: %d\n", busca_binaria_rec(v_busca, 0, 9, 50)); // Esperado: -1

    // Ex. 11 (Busca da Primeira Ocorrência)
    int v_duplicado[10] = {10, 20, 20, 30, 30, 30, 40, 50, 50, 60};
    printf("\nExercicio. XI - Busca Primeira Ocorrência:\n");
    printf("Busca 30: %d\n", busca_primeiro_rec(v_duplicado, 0, 9, 30)); // Esperado: 3
    printf("Busca 20: %d\n", busca_primeiro_rec(v_duplicado, 0, 9, 20)); // Esperado: 1

    // Ex. 12 (Busca do Menor Elemento que X)
    printf("\nExercicio. XII - Busca do Menor Elemento que X:\n");
    // O maior elemento menor que 51 é o 48, que está no índice 3.
    int idx1 = busca_menor_rec(v_busca, 0, 9, 51);
    printf("Busca menor que 51: %d (v[%d] = %d)\n", idx1, idx1, (idx1 != -1 ? v_busca[idx1] : -1)); // Esperado: 3 (elemento 48)

    int idx2 = busca_menor_rec(v_busca, 0, 9, 10);
    printf("Busca menor que 10: %d\n", idx2); // Esperado: -1
    
    return 0;
}