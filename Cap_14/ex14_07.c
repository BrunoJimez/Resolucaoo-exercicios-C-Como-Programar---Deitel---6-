/* Exercicio 14.7 - Alocacao dinamica e realloc para metade */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    printf("Digite o tamanho do array (numero par >= 2): ");
    if (scanf("%d", &n) != 1 || n < 2) {
        fprintf(stderr, "Tamanho invalido.\n");
        return EXIT_FAILURE;
    }

    /* Aloca dinamicamente o array */
    int *v = malloc(n * sizeof(int));
    if (v == NULL) {
        fprintf(stderr, "Erro de alocacao.\n");
        return EXIT_FAILURE;
    }

    /* Le os elementos */
    printf("Digite %d inteiros separados por espacos:\n", n);
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &v[i]) != 1) {
            fprintf(stderr, "Erro de leitura no indice %d.\n", i);
            free(v);
            return EXIT_FAILURE;
        }
    }

    /* Imprime o array original */
    printf("\nArray original (%d elementos):\n", n);
    for (int i = 0; i < n; ++i) {
        printf("  v[%d] = %d\n", i, v[i]);
    }

    /* Realoca para metade do tamanho */
    int novoTamanho = n / 2;
    int *novo = realloc(v, novoTamanho * sizeof(int));
    if (novo == NULL) {
        fprintf(stderr, "Erro de realocacao.\n");
        free(v);
        return EXIT_FAILURE;
    }
    v = novo;

    /* Imprime o array realocado */
    printf("\nApos realloc para %d elementos:\n", novoTamanho);
    for (int i = 0; i < novoTamanho; ++i) {
        printf("  v[%d] = %d\n", i, v[i]);
    }

    free(v);
    return EXIT_SUCCESS;
}
