/* Exercicio 14.2 - Produto de inteiros via lista variadica */
#include <stdio.h>
#include <stdarg.h>

int product(int count, ...);

int main(void) {
    printf("Produto de  3 inteiros: %d\n", product(3, 2, 3, 4));
    printf("Produto de  5 inteiros: %d\n", product(5, 1, 2, 3, 4, 5));
    printf("Produto de  7 inteiros: %d\n", product(7, 2, 2, 2, 2, 2, 2, 2));
    printf("Produto de  1 inteiro : %d\n", product(1, 42));
    printf("Produto de 10 inteiros: %d\n",
           product(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
    return 0;
}

int product(int count, ...) {
    va_list args;
    int produto = 1;

    va_start(args, count);

    for (int i = 0; i < count; ++i) {
        produto *= va_arg(args, int);
    }

    va_end(args);
    return produto;
}
