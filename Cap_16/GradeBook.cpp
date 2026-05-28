// Exercicio 16.11 - GradeBook.cpp
// Implementacao das funcoes-membro da classe GradeBook
#include <iostream>
#include "GradeBook.h"
using namespace std;

// Construtor: inicializa os dois dados-membro
GradeBook::GradeBook(string nomeDoCurso, string nomeDoInstrutor)
    : courseName(nomeDoCurso), instructorName(nomeDoInstrutor) {
}

// Set/get para o nome do curso
void GradeBook::setCourseName(string nome) {
    courseName = nome;
}

string GradeBook::getCourseName() const {
    return courseName;
}

// Set/get para o nome do instrutor
void GradeBook::setInstructorName(string nome) {
    instructorName = nome;
}

string GradeBook::getInstructorName() const {
    return instructorName;
}

// Exibe mensagem de boas-vindas, nome do curso e nome do instrutor
void GradeBook::displayMessage() const {
    cout << "Bem-vindo ao livro de notas para\n" << courseName << "!\n"
         << "Esse curso e apresentado por: " << instructorName << endl;
}
