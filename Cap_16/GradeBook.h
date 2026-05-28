// Exercicio 16.11 - GradeBook.h
// Declaracao da classe GradeBook com nome do curso E nome do instrutor
#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <string>

class GradeBook {
public:
    // Construtor que recebe nome do curso e nome do instrutor
    GradeBook(std::string nomeDoCurso, std::string nomeDoInstrutor);

    // Funcoes para o nome do curso
    void setCourseName(std::string nome);
    std::string getCourseName() const;

    // Funcoes para o nome do instrutor
    void setInstructorName(std::string nome);
    std::string getInstructorName() const;

    // Exibe mensagem de boas-vindas
    void displayMessage() const;

private:
    std::string courseName;       // nome do curso
    std::string instructorName;   // nome do instrutor
};

#endif
