// Binario a decimal

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int binADec(int bin, int dec) {
    string tmp;
    tmp = to_string(bin);
    int dig = tmp.size();

    for (int i = 0; i <= dig; i++) {
        dec = dec + tmp[dig - i] * pow(2,(dig - i));
    }
    return dec;
}

int main() {
    double bin = 0;
    int dec = 0;

    while (true) {
        cout << "Ingrese un número en binario, con menos de 12 dígitos: " << endl;
        cin >> bin;
        if (bin != -1) {
            dec = binADec(bin, dec);
            cout << "Su equivalente en decimal es " << dec << endl;
        } else {
            break;
        }
    }
    return 0;
}
