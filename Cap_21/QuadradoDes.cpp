// Exercicio 21.14 - QuadradoDes.cpp
#include <sstream>
#include "QuadradoDes.h"
using namespace std;

QuadradoDes::QuadradoDes(int xi, int yi, int l, char p)
    : FormaDesenhavel(xi, yi, p), lado(l > 0 ? l : 1) {}

void QuadradoDes::desenhar(Tela &t) const {
    int alt = (int)t.size();
    int lar = alt > 0 ? (int)t[0].size() : 0;
    for (int i = 0; i < lado; ++i) {
        for (int j = 0; j < lado; ++j) {
            int ty = y + i;
            int tx = x + j;
            if (ty >= 0 && ty < alt && tx >= 0 && tx < lar)
                t[ty][tx] = preenche;
        }
    }
}

string QuadradoDes::descricao() const {
    ostringstream oss;
    oss << "Quadrado(" << x << "," << y << ") lado=" << lado
        << " '" << preenche << "'";
    return oss.str();
}
