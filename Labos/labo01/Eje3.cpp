#include <iostream>

// Dado dos enteros, devuelve la suma si el primero es mayor al segundo, y el producto en caso contrario

int f(int x, int y) {
    if (x > y) {
        return x + y;
    }
    else {
        return x * y;
    }
}

int main () {
    std :: cout << " El resultado es : " << f (10, 8) << std :: endl;
    return 0;
}