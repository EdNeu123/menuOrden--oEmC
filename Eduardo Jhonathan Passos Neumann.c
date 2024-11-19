#include <stdio.h>
#include <stdlib.h>
#include "ordena.h"

int main() {
    system("CHCP 65001>NULL");
    system("cls");
    
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    // Alocação dinâmica de memória para o vetor
    int* vet = (int*)malloc(tamanho * sizeof(int));
    if (vet == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Geração do vetor de números aleatórios sem repetição
    gerarVetor(vet, tamanho);

    int opcao;
    printf("Escolha o método de ordenação:\n");
    printf("1. Selection Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Bubble Sort\n");
    printf("4. Quick Sort\n");
    printf("5. Bogo Sort\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    // Exibição do vetor original
    printf("\n\nVetor original:\n");
    imprimirVetor(vet, tamanho);

    // Execução do método de ordenação escolhido
    switch (opcao) {
        case 1:
            selection(vet, tamanho);
            break;
        case 2:
            insertion(vet, tamanho);
            break;
        case 3:
            bolha(vet, tamanho);
            break;
        case 4:
            quick(vet, 0, tamanho - 1);
            break;
        case 5:
            bogoSort(vet, tamanho);
            break;
        default:
            printf("Opção inválida!\n");
            free(vet); // Libera a memória alocada antes de sair
            return 1;
    }

    // Exibição do vetor ordenado
    printf("Vetor ordenado:\n");
    imprimirVetor(vet, tamanho);

    // Gravação do vetor original e do vetor ordenado em arquivos texto
    salvarVetorEmArquivo("vetor_original.txt", vet, tamanho);
    salvarVetorEmArquivo("vetor_ordenado.txt", vet, tamanho);

    // Liberação da memória alocada
    free(vet);

    return 0;
}
