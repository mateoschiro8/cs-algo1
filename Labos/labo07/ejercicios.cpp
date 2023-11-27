#include "ejercicios.h"

vector<vector<int>> productoVectorial(vector<int> u, vector<int> v){
	//COMPLETAR
    int largoFila = u.size();
    int largoColumna = v.size();
    vector<vector<int>> res(largoFila, vector<int>(largoColumna));
    for (int i = 0; i < largoFila; ++i) {
        for (int j = 0; j < largoColumna; ++j) {
            res[i][j] = u[i] * v[j];
        }
    }
	return res;
}

void trasponer(vector<vector<int>> &m) {
	//COMPLETAR
    vector<vector<int>> temp = m;
    int largoFila = m.size();
    int largoColumna = m[0].size();
    for (int i = 0; i < largoFila; ++i) {
        for (int j = 0; j < largoColumna; ++j) {
            m[i][j] = temp[j][i];
        }
    }
	return;
}

vector<vector<int>> multiplicar(vector<vector<int>> m1, vector<vector<int> > m2){
	//COMPLETAR
    int cantFilasM1 = m1.size(), cantColumnasM1 = m1[0].size(), cantFilasM2 = m2.size(), cantColumnasM2 = m2[0].size();
    vector<vector<int>> res(cantFilasM1, vector<int>(cantColumnasM2));
    for (int i = 0; i < cantFilasM1; ++i) {
        for (int j = 0; j < cantColumnasM2; ++j) {
            res[i][j] = 0;
            for (int k = 0; k < m2.size(); ++k) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
	return res;
}

vector<vector<int>> promediar(vector<vector<int>> m){
	//COMPLETAR
    int largoFila = m.size();
    int largoColumna = m[0].size();
    vector<vector<int>> res(largoFila, vector<int>(largoColumna));
    for (int i = 0; i < largoFila; ++i) {
        for (int j = 0; j < largoColumna; ++j) {
            res[i][j] = prom(i, j, m);
        }
    }
	return res;
}

bool estaEnMatriz(int i, int j, vector<vector<int>> m) {
    return (i >= 0 && i < m.size() && j >= 0 && j < m[0].size());
}

int prom(int q1, int q2, vector<vector<int>> m){
    int cantVecinos = 0;
    int promedio = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (estaEnMatriz(q1 + i, q2 + j, m)) {
                cantVecinos++;
                promedio = promedio + m[q1 + i][q2 + j];
            }
        }
    }
    return promedio/cantVecinos;
}


int contarPicos(vector<vector<int>> m){
	//COMPLETAR
    int cantPicos = 0;
    int largoFila = m.size();
    int largoColumna = m[0].size();
    for (int i = 0; i < largoFila; ++i) {
        for (int j = 0; j < largoColumna; ++j) {
            if (esMayorQueVecinos(i,j,m))
                cantPicos++;
        }
    }
    return cantPicos;
}

bool esMayorQueVecinos(int q1, int q2, vector<vector<int>> m){
    int cantVecinosMayores = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (estaEnMatriz(q1 + i, q2 + j, m) && m[q1 + i][q2 + j] >= m[q1][q2] && (i != 0 || j != 0)) {
                cantVecinosMayores++;
            }
        }
    }
    return cantVecinosMayores == 0;
}

bool esTriangular(vector<vector<int>> m){
	//COMPLETAR
	return (esTriangularSuperior(m) || esTriangularInferior(m));
}

bool esTriangularSuperior(vector<vector<int>> m){
    bool esTriangular = true;
    int largoColumna = m.size();
    for (int i = 0; i < largoColumna; ++i) {
        for (int j = i + 1; j < largoColumna; ++j) {
            if (m[i][j] != 0)
                esTriangular = false;
        }
    }
    return esTriangular;
}

bool esTriangularInferior(vector<vector<int>> m){
    bool esTriangular = true;
    int largoColumna = m.size();
    for (int j = 0; j < largoColumna; ++j) {
        for (int i = j + 1; i < largoColumna; ++i) {
            if (m[i][j] != 0)
                esTriangular = false;
        }
    }
    return esTriangular;
}

bool hayAmenaza(vector<vector<int>> m){
	//COMPLETAR
    bool hayAmenaza = false;
    int largoFila = m.size();
    int largoColumna = m[0].size();
    for (int i = 0; i < largoFila; ++i) {
        for (int j = i + 1; j < largoColumna; ++j) {
            if (m[i][j] == 1 && amenazaAlguien(i, j, m))
                hayAmenaza = true;
        }
    }
	return hayAmenaza;
}

bool amenazaAlguien(int q1, int q2, vector<vector<int>> m){
    return (amenazaVertical(q1, q2, m) || amenazaHorizontal(q1, q2, m) || amenazaDiagonal(q1, q2, m));
}

bool amenazaVertical(int q1, int q2, vector<vector<int>> m){
    int cantidadReinas = 0;
    int largoFila = m.size();
    int largoColumna = m[0].size();
    for (int i = 0; i < largoFila; ++i) {
        if (m[i][q2] == 1)
            cantidadReinas++;
    }
    return cantidadReinas > 1;
}

bool amenazaHorizontal(int q1, int q2, vector<vector<int>> m){
    int cantidadReinas = 0;
    int largoFila = m.size();
    int largoColumna = m[0].size();
    for (int j = 0; j < largoColumna; ++j) {
        if (m[q1][j] == 1)
            cantidadReinas++;
    }
    return cantidadReinas > 1;
}

bool amenazaDiagonal(int q1, int q2, vector<vector<int>> m){
    int cantidadReinas = 0;
    int largoFila = m.size();
    int largoColumna = m[0].size();
    int i = 0, j = 0;
    i = q1; j = q2;
    while(i >= 0 && i < largoFila && j >= 0 && j < largoColumna) {
        if(m[i][j] == 1) {
            cantidadReinas++;
        }
        i++; j++;
    }
    i = q1; j = q2;
    while(i >= 0 && i < largoFila && j >= 0 && j < largoColumna) {
        if(m[i][j] == 1) {
            cantidadReinas++;
        }
        i++; j--;
    }
    i = q1; j = q2;
    while(i >= 0 && i < largoFila && j >= 0 && j < largoColumna) {
        if(m[i][j] == 1) {
            cantidadReinas++;
        }
        i--; j++;
    }
    i = q1; j = q2;
    while(i >= 0 && i < largoFila && j >= 0 && j < largoColumna) {
        if(m[i][j] == 1) {
            cantidadReinas++;
        }
        i--; j--;
    }
    return cantidadReinas > 4;
}

int diferenciaDiagonales(vector<vector<int>> m) {
    //COMPLETAR
    int sumaTotal = 0, sumaDiagonalDerecha = 0, sumaDiagonalIzquierda = 0;
    int largoMatriz = m.size();
    int i = 0, j = 0;
    while(i >= 0 && i < largoMatriz && j >= 0 && j < largoMatriz) {
        sumaDiagonalDerecha = sumaDiagonalDerecha + m[i][j];
        i++; j++;
    }
    i = 0; j = largoMatriz - 1;
    while(i >= 0 && i < largoMatriz && j >= 0 && j < largoMatriz) {
        sumaDiagonalIzquierda = sumaDiagonalIzquierda + m[i][j];
        i++; j--;
    }
    sumaTotal = sumaDiagonalDerecha - sumaDiagonalIzquierda;
    if (sumaTotal < 0)
        sumaTotal = sumaTotal*(-1);
    return sumaTotal;
}