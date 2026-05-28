// Exercicio 15.10 - Versoes CORRIGIDAS dos quatro segmentos com erro
// (Demonstracao de que as correcoes propostas compilam e funcionam)

#include <iostream>
using namespace std;

// ----- (a) CORRIGIDO -----
// Erro original: o parametro de tipo "class A" do template nao era usado.
// Correcao: ou remover o template, ou substituir int por A nos parametros.
template <typename A>
A sum(A num1, A num2, A num3) {
    return num1 + num2 + num3;
}

// ----- (b) CORRIGIDO -----
// Erro original: funcao declarada como void, mas usa "return x + y;".
// Correcao: mudar o tipo de retorno para int (ou remover o return).
int printResults(int x, int y) {
    cout << "A soma e " << x + y << '\n';
    return x + y;
}

// ----- (c) CORRIGIDO -----
// Erro original: faltou a palavra-chave "class" (ou "typename") antes do A.
// Correcao: template <class A> ou template <typename A>.
template <class A>
A product(A num1, A num2, A num3) {
    return num1 * num2 * num3;
}

// ----- (d) CORRIGIDO -----
// Erro original: nao se pode sobrecarregar funcoes que diferem APENAS
// no tipo de retorno. Para "corrigir", basta dar nomes diferentes
// (ou diferenciar tambem as listas de parametros).
double cubeD(int x) { return static_cast<double>(x) * x * x; }
int    cubeI(int x) { return x * x * x; }

int main() {
    // Testes de (a)
    cout << "sum<int>(1,2,3)         = " << sum(1, 2, 3) << endl;
    cout << "sum<double>(1.5,2.5,3.0)= " << sum(1.5, 2.5, 3.0) << endl;

    // Testes de (b)
    int s = printResults(10, 20);
    cout << "printResults retornou: " << s << endl;

    // Testes de (c)
    cout << "product<int>(2,3,4)     = " << product(2, 3, 4) << endl;
    cout << "product<double>(1.5,2,4)= " << product(1.5, 2.0, 4.0) << endl;

    // Testes de (d)
    cout << "cubeD(3) = " << cubeD(3) << "  cubeI(4) = " << cubeI(4) << endl;

    return 0;
}
