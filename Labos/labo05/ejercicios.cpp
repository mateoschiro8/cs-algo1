#include "ejercicios.h"

// Ejercicio 1
bool existePico(vector<int> v){
    if (v.size() >= 3) {
        int i = 1;
        while (i < v.size() - 1) {
            if (v[i] > v[i - 1] && v[i] > v[i + 1])
                return true;
        i++;
        }
        return false;
    } else {
        return false;
    }
}

// Ejercicio 2
int mcd(int m, int n){
    int resto = 0;
    while(n!=1){
        resto = m%n;
        if (resto == 0)
            return n;
        m = n;
        n = resto;
    }
    return 1;
}

// Ejercicio 3
int indiceMinSubsec(vector<int> v, int l, int r) {
    int i = l;
    int res = l;
    while(i <= r) {
        if (v[i] < v[res]) {
            res = i;
        }
        i++;
    }
    return res;
}

void swappeo(vector<int>& v, int i, int j) {
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// Ejercicio 4
void ordenar1(vector<int>& v){
    int i = 0;
    while(i < v.size() - 1) {
        if(v[i] > v[i + 1]) {
            swappeo(v, i, i + 1);
            i = 0;
        } else {
            i++;
        }
    }
}

// Ejercicio 5
void ordenar2(vector<int>& v){
    ordenar1(v);

    /*
    int i = 0;
    while(i < v.size()) {
        if (v[i] == 0) {

            i = 0;
        } else if (v[i] == 2) {
            v.push_back(2);
            i = 0;
        } else
            i++;
    }
     */
}

// Ejercicio 6
tuple<int,int> division(int n, int d){
    int j = 0;
    while(n >= d) {
        n = n - d;
        j++;
    }
    return make_tuple(j,n);
}
