// Exercicio 21.14 - TrianguloDes.cpp
#include <sstream>
#include "TrianguloDes.h"
using namespace std;

TrianguloDes::TrianguloDes(int xi, int yi, int a, char p)
    : FormaDesenhavel(xi, yi, p), altura(a > 0 ? a : 1) {}

// Triangulo retangulo: a primeira linha tem 1 ponto, a segunda 2, etc.
void TrianguloDes::desenhar(Tela &t) const {
    int alt = (int)t.size();
    int lar = alt > 0 ? (int)t[0].size() : 0;
    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j <= i; ++j) {
            int ty = y + i, tx = x + j;
            if (ty >= 0 && ty < alt && tx >= 0 && tx < lar)
                t[ty][tx] = preenche;
        }
    }
}

string TrianguloDes::descricao() const {
    ostringstream oss;
    oss << "Triangulo(" << x << "," << y << ") altura=" << altura
        << " '" << preenche << "'";
    return oss.str();
}
