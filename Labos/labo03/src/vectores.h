#ifndef EJERCICIOS_H
#define EJERCICIOS_H

#include <iostream>
#include <vector>

using namespace std;

void holaModuloVectores();

//Ejercicio
bool divide(const vector<int>& v, int a);
// Dados un vector v y un int a, decide si a divide a todos los numeros de v.

void divideAux(const vector<int>& v, int a);

//Ejercicio
int mayor(vector<int> v);
// Dado un vector v, devuelve el valor maximo encontrado.

void mayorAux(vector<int> v);

//Ejercicio
vector<int> reverso(vector<int> v);
// Dado un vector v, devuelve el reverso.

void reversoAux(const vector<int>& v);

//Ejercicio
vector<int> rotar(vector<int> v, int k);
// Dado un vector v y un entero k, rotar k posiciones los elementos de v.
// [1,2,3,4,5,6] rotado 2, deberia dar [3,4,5,6,1,2].

void rotarAux(vector<int> v, int k);


bool estaOrdenado(vector<int> v);

void estaOrdenadoAux(vector<int> v);


//Ejercicio
vector<int> factoresPrimos(int n);
// Dado un entero devuelve un vector con los factores primos del mismo

void factoresPrimosAux();
bool esPrimo(int n);
//Ejercicio
void mostrarVector(vector<int> v);
// Dado un vector de enteros muestra por la salida estándar, el vector
// Ejemplo: si el vector es <1, 2, 5, 65> se debe mostrar en pantalla [1, 2, 5, 65]

// Y aca van todos los otros headers de los ejercicios del laboratorio

#endif