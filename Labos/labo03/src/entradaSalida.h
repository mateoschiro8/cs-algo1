#ifndef LABO03_ENTRADASALIDA_H
#define LABO03_ENTRADASALIDA_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> leerVector(string archivo);

void guardarVector(vector<int> v, string archivo);

void elementoMedioAux(string archivo);
int elementoMedio(vector<int> v);

int sumaMenoresInc(vector<int> v, int k);
int sumaMayoresExc(vector<int> v, int k);

void cantApariciones(string archivo);





#endif //LABO03_ENTRADASALIDA_H
