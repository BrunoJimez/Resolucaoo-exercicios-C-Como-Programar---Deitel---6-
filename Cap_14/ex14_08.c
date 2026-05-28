/* Exercicio 14.8 - Le um arquivo e escreve seus caracteres em ordem
   reversa em outro arquivo */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <arquivo_entrada> <arquivo_saida>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *entrada = fopen(argv[1], "rb");
    if (entrada == NULL) {
        fprintf(stderr, "Erro: nao foi possivel abrir \"%s\".\n", argv[1]);
        return EXIT_FAILURE;
    }

    FILE *saida = fopen(argv[2], "wb");
    if (saida == NULL) {
        fprintf(stderr, "Erro: nao foi possivel criar \"%s\".\n", argv[2]);
        fclose(entrada);
        return EXIT_FAILURE;
    }

    /* Posiciona-se no final do arquivo para descobrir o tamanho */
    if (fseek(entrada, 0L, SEEK_END) != 0) {
        fprintf(stderr, "Erro em fseek.\n");
        fclose(entrada);
        fclose(saida);
        return EXIT_FAILURE;
    }
    long tamanho = ftell(entrada);

    /* Le o arquivo um caractere de cada vez, do ultimo para o primeiro */
    for (long pos = tamanho - 1; pos >= 0; --pos) {
        if (fseek(entrada, pos, SEEK_SET) != 0) {
            fprintf(stderr, "Erro em fseek (pos=%ld).\n", pos);
            break;
        }
        int c = fgetc(entrada);
        if (c == EOF) break;
        fputc(c, saida);
    }

    fclose(entrada);
    fclose(saida);

    printf("Arquivo \"%s\" gravado com %ld caracteres em ordem reversa "
           "de \"%s\".\n", argv[2], tamanho, argv[1]);
    return EXIT_SUCCESS;
}
