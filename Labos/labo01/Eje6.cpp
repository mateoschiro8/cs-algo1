#include <iostream>
using namespace std;

// Dado un entero n, devuelve la suma de todos los numeros impares menores que n (sin incluir a n)

int sumaImpRecu(int n) {
    if(n % 2 == 1) {
        return n + sumaImpRecu(n - 1);
    }
    else if(n == 0) {
        return 0;
    }
    else {
        return sumaImpRecu(n - 1);
    }
}

int sumaImpIte(int n) {
    int s = 0;
    for(int i = 1; i < n; i++) {
        if (i % 2 == 1) {
          s = s + i;
        }
    } return s;
}

int main() {
    while (true) {
        int n;
        cout << "Ingrese un valor de n: ";
        cin >> n;
        int x = sumaImpRecu(n) - n;
        int y = sumaImpIte(n);
        cout << "La suma de los impares menores a " << n << " es (" << x << ", " << y <<
             "), con recursión e iteraciones" << endl;
    }
}
