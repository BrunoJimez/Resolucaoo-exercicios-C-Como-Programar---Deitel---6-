// Exercicio 21.13 - main_Forma.cpp
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include "Forma.h"
#include "FormaBidimensional.h"
#include "FormaTridimensional.h"
#include "Circulo.h"
#include "Quadrado.h"
#include "Triangulo.h"
#include "Esfera.h"
#include "Cubo.h"
#include "Cilindro.h"
using namespace std;

int main() {
    cout << fixed << setprecision(4);

    // Vector de ponteiros Forma para formas concretas
    vector<unique_ptr<Forma>> formas;
    formas.push_back(unique_ptr<Forma>(new Circulo(5.0)));
    formas.push_back(unique_ptr<Forma>(new Quadrado(4.0)));
    formas.push_back(unique_ptr<Forma>(new Triangulo(6.0, 4.0)));
    formas.push_back(unique_ptr<Forma>(new Esfera(3.0)));
    formas.push_back(unique_ptr<Forma>(new Cubo(2.0)));
    formas.push_back(unique_ptr<Forma>(new Cilindro(2.0, 5.0)));

    cout << "=== Processamento polimorfico de formas ===" << endl;
    for (const auto &fp : formas) {
        cout << "\n* ";
        fp->print();    // POLIMORFISMO!

        // dynamic_cast para descobrir o tipo concreto
        FormaBidimensional *p2D = dynamic_cast<FormaBidimensional*>(fp.get());
        FormaTridimensional *p3D = dynamic_cast<FormaTridimensional*>(fp.get());

        if (p2D) {
            cout << "\n  [2D] Area = " << p2D->retArea();
        } else if (p3D) {
            cout << "\n  [3D] Area total da superficie = " << p3D->retArea()
                 << "\n       Volume = " << p3D->retVolume();
        }
    }
    cout << endl;

    return 0;
}
