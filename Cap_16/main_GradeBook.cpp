// Exercicio 16.11 - main_GradeBook.cpp
// Programa de teste da classe GradeBook modificada
#include <iostream>
#include "GradeBook.h"
using namespace std;

int main() {
    // Cria dois objetos com nome do curso e nome do instrutor
    GradeBook livro1("CS101 - Introducao a Programacao em C++",
                     "Prof. Paulo Souza");
    GradeBook livro2("CS201 - Estruturas de Dados",
                     "Profa. Maria Santos");

    // Exibe as informacoes iniciais
    cout << "==== Livro 1 ====\n";
    livro1.displayMessage();
    cout << "\n==== Livro 2 ====\n";
    livro2.displayMessage();

    // Atualiza o instrutor do livro 1
    cout << "\n>>> Atualizando o instrutor do Livro 1...\n";
    livro1.setInstructorName("Prof. Roberto Almeida");

    cout << "\n==== Livro 1 (apos atualizacao) ====\n";
    livro1.displayMessage();

    // Demonstra as funcoes get
    cout << "\n>>> Recuperando via get:\n";
    cout << "Curso  do Livro 2: " << livro2.getCourseName() << "\n";
    cout << "Instr. do Livro 2: " << livro2.getInstructorName() << "\n";

    return 0;
}
