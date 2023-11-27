#include <iostream>
using namespace std;

// Dados enteros n y k, computa el combinatorio (n k), sin utilizar factoriales.

int combinRecu(int n, int k) {
    if (k == n) {
        return 1;
    }
    else if(k == 1) {
        return n;
    }
    else {
        return combinRecu(n - 1, k) + combinRecu(n - 1, k - 1);
    }
}

int combinIte(int n, int k) {

}

int main() {
    while (true) {
        int n, k;
        cout << "Ingrese valores de n y k: " << endl;
        cin >> n;
        cin >> k;
        int x = combinRecu(n, k);
        int y = combinIte(n, k);
        cout << "El combinatorio entre " << n << " y " << k << " es (" << x << ", " << y <<
                                                 "), con recursión e iteraciones" << endl;
    }
}
