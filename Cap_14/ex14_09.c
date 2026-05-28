/* Exercicio 14.9 - Quadrado de asteriscos usando goto e apenas as tres
   instrucoes printf permitidas */
#include <stdio.h>

#define LADO 5

int main(void) {
    int linha = 1;
    int coluna;

inicioLinha:
    if (linha > LADO) goto fim;

    coluna = 1;

inicioColuna:
    if (coluna > LADO) goto fimLinha;

    /* Caractere a imprimir: '*' se estiver na borda; ' ' caso contrario. */
    if (linha == 1 || linha == LADO || coluna == 1 || coluna == LADO)
        goto imprimeAsterisco;
    else
        goto imprimeEspaco;

imprimeAsterisco:
    printf("*");
    goto avancaColuna;

imprimeEspaco:
    printf(" ");
    goto avancaColuna;

avancaColuna:
    coluna = coluna + 1;
    goto inicioColuna;

fimLinha:
    printf("\n");
    linha = linha + 1;
    goto inicioLinha;

fim:
    return 0;
}
