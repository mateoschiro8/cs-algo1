#include <iostream>

using namespace std;

int main() {
    float n = 0;
    int i = 1;
    int t = 0;
    while(i <= 10) {
        cout << "Ingrese la nota " << i << ": " << endl;
        cin >> t;
        if (0 <= t && t <= 10) {
            n = n + t;
            i++;
        }
        else {
            cout << "Nota no valida" << endl;
        }
    }
    cout << "La suma total es " << n << " y el promedio es " << n/10 << endl;
    return 0;
}
