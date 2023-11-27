#include <iostream>

using namespace std;

int main() {
    float n = 0;
    int i = 1;
    int t = 0;
    while(t != -1) {
        cout << "Ingrese la nota " << i << ", o -1 para finalizar: " << endl;
        cin >> t;
        if (0 <= t && t <= 10) {
            n = n + t;
            i++;
        }
        else {
            cout << "Nota no valida" << endl;
        }
    }
    i--;
    cout << "La suma total es " << n << " y el promedio es " << n/i << endl;
    return 0;
}
