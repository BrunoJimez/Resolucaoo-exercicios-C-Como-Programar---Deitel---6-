/* Exercicio 14.4 - Ordenacao com flag -c (crescente) ou -d (decrescente) */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAMANHO 10

void bubbleSort(int v[], int n, int crescente);
void imprimirArray(const int v[], int n);

int main(int argc, char *argv[]) {
    int crescente;
    int dados[TAMANHO] = {37, 12, 89, 4, 56, 23, 71, 8, 45, 99};

    /* Verifica se o flag foi fornecido */
    if (argc != 2) {
        fprintf(stderr, "Uso: %s -c | -d\n", argv[0]);
        fprintf(stderr, "  -c : ordena em ordem crescente\n");
        fprintf(stderr, "  -d : ordena em ordem decrescente\n");
        return EXIT_FAILURE;
    }

    /* Decodifica o flag */
    if (strcmp(argv[1], "-c") == 0) {
        crescente = 1;
    } else if (strcmp(argv[1], "-d") == 0) {
        crescente = 0;
    } else {
        fprintf(stderr, "Opcao desconhecida: \"%s\"\n", argv[1]);
        return EXIT_FAILURE;
    }

    printf("Array original:\n");
    imprimirArray(dados, TAMANHO);

    bubbleSort(dados, TAMANHO, crescente);

    printf("\nArray ordenado em ordem %s:\n",
           crescente ? "crescente" : "decrescente");
    imprimirArray(dados, TAMANHO);

    return EXIT_SUCCESS;
}

void bubbleSort(int v[], int n, int crescente) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            int trocar = crescente ? (v[j] > v[j + 1]) : (v[j] < v[j + 1]);
            if (trocar) {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

void imprimirArray(const int v[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%4d", v[i]);
    }
    printf("\n");
}
