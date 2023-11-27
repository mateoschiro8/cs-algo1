#include "ejercicios.h"

using namespace std;

int main() {
/*
    int n = 20000;
    vector<int> v = construir_vector(n, "azar");

    double t0 = clock();
    bool tieneDupl = hayDuplicados(v);
    double t1 = clock();

    double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << tiempo;
    return 0;
*/
    int n = 1; int hasta = 10000; int paso = 5000;
    ofstream fout;
    fout.open("datos.csv");
    fout << "n\t" << "tiempo" <<endl;
    fout << "n\t" << "tiempo" <<endl;

    while(n < hasta){
        vector<int> v = construir_vector(n, "asc");

        double t0=clock();
        bool tieneDupl = hayDuplicados(v);
        double t1 = clock();

        double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);

        fout << n << "\t" << tiempo << endl;

        n +=paso;

        }

    fout.close();
}