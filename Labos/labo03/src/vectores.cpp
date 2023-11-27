#include "vectores.h"

using namespace std;

// Función para probar en main.cpp si este módulo fue cargado correctamente
void holaModuloVectores(){
    cout << "El módulo vectores fue cargado correctamente" << endl;
}


// Ejercicio
bool divide(const vector<int>& v, int a) {
	// Dados un vector v y un int a, decide si a divide a todos los numeros de v.
    for(int i = 0; i < v.size(); i++) {
        if (v[i] % a != 0) {
            return false;
        }
    }
    return true;
}

void divideAux(const vector<int>& v, int a) {
    if (divide(v,a)) {
        cout << a << " divide a todos los elementos de ";
        mostrarVector(v);
        cout << endl;
    } else {
        cout << a << " no divide a todos los elementos de ";
        mostrarVector(v);
        cout << endl;
    }
}

// Ejercicio
int mayor(vector<int> v) {
	// Dado un vector v, devuelve el valor máximo encontrado.
    int s = v[0];
    for(int i = 0; i < v.size() - 1; i++) {
        if ((v[i] <= v[i + 1]) && (v[i + 1] >= s)) {
            s = v[i + 1];
        }
    }
    return s;
}

void mayorAux(vector<int> v) {
    cout << "El mayor elemento de ";
    mostrarVector(v);
    cout << " es " << mayor(v) << endl;
}


// Ejercicio
vector<int> reverso(vector<int> v) {
	// Dado un vector v, devuelve el reverso.
    vector<int> rev;
    for (int i = 0; i < v.size(); i++) {
        rev.push_back(v[v.size() - 1 - i]);
    }
    return rev;
}

void reversoAux(const vector<int>& v) {
    cout << "El reverso de ";
    mostrarVector(v);
    cout << " es ";
    mostrarVector(reverso(v));
    cout << endl;
}

//Ejercicio
vector<int> rotar(vector<int> v, int k) {
	// Dado un vector v y un entero k, rotar k posiciones los elementos de v.
    while(k > 0) {
        v.push_back(v[0]);
        v = reverso(v);
        v.pop_back();
        v = reverso(v);
        k--;
    }
    return v;
}

void rotarAux(vector<int> v, int k) {
    cout << "El vector ";
    mostrarVector(v);
    cout << " rotado " << k << " veces es ";
    mostrarVector(rotar(v, k));
    cout << endl;
}

bool estaOrdenado(vector<int> v) {
    for (int i = 0; i < v.size() - 1; i++) {
        if(v[i] > v[i + 1]) {
            return false;
        }
    }
    return true;
}

void estaOrdenadoAux(vector<int> v) {
    if(estaOrdenado(v)) {
        mostrarVector(v);
        cout << " está ordenado de forma creciente" << endl;
    } else if (estaOrdenado(reverso(v))) {
        mostrarVector(v);
        cout << " está ordenado de forma decreciente" << endl;
    } else {
        mostrarVector(v);
        cout << " no está ordenado " << endl;
    }
}

//Ejercicio
vector<int> factoresPrimos(int n) {
	//que dado un entero devuelve un vector con los factores primos del mismo
    vector<int> facPrim = {};
    for(int i = 2; i <= n; i ++) {
        if ((n % i == 0) && esPrimo(i)) {
            facPrim.push_back(i);
        }
    }
    return facPrim;
}

bool esPrimo(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void factoresPrimosAux(){
    int n;
    cout << "Ingrese un número entero positivo: ";
    cin >> n;
    cout << "Sus factores primos son: ";
    mostrarVector(factoresPrimos(n));
}

//Ejercicio
void mostrarVector(vector<int> v) {
	// Dado un vector de enteros, muestra el vector por la salida estándar
    cout << "[";
    for (int i = 0; i < v.size() - 1; i ++) {
        cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]";
}
