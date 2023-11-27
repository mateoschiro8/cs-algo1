#include <iostream>
using namespace std;

// Dado un entero n, devuelve el n-ésimo termino de la sucesión de Fibonacci

int fiboRecu(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return fiboRecu(n - 1) + fiboRecu(n - 2);
    }
}

int fiboIte(int n) {
    int fibo[n];
    for(int i = 0; i <= n; i++) {
        if (i == 0) {
            fibo[i] = 0;
        }
        else if (i == 1) {
            fibo[i] = 1;
        }
        else {
            fibo[i] = fibo[i - 1] + fibo[i - 2];
        }
    }
    return fibo[n];
}

int main() {
    while (true) {
        int n;
        cout << "Ingrese un valor de n: ";
        cin >> n;
        int x = fiboRecu(n);
        int y = fiboIte(n);
        cout << "El " << n << " término de la sucesión es (" << x << ", " << y <<
                  "), con recursión e iteraciones" << endl;
    }
}