#ifndef FUNCAO_H
#define FUNCAO_H
#include <vector>

using namespace std;

class Funcao{

private:
    double a;
    double b;
    double c;
    vector< vector<int> > pontos;
public:
    Funcao(double a, double b, double c);
    void makePoints(int dominio_ini, int dominio_fim);
    vector< vector<int> > retornaPontos();
};


#endif // FUNCAO_H
