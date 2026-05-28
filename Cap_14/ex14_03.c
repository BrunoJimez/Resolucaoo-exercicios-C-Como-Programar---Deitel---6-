/* Exercicio 14.3 - Imprimir argumentos da linha de comando */
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("O programa recebeu %d argumento(s) da linha de comando:\n\n", argc);

    for (int i = 0; i < argc; ++i) {
        printf("  argv[%d] = \"%s\"\n", i, argv[i]);
    }

    return 0;
}
