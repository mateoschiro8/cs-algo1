#include <iostream>

using namespace std;

int main() {
    float n = 0;
    int i = 1;
    int t = 0;
    int ap = 0;
    while(true) {
        cout << "Ingrese la nota " << i << ", o -1 para finalizar: " << endl;
        cin >> t;
        if (t == -1) {
            if (i >= 6) {
                break;
            } else {
                cout << "Cantidad de notas totales no suficiente" << endl;
            }
        } else if (0 <= t && t <= 10) {
            n = n + t;
            i++;
            if (6 <= t) {
                ap++;
            }
        } else {
            cout << "Nota no valida" << endl;
        }
    }
    cout << "La suma total es " << n << ", el promedio es " << n/i <<
                               ", y hay " << ap << " aprobados y " << i - 1 -ap << " desaprobados " << endl;

    if (ap > (i * (2/3))) {   // esto funciona mal y no sé por qué xddd
        cout << "Puede incrementar el numero de plazas!" << endl;
    }
    return 0;
}
