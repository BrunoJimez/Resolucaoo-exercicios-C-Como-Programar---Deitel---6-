/* Exercicio 14.6 - Tratamento de sinais SIGABRT e SIGINT */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void tratadorSinal(int tipoSinal);

int main(void) {
    /* Registra o mesmo tratador para os dois sinais */
    signal(SIGABRT, tratadorSinal);
    signal(SIGINT,  tratadorSinal);

    printf("Programa iniciado.\n");
    printf("  - Pressione <Ctrl> + <C> para gerar SIGINT.\n");
    printf("  - Apos 5 segundos sem entrada, chamaremos abort()\n");
    printf("    para gerar SIGABRT.\n\n");

    /* Aguarda alguma intervencao do usuario; se nada acontecer,
       dispara abort() para demonstrar a interceptacao de SIGABRT. */
    printf("Pressione <Enter> para chamar abort() agora,\n");
    printf("ou <Ctrl>+<C> para gerar SIGINT: ");
    fflush(stdout);

    int c = getchar();
    if (c == '\n' || c == EOF) {
        printf("\nChamando abort()...\n");
        abort();          /* gera SIGABRT */
    }

    printf("Programa terminou normalmente.\n");
    return EXIT_SUCCESS;
}

void tratadorSinal(int tipoSinal) {
    const char *nome;

    switch (tipoSinal) {
        case SIGABRT: nome = "SIGABRT"; break;
        case SIGINT:  nome = "SIGINT";  break;
        default:      nome = "desconhecido"; break;
    }

    printf("\n>>> Sinal interceptado: %s (codigo %d)\n", nome, tipoSinal);
    printf(">>> O tratador esta encerrando o programa.\n");
    exit(EXIT_FAILURE);
}
