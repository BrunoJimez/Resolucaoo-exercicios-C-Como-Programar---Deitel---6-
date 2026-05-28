// Exercicio 21.14 - CirculoDes.cpp
#include <sstream>
#include "CirculoDes.h"
using namespace std;

CirculoDes::CirculoDes(int xi, int yi, int r, char p)
    : FormaDesenhavel(xi, yi, p), raio(r > 0 ? r : 1) {}

// Desenha aproximadamente um disco: todas as celulas (i,j) tais
// que (i-cx)^2 + (j-cy)^2 <= r^2 sao marcadas.
void CirculoDes::desenhar(Tela &t) const {
    int alt = (int)t.size();
    int lar = alt > 0 ? (int)t[0].size() : 0;
    for (int i = -raio; i <= raio; ++i) {
        for (int j = -raio; j <= raio; ++j) {
            if (i*i + j*j <= raio*raio) {
                int ty = y + i, tx = x + j;
                if (ty >= 0 && ty < alt && tx >= 0 && tx < lar)
                    t[ty][tx] = preenche;
            }
        }
    }
}

string CirculoDes::descricao() const {
    ostringstream oss;
    oss << "Circulo centro=(" << x << "," << y << ") raio=" << raio
        << " '" << preenche << "'";
    return oss.str();
}
