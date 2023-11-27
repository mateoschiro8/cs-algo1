#include "ejercicios.h"
#include "time.h"
#include <ctime>
#include "stdlib.h"
#include <string>
#include<iostream>
#include <cmath>

using namespace std;

int busquedaBinaria(vector<int> v, int x) {
    int low = 0, high = v.size() - 1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(v[mid] == x)
            return mid;
        if(v[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int busquedaJumpSearch(vector<int> v, int x) {
    int m = sqrt(v.size());
    int i = 0;
    while (v[i] != x) {
        if (i < v.size()) {
            if (v[i] < x)
                i = i + m;
            else if (v[i] > x) {
                for (int j = i - m; j < i; ++j) {
                    if (v[j] == x)
                        return j;
                }
            }
        }
        for (int j = i - m; j < v.size(); ++j) {
            if (v[j] == x)
                return j;
        }
        return -1;
    }
	return i;
}

int buscar(vector<int> v, int x){
    return busquedaBinaria(v, x);
    //return busquedaJumpSearch(v, x);
}

void medirTiemposBusquedas() {
    for (int i = 100; i <= 100000; i = 10 * i) {

        cout << "###   n = " << i << "   ###" << endl;

        vector<int> v = construir_vector(i, "azar");

        time_t t;
        srand((unsigned) time(&t));

        clock_t begin = clock();
        int j = busquedaBinaria(v, rand() % i);
        clock_t end = clock();
        double elapsed_msecs = double(end - begin) / CLOCKS_PER_SEC  * 1000; // mide el tiempo en ms
        cout << "Busqueda Binaria: " << elapsed_msecs << endl;

        begin = clock();
        j = busquedaJumpSearch(v, rand() % i);
        end = clock();
        elapsed_msecs = double(end - begin) / CLOCKS_PER_SEC  * 1000; // mide el tiempo en ms
        cout << "Busqueda Jump: " << elapsed_msecs << endl;
    }
}

double ejemplo_como_calcular_tiempos() {
    clock_t begin = clock();

    for(int i=0 ; i < 100000; i++){
        // nada
    }

    clock_t end = clock();
    double elapsed_msecs = double(end - begin) / CLOCKS_PER_SEC  * 1000; // mide el tiempo en milisegundos
    return elapsed_msecs;
}

vector<int> construir_vector(int size, string mode){
    vector<int> res {};
    time_t t;
    srand((unsigned) time(&t));
    int base = rand() % 100;
    int step;
    for(int i = 0; i < size; i++){
        step = rand() % 100;
        if(mode == "asc") {
            res.push_back(base+step);
            base += step;
        }
        if(mode == "desc"){
            res.push_back(base-step);
            base -= step;
        }
        if(mode == "azar"){
            res.push_back(step);
        }
        if(mode == "iguales"){
            res.push_back(base);
        }
    }
    return res;
}

int indicePico(vector<int> v){
    if (v.size() == 1)
        return 0;
    else if(v.size() == 2) {
        if (v[0] >= v[1])
            return 0;
        else if (v[0] <= v[1])
            return 1;
    } else {
        for (int i = 1; i < v.size() - 1; i++) {
            if (v[i] >= v[i - 1] && v[i] >= v[i + 1])
                return i;
        } if (v[v.size() - 1] >= v[v.size() - 2])
            return v.size() - 1;
    }
	return -1;
}

int puntoFijo(vector<int> v){
    /*
    for (int i = 0; i < v.size(); ++i) {
        if(v[i] == i)
            return i;
    }
    return -1; */

    int low = 0, high = v.size() - 1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(v[mid] == mid)
            return mid;
        if(v[mid] < mid) {
            low = mid + 1;
            if (v[low] == low)
                return low;
        }
        else
            high = mid - 1;
    }
    return -1;
}

int encontrarRotado(vector<int> v, int x){
	return -1;
}

int menorMasGrande(vector<int> v, int x){
 // Buscar manera de hacer algo similar a la busqueda binaria.

    for (int i = 0; i < v.size(); ++i) {
        if(v[i] > x)
            return i;
    }
    return -1;
}


vector<int> masCercanoK(vector<int> v, int k,  int x){
	return {};
}
