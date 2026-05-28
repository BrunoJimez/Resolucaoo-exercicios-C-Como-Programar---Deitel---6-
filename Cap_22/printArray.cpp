// Exercicios 22.4 e 22.5 - printArray.cpp
// Tres versoes coexistem:
//   1. Template original (Fig. 22.1 do livro)
//   2. Template SOBRECARREGADO com (lowSubscript, highSubscript) [22.4]
//   3. Versao NAO-TEMPLATE para const char* [22.5]
#include <iostream>
#include <iomanip>
using namespace std;

// === Versao 1 (original do livro): imprime array inteiro ===
template <typename T>
void printArray(const T arr[], int tamanho) {
    for (int i = 0; i < tamanho; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// === Versao 2 (Exercicio 22.4): imprime subintervalo ===
// Retorna o numero de elementos impressos, ou 0 em caso de erro.
template <typename T>
int printArray(const T arr[], int tamanho,
               int lowSubscript, int highSubscript) {
    if (tamanho < 0 || lowSubscript < 0 || highSubscript < 0
        || lowSubscript >= tamanho || highSubscript >= tamanho
        || highSubscript <= lowSubscript) {
        return 0;
    }
    int contador = 0;
    for (int i = lowSubscript; i <= highSubscript; ++i) {
        cout << arr[i] << " ";
        ++contador;
    }
    cout << endl;
    return contador;
}

// === Versao 3 (Exercicio 22.5): nao-template para const char* ===
// (Especializacao explicita por sobrecarga, n\~ao por template<>.)
// Imprime strings em formato organizado, em colunas alinhadas.
void printArray(const char *const arr[], int tamanho) {
    const int LARGURA_COLUNA = 15;
    const int COLUNAS_POR_LINHA = 4;
    for (int i = 0; i < tamanho; ++i) {
        cout << setw(LARGURA_COLUNA) << left << arr[i];
        if ((i + 1) % COLUNAS_POR_LINHA == 0) cout << endl;
    }
    if (tamanho % COLUNAS_POR_LINHA != 0) cout << endl;
}

int main() {
    // Arrays do livro (figura 22.1)
    int   a[] = {1, 2, 3, 4, 5};
    float b[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    char  c[] = "OLA";          // string como array de char

    // === V1: imprimir arrays inteiros ===
    cout << "=== printArray (versao original): ===" << endl;
    cout << "a: "; printArray(a, 5);
    cout << "b: "; printArray(b, 5);
    cout << "c: "; printArray(c, 3);    // imprime 'O' 'L' 'A'

    // === V2: imprimir subintervalos (Ex. 22.4) ===
    cout << "\n=== printArray com range (Ex. 22.4): ===" << endl;
    cout << "a[1..3]: ";
    int n = printArray(a, 5, 1, 3);
    cout << "  (imprimiu " << n << " elementos)" << endl;

    cout << "b[0..4]: ";
    n = printArray(b, 5, 0, 4);
    cout << "  (imprimiu " << n << " elementos)" << endl;

    // Testes de validacao:
    cout << "Tentativa intervalo invalido (low=4 > high=1):" << endl;
    n = printArray(a, 5, 4, 1);
    cout << "  retornou " << n << " (sem impressao)" << endl;

    cout << "Tentativa fora dos limites (high=10):" << endl;
    n = printArray(a, 5, 0, 10);
    cout << "  retornou " << n << " (sem impressao)" << endl;

    cout << "Tentativa low = high (degenerado):" << endl;
    n = printArray(a, 5, 2, 2);
    cout << "  retornou " << n << " (sem impressao porque high <= low)" << endl;

    // === V3: array de strings (Ex. 22.5) ===
    cout << "\n=== printArray para strings (Ex. 22.5): ===" << endl;
    const char *nomes[] = {
        "Alice",    "Bob",      "Carlos",   "Daniela",
        "Eduardo",  "Fernanda", "Gabriel",  "Helena",
        "Igor",     "Julia"
    };
    printArray(nomes, 10);

    return 0;
}
