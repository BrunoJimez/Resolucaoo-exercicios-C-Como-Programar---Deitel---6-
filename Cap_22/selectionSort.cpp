// Exercicio 22.3 - selectionSort.cpp
// Template de selection sort: classifica em ordem CRESCENTE.
// Funciona para qualquer tipo T que suporte operator< e operator=.
#include <iostream>
#include <iomanip>
using namespace std;

// Template de funcao: T eh o tipo parametrizado
template <typename T>
void selectionSort(T arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; ++i) {
        // Procura o menor elemento na sub-array [i..tamanho-1]
        int indiceMenor = i;
        for (int j = i + 1; j < tamanho; ++j) {
            if (arr[j] < arr[indiceMenor])
                indiceMenor = j;
        }
        // Troca arr[i] com arr[indiceMenor]
        if (indiceMenor != i) {
            T temp = arr[i];
            arr[i] = arr[indiceMenor];
            arr[indiceMenor] = temp;
        }
    }
}

// Template auxiliar para imprimir um array
template <typename T>
void imprimirArray(const T arr[], int tamanho) {
    for (int i = 0; i < tamanho; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    // === Teste 1: array de int ===
    cout << "=== Teste com array de int ===" << endl;
    int vi[] = {64, 25, 12, 22, 11, 90, 1, 33};
    const int N1 = sizeof(vi) / sizeof(vi[0]);
    cout << "Antes:   ";  imprimirArray(vi, N1);
    selectionSort(vi, N1);
    cout << "Depois:  ";  imprimirArray(vi, N1);

    // === Teste 2: array de float ===
    cout << "\n=== Teste com array de float ===" << endl;
    float vf[] = {3.14f, 1.41f, 2.71f, 0.577f, 1.618f};
    const int N2 = sizeof(vf) / sizeof(vf[0]);
    cout << fixed << setprecision(3);
    cout << "Antes:   ";  imprimirArray(vf, N2);
    selectionSort(vf, N2);
    cout << "Depois:  ";  imprimirArray(vf, N2);

    // === Teste 3 (bonus): array de char ===
    cout << "\n=== Teste com array de char ===" << endl;
    char vc[] = {'h', 'e', 'l', 'l', 'o'};
    const int N3 = sizeof(vc) / sizeof(vc[0]);
    cout << "Antes:   ";  imprimirArray(vc, N3);
    selectionSort(vc, N3);
    cout << "Depois:  ";  imprimirArray(vc, N3);

    return 0;
}
