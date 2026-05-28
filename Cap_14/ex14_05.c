/* Exercicio 14.5 - Espacar os caracteres de um arquivo usando arquivo temporario */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <arquivo>\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Fase 1: abre o arquivo original para leitura e cria um arquivo temporario.
       Para cada caractere do original, escreve no temporario o caractere
       seguido de um espaco. */
    FILE *original = fopen(argv[1], "r");
    if (original == NULL) {
        fprintf(stderr, "Erro: nao foi possivel abrir \"%s\" para leitura.\n",
                argv[1]);
        return EXIT_FAILURE;
    }

    FILE *temporario = tmpfile();
    if (temporario == NULL) {
        fprintf(stderr, "Erro: nao foi possivel criar arquivo temporario.\n");
        fclose(original);
        return EXIT_FAILURE;
    }

    int c;
    while ((c = fgetc(original)) != EOF) {
        fputc(c, temporario);
        if (c != '\n') {           /* nao colocar espaco apos quebra de linha */
            fputc(' ', temporario);
        }
    }
    fclose(original);

    /* Fase 2: reabre o original em modo de escrita (truncando-o) e copia
       todo o conteudo do temporario de volta para ele. */
    rewind(temporario);

    original = fopen(argv[1], "w");
    if (original == NULL) {
        fprintf(stderr, "Erro: nao foi possivel reabrir \"%s\" para escrita.\n",
                argv[1]);
        fclose(temporario);
        return EXIT_FAILURE;
    }

    while ((c = fgetc(temporario)) != EOF) {
        fputc(c, original);
    }

    fclose(original);
    fclose(temporario);    /* tmpfile() e auto-removido ao fechar */

    printf("Arquivo \"%s\" reescrito com espacos entre caracteres.\n", argv[1]);
    return EXIT_SUCCESS;
}
