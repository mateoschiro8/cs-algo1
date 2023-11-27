#include "entradaSalida.h"
#include "vectores.h"

using namespace std;

vector<int> leerVector(string archivo) {
    vector<int> v; int n;
    ifstream archivoIn; // Declara el archivo
    ifstream fin;
    archivoIn.open(archivo,ios::in); // abre modo lectura

    int i = 0;
    while(!archivoIn.eof()) {
        archivoIn >> n;
        v.push_back(n);
        i++;
    }

    archivoIn.close();
    return v;
}

void guardarVector(vector<int> v, string archivo) {
    ofstream archivoOut;
    archivoOut.open(archivo); // crea el archivo
    for (int i = 0; i < v.size(); i++) {
        archivoOut << v[i] << " ";
    }
    archivoOut.close(); // guarda y cierra el archivo
}

void elementoMedioAux(string archivo) {
    vector<int> v = leerVector(archivo);
    int a = elementoMedio(v);
    cout << a;
}
int elementoMedio(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        if(sumaMenoresInc(v, i) >= sumaMayoresExc(v, i)) {
            return v[i];
        }
    }
}

int sumaMenoresInc(vector<int> v, int k) {
    int s = 0;
    for(int i = 0; i <= k; i++) {
        s = s + v[i];
    }
    return s;
}
int sumaMayoresExc(vector<int> v, int k) {
    int s = 0;
    for (int i = k + 1; i < v.size(); i++) {
        s = s + v[i];
    }
    return s;
}

void cantApariciones(string archivo) {
    vector<int> n = leerVector(archivo);
    // mostrarVector(n);
    int a = mayor(n);
    vector<int> c(a);

    for (int i = 0; i < n.size(); i++) {
        c[n[i] - 1]++;
    }

    ofstream archivoOut;
    archivoOut.open("Apariciones"); // crea el archivo
    for (int i = 0; i < c.size(); i++) {
        if (c[i] > 0) {
            archivoOut << "Elemento: " << i + 1 << ", apariciones: " << c[i] << endl;
        }
    }
    archivoOut.close(); // guarda y cierra el archivo
}
