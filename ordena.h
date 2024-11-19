#ifndef ORDENA_H
#define ORDENA_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Função de ordenação por seleção
void selection(int vet[], int tamanho) {
    int i, j, aux, menor;
    for (i = 0; i < tamanho - 1; i++) {
        menor = i; // Assume que o menor elemento é o primeiro não ordenado
        for (j = i + 1; j < tamanho; j++) {
            if (vet[j] < vet[menor]) {
                menor = j; // Encontra o menor elemento na sublista não ordenada
            }
        }
        if (i != menor) {
            aux = vet[i];
            vet[i] = vet[menor];
            vet[menor] = aux; // Troca o menor elemento encontrado com o primeiro não ordenado
        }
    }
}


// Função de ordenação por inserção
void insertion(int vet[], int tamanho) {
    int i, j, aux;
    for (i = 1; i < tamanho; i++) {
        aux = vet[i]; // Armazena o valor a ser inserido
        for (j = i; (j > 0) && (aux < vet[j - 1]); j--) {
            vet[j] = vet[j - 1]; // Desloca os elementos maiores para a direita
        }
        vet[j] = aux; // Insere o valor armazenado na posição correta
    }
}

// Função de ordenação por bolha
void bolha(int vet[], int tamanho) {
    int i, j, aux;
    bool trocou;
    for (i = 0; i < tamanho - 1; i++) {
        trocou = false; // Flag para verificar se houve troca
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vet[j] > vet[j + 1]) {
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux; // Troca os elementos adjacentes se estiverem fora de ordem
                trocou = true;
            }
        }
        if (!trocou) break; // Se não houve troca, o array já está ordenado
    }
}

// Função auxiliar para particionar o array para o Quick Sort
int dividir(int vet[], int esq, int dir) {
    int aux, i;
    int cont = esq;
    for (i = esq + 1; i <= dir; i++) {
        if (vet[i] < vet[esq]) {
            cont++;
            aux = vet[i];
            vet[i] = vet[cont];
            vet[cont] = aux; // Move os elementos menores que o pivô para a esquerda
        }
    }
    aux = vet[esq];
    vet[esq] = vet[cont];
    vet[cont] = aux; // Coloca o pivô na posição correta
    return cont; // Retorna a posição do pivô
}

// Função de ordenação rápida (Quick Sort)
void quick(int vet[], int esq, int dir) {
    int pos;
    if (esq < dir) {
        pos = dividir(vet, esq, dir); // Particiona o array e obtém a posição do pivô
        quick(vet, esq, pos - 1); // Ordena a sublista à esquerda do pivô
        quick(vet, pos + 1, dir); // Ordena a sublista à direita do pivô
    }
}

// Função de ordenação Bogo Sort
bool isSorted(int vet[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        if (vet[i] > vet[i + 1]) {
            return false;
        }
    }
    return true;
}

void shuffle(int vet[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int r = rand() % tamanho;
        int temp = vet[i];
        vet[i] = vet[r];
        vet[r] = temp;
    }
}

void bogoSort(int vet[], int tamanho) {
    while (!isSorted(vet, tamanho)) {
        shuffle(vet, tamanho);
    }
}

// Função de busca linear
int buscaLinear(int vet[], int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (vet[i] == valor) {
            return i; // Retorna o índice do valor encontrado
        }
    }
    return -1; // Retorna -1 se o valor não for encontrado
}

// Função de busca binária
int buscaBinaria(int vet[], int tamanho, int valor) {
    int esq = 0, dir = tamanho - 1;
    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;
        if (vet[meio] == valor) {
            return meio; // Retorna o índice do valor encontrado
        }
        if (vet[meio] < valor) {
            esq = meio + 1;
        } else {
            dir = meio - 1;
        }
    }
    return -1; // Retorna -1 se o valor não for encontrado
}

// Função para gerar um vetor de números aleatórios sem repetição
void gerarVetor(int vet[], int tamanho) {
    srand(time(NULL));
    bool* usado = (bool*)calloc(100, sizeof(bool)); // Array auxiliar para rastrear números usados
    if (usado == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        int num;
        do {
            num = rand() % 100; // Gera números aleatórios entre 0 e 99
        } while (usado[num]); // Garante que o número não foi usado ainda
        vet[i] = num;
        usado[num] = true; // Marca o número como usado
    }

    free(usado); // Libera a memória alocada para o array auxiliar
}

// Função para salvar um vetor em um arquivo texto
void salvarVetorEmArquivo(const char* nomeArquivo, int vet[], int tamanho) {
    FILE* arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d\n", vet[i]);
    }
    fclose(arquivo);
}

// Função para imprimir o vetor na tela
void imprimirVetor(int vet[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

#endif // ORDENA_H
