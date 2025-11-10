// coloracao.h - Interface e definicoes globais

#ifndef COLORACAO_H
#define COLORACAO_H

// Define a dimensao da matriz da imagem
#define DIM 9

// Funcao central de coloracao
void colorir(int I[DIM][DIM], int i, int j, int nova_cor);

// Funcao para exibir a matriz
void exiba(int I[DIM][DIM]);

// Funcao para inicializar a matriz lendo dados de um arquivo (Exercicio 2)
void inicia(int I[DIM][DIM], char *nome_arquivo);

#endif