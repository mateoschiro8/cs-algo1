#include <iostream>
#include "gtest/gtest.h"
#include "ejercicios.h"

using namespace std;

void swap(vector<int> &v, int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int minim(vector<int> &v, int low, int high) {
    int index = low;
    for(int i = low; i < high; ++i) {
        if(v[index] > v[i])
            index = i;
    }
    return index;
}

void selectionSort(vector<int> &arr){
    //Rellenar selection
    for (int i = 0; i < arr.size(); ++i) {
        int min = minim(arr, i, arr.size());
        swap(arr, i, min);
    }
}

void insert(vector<int> &v, int j, int i) {
    vector<int> temp;
    for (int k = 0; k < v.size() + 1; ++k) {
        if(k < j)
            temp.push_back(v[k]);
        else if(k == j)
            temp.push_back(v[i]);
        else if(k - 1 != i)
            temp.push_back(v[k - 1]);
    }
    v = temp;
}

void insertionSort(vector<int> &v){
    //Rellenar insertion
    for (int i = 1; i < v.size(); ++i) {
        for(int j = 0; j < i; ++j) {
            if (v[0] > v[i])
                insert(v, 0, i);
            else if(v[j] <= v[i] && v[j + 1] > v[i]) {
                insert(v, j + 1, i);
            }
        }
    }
}

int maxim(vector<int> &v, int low, int high) {
    int index = low;
    for(int i = low; i < high; ++i) {
        if(v[index] < v[i])
            index = i;
    }
    return index;
}

void selectionSortDesc(vector<int> &arr) {
    //Rellenar selection
    for (int i = 0; i < arr.size(); ++i) {
        int max = maxim(arr, i, arr.size());
        swap(arr, i, max);
    }
}

void mostrarVector(vector<int> v) {
    // Dado un vector de enteros, muestra el vector por la salida estándar
    cout << "[";
    for (int i = 0; i < v.size() - 1; i ++) {
        cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
}

void bubbleSort(vector<int> &v) {
    int i = 0, j;
    while(i < v.size() - 1) {
        j = 0;
        while(j < v.size() - 1) {
            if (v[j] > v[j + 1]) {
                swap(v, j, j + 1);
                //mostrarVector(v);
            }
            j++;
        }
        i++;
    }
}

void cocktailSort(vector<int> &v) {
    int i = 0, j;
    while(i < v.size()/2 - 1) {
        j = 0;
        while(j < v.size() - 1) {
            if (v[j] > v[j + 1]) {
                swap(v, j, j + 1);
                //mostrarVector(v);
                }
            j++;
        }
        j = v.size() - 1;
        while(j > 0) {
            if (v[j] < v[j - 1]) {
                swap(v, j, j - 1);
                //mostrarVector(v);
                }
            j--;
        }
        i++;
    }
}

// PRACTICA 2do PARCIAL

int cantidadDistintos(vector<int> s, int a, int b) {
    vector<int> dist = {};
    bool esta;
    for (int i = a; i <= b ; ++i) {
        esta = false;
        for (int j = 0; j < dist.size() && !esta; ++j) {
            if(s[i] == dist[j])
                esta = true;
        }
        if (!esta)
            dist.push_back(s[i]);
    }
    return dist.size();
}

int indiceCantidadDistintos(vector<int> s) {
    int indice = -1;
    for (int i = 0; i < s.size(); ++i) {
        if(cantidadDistintos(s, 0, i) == cantidadDistintos(s, i + 1, s.size() - 1))
            indice = i;
    }
    return indice;
}


bool estaEnRango(vector<vector<int>> t, int x, int y) {
    return(x >= 0 && x < t[0].size() && y >= 0 && y < t.size());
}

bool esVecinoOrt(int x1, int y1, int x2, int y2) {
    return (x1 == x2 + 1 && y1 == y2) || (x1 == x2 - 1 && y1 == y2) ||
            (x1 == x2 && y1 == y2 + 1) || (x1 == x2 && y1 == y2 - 1);
}

int largoViborita(vector<vector<int>> t, int fC, int cC) {
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            if(estaEnRango(t, fC + i, cC + j) && esVecinoOrt(fC, cC, fC + i, cC + j) && t[fC + i][cC + j]) {
                t[fC][cC] = false;
                return 1 + largoViborita(t,fC + i,cC +j);
            }
        }
    }
    return 1;
}

void removeElem(vector<int> & v, int index){
    for(int i = index; i < v.size()-1; i++)
        v[i] = v[i+1];
    v.pop_back();
}

int main(int argc, char **argv) {

   /* cout << "Implementando GTest!!" << endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); */

    // medirTiemposBusquedas();
    // vector <int> v = {3,5,7,3,9,4,6,8,2,2,9,3,4,7,1,8,4,5,7,4,2,3};
    //vector <int> v = {9,3,7,2};
    vector <int> v = {1,1,7,3,2,4,6};
    mostrarVector(v);
    removeElem(v, 5);
    mostrarVector(v);


    /*int ind = indiceCantidadDistintos(v);
    // cout << ind;

    vector<vector<int>> t = {{true, true, false, false},
                             {false, true, false, false},
                             {false, true, true, false},
                             {false, false, true, false}};

    int largo = largoViborita(t, 0, 0);
    cout << largo;
    /*
    mostrarVector(v);
    cout << endl;
    cocktailSort(v);
    mostrarVector(v);
/*
    cout << minim(v, 2, v.size() - 1);

    return 0;
    */
}
