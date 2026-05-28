// Exercicio 17.9 - main_DateAndTime.cpp
#include <iostream>
#include "DateAndTime.h"
using namespace std;

int main() {
    cout << "=== Teste 1: transicao normal de hora ===" << endl;
    DateAndTime dt1(5, 15, 2026, 9, 59, 58);
    cout << "Inicio: "; dt1.printUniversal(); cout << endl;
    for (int i = 0; i < 3; ++i) {
        dt1.tick();
        cout << " Tick #" << (i+1) << ": "; dt1.printUniversal();
        cout << endl;
    }

    cout << "\n=== Teste 2: transicao 23:59:59 -> dia seguinte ===" << endl;
    DateAndTime dt2(5, 15, 2026, 23, 59, 58);
    cout << "Inicio: "; dt2.printUniversal(); cout << endl;
    for (int i = 0; i < 4; ++i) {
        dt2.tick();
        cout << " Tick #" << (i+1) << ": "; dt2.printUniversal();
        cout << endl;
    }

    cout << "\n=== Teste 3: transicao 31/12 23:59:58 -> 1/1/2027 ===" << endl;
    DateAndTime dt3(12, 31, 2026, 23, 59, 58);
    cout << "Inicio: "; dt3.printUniversal(); cout << endl;
    for (int i = 0; i < 4; ++i) {
        dt3.tick();
        cout << " Tick #" << (i+1) << ": "; dt3.printUniversal();
        cout << "  ("; dt3.printStandard(); cout << ")" << endl;
    }

    return 0;
}
