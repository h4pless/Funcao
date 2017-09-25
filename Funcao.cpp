#include "Funcao.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>


using namespace std;

double e = 2.71828;

Funcao::Funcao(double a, double b, double c){

    this->a = a;
    this->b = b;
    this->c = c;
}

void Funcao::makePoints(int dominio_ini, int dominio_fim){

    int aux;
    double expoente;
    vector<int> quantPontos;
    quantPontos.push_back(dominio_fim - dominio_ini);
    pontos.push_back(quantPontos);
    for(int i = dominio_ini; i < dominio_fim; i++){
        vector<int> ponto1;
        expoente = -(pow(i-b, 2)/(2*pow(c, 2)));
        aux = pow(e, expoente)*a;
        ponto1.push_back(i);
        ponto1.push_back(aux);
        pontos.push_back(ponto1);
        ponto1.clear();
    }
}

vector< vector<int> > Funcao::retornaPontos(){
    return pontos;
}
