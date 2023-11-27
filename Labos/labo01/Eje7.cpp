#include <iostream>
using namespace std;

// Dado un entero n, devuelve la suma de todos sus divisores

int sumaDiviRecu(int n, int i) {
    if (n % i == 0) {
        if (n == i) {
            return i;
        }
        else {
            return i + sumaDiviRecu(n, i + 1);
        }
    }
    return sumaDiviRecu(n, i + 1);
}

int sumaDiviIte(int n) {
    int s = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            s = i + s;
        }
    }
  return s;
}

int main() {
    while (true) {
        int n;
        cout << "Ingrese un valor de n: ";
        cin >> n;
        int x = sumaDiviRecu(n, 1);
        int y = sumaDiviIte(n);
        cout << "La suma de los divisores de " << n << " es (" << x << ", " << y <<
             "), con recursión e iteraciones" << endl;
    }
}
