#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <sstream>

using namespace std;

vector<vector<int> > productoVectorial(vector<int> u, vector<int> v);
void trasponer(vector<vector<int> > &m);
vector<vector<int> > multiplicar(vector<vector<int> > m1, vector<vector<int> > m2);
vector<vector<int> > promediar(vector<vector<int> > m);
int contarPicos(vector<vector<int> > m);
bool esTriangular(vector<vector<int> > m);
bool hayAmenaza(vector<vector<int> > m);
int diferenciaDiagonales(vector<vector<int> > m);

bool estaEnMatriz(vector<vector<int>> m);
int prom(int i, int j, vector<vector<int>> m);
bool esMayorQueVecinos(int q1, int q2, vector<vector<int>> m);

bool esTriangularSuperior(vector<vector<int>> m);
bool esTriangularInferior(vector<vector<int>> m);

bool amenazaAlguien(int q1, int q2, vector<vector<int>> m);
bool amenazaVertical(int q1, int q2, vector<vector<int>> m);
bool amenazaHorizontal(int q1, int q2, vector<vector<int>> m);
bool amenazaDiagonal(int q1, int q2, vector<vector<int>> m);