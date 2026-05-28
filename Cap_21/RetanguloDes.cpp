// Exercicio 21.14 - RetanguloDes.cpp
#include <sstream>
#include "RetanguloDes.h"
using namespace std;

RetanguloDes::RetanguloDes(int xi, int yi, int l, int a, char p)
    : FormaDesenhavel(xi, yi, p),
      largura(l > 0 ? l : 1), altura(a > 0 ? a : 1) {}

void RetanguloDes::desenhar(Tela &t) const {
    int alt = (int)t.size();
    int lar = alt > 0 ? (int)t[0].size() : 0;
    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j < largura; ++j) {
            int ty = y + i, tx = x + j;
            if (ty >= 0 && ty < alt && tx >= 0 && tx < lar)
                t[ty][tx] = preenche;
        }
    }
}

string RetanguloDes::descricao() const {
    ostringstream oss;
    oss << "Retangulo(" << x << "," << y << ") "
        << largura << "x" << altura << " '" << preenche << "'";
    return oss.str();
}
