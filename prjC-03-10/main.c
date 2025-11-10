#include "lista_encadeada.h"

int main(void) {
    // Inicialização da semente para números aleatórios
    srand(time(NULL)); 

    // Criação de listas de teste
    Lista I = no(3, no(1, no(5, NULL)));          // Lista I: [3, 1, 5]
    Lista H = no(4, no(2, NULL));                // Lista H: [4, 2]
    Lista VAZIA = NULL;
    Lista REPETIDA = no(10, no(20, no(10, no(30, NULL)))); // [10, 20, 10, 30]
    Lista ORD = no(1, no(2, no(3, NULL)));       // [1, 2, 3]
    Lista TESTE_ERRO = NULL; // Lista vazia para testar retorno de erro -1

    printf("--- EXERCICIOS ITERATIVOS (1-12) ---\n");

    printf("Ex. 1/2: Lista I: ");
    exibe_formatado(I); 
    printf("\nEx. 2: Lista VAZIA: ");
    exibe_formatado(VAZIA); 

    printf("\n\nEx. 3: Tamanho de I = %d\n", tamanho(I)); 
    printf("Ex. 4: Soma de I = %d\n", soma(I));       

    // Ex. 5
    Lista A = aleatoria(5, 10);
    printf("\nEx. 5: Lista Aleatoria (5, 10): ");
    exibe_formatado(A);

    // Ex. 6
    Lista INT_SIMPLES = intervalo_simples(4); 
    printf("\n\nEx. 6: Intervalo Simples (1 a 4): ");
    exibe_formatado(INT_SIMPLES);

    // Ex. 7
    anexa(&H, I); // H se torna [4, 2, 3, 1, 5]
    printf("\n\nEx. 7: Lista H Anexada (H+I): ");
    exibe_formatado(H);

    // Ex. 8 e 9: Testando funções com tratamento de erro (retorna -1 se erro)
    printf("\n\nEx. 8: Ultimo item de H = %d\n", ultimo(H));   
    printf("Ex. 9: Item maximo de H = %d\n", maximo(H));     
    printf("Ex. 10: 1 pertence a H? %d (1=Sim)\n", pertence(1, H)); 
    
    // Teste de ERRO (deve imprimir a mensagem no stderr e retornar -1)
    printf("Ex. 8 (Vazia - ERRO): %d\n", ultimo(TESTE_ERRO)); 

    // Ex. 11
    Lista INV = inversa(H);
    printf("\nEx. 11: Inversa de H: "); 
    exibe_formatado(INV);

    // Ex. 12
    Lista INT_PU = intervalo(-2, 3); 
    printf("\nEx. 12: Intervalo p a u (-2, 3): ");
    exibe_formatado(INT_PU);


    printf("\n\n--- EXERCICIOS RECURSIVOS (13-24) ---\n");

    printf("Ex. 13: len(H) = %d\n", len(H)); 
    printf("Ex. 14: sum(H) = %d\n", sum(H)); 

    // Ex. 15/22
    Lista CLONE = clone(H);
    printf("Ex. 15/22: equal(H, CLONE)? %d (1=Sim)\n", equal(H, CLONE));
    destroi(&CLONE); 

    // Ex. 17, 18, 19, 20: Testando funções com tratamento de erro (retorna -1 se erro)
    printf("Ex. 17: last(REPETIDA) = %d\n", last(REPETIDA));             
    printf("Ex. 18: in(20, REPETIDA)? %d (1=Sim)\n", in(20, REPETIDA));   
    printf("Ex. 19: 3o item de REPETIDA = %d\n", nth(3, REPETIDA));       
    printf("Ex. 20: minimum(REPETIDA) = %d\n", minimum(REPETIDA));   

    // Teste de ERRO (deve imprimir a mensagem no stderr e retornar -1)
    printf("Ex. 17 (Vazia - ERRO): %d\n", last(TESTE_ERRO)); 
    
    // Ex. 21, 23
    printf("\nEx. 21: sorted(ORD)? %d (1=Sim)\n", sorted(ORD));        
    printf("Ex. 23: count(10, REPETIDA) = %d\n", count(10, REPETIDA)); 

    // Ex. 24
    printf("Ex. 24: REPETIDA antes de replace(10, 99): ");
    exibe_formatado(REPETIDA);
    replace(10, 99, REPETIDA); 
    printf("\nREPETIDA depois: ");
    exibe_formatado(REPETIDA); 

    // Limpeza de memória
    destroi(&H);
    destroi(&A);
    destroi(&INV);
    destroi(&INT_SIMPLES);
    destroi(&INT_PU);
    destroi(&ORD);
    destroi(&REPETIDA);
    // TESTE_ERRO é NULL, não precisa de destroi

    printf("\n\nMemoria limpa. Fim do programa.\n");
    return 0; 
}