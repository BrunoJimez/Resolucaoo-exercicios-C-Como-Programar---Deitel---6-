// Exercicio 22.7 - Array.h
// Template de classe Array com DOIS parametros:
//   - numeroDeElementos: parametro NAO-TIPO (int conhecido em compilacao)
//   - tipoElemento:      parametro de tipo
// Inclui especializacao EXPLICITA para Array<float, N>.
#ifndef ARRAY_TEMPLATE_H
#define ARRAY_TEMPLATE_H

#include <iostream>
#include <iomanip>

// === Template primario (geral) ===
template <typename tipoElemento, int numeroDeElementos>
class Array {
public:
    Array() {
        // Inicializa todos com valor "zero" do tipo
        for (int i = 0; i < numeroDeElementos; ++i)
            dados[i] = tipoElemento();
    }

    int tamanho() const { return numeroDeElementos; }

    tipoElemento &operator[](int i) { return dados[i]; }
    const tipoElemento &operator[](int i) const { return dados[i]; }

    void imprimir() const {
        std::cout << "[Array geral] ";
        for (int i = 0; i < numeroDeElementos; ++i)
            std::cout << dados[i] << " ";
        std::cout << std::endl;
    }

private:
    tipoElemento dados[numeroDeElementos];
};

// === Especializacao para float ===
// Imprime com precisao fixa de 3 casas, formato fechado entre colchetes.
template <int numeroDeElementos>
class Array<float, numeroDeElementos> {
public:
    Array() {
        for (int i = 0; i < numeroDeElementos; ++i)
            dados[i] = 0.0f;
    }

    int tamanho() const { return numeroDeElementos; }

    float &operator[](int i) { return dados[i]; }
    const float &operator[](int i) const { return dados[i]; }

    void imprimir() const {
        std::cout << "[Array<float> especializado] [ ";
        for (int i = 0; i < numeroDeElementos; ++i) {
            std::cout << std::fixed << std::setprecision(3)
                      << dados[i];
            if (i < numeroDeElementos - 1) std::cout << ", ";
        }
        std::cout << " ]" << std::endl;
    }

private:
    float dados[numeroDeElementos];
};

#endif
