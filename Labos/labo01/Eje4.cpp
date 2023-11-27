#include <iostream>

// Dado un entero, determina si es primo o no

bool f(int x) {
    if (x >= 1) {
        for (int i = 2; i < x; i++) {
            if ((x % i) == 0) {
                return false;
            }
        }
            return true;
    }
    else {
        return false;
    }
}

int main () {
    int x = 15;
    bool n = f(x);
    if (n) {
        std :: cout << x << " es primo : " << std :: endl;
    }
    else {
        std :: cout << x << " no es primo : " << std :: endl;
    }
    return 0;
}