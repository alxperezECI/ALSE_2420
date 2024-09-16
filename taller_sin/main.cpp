#include <iostream>
#include <cmath>
#include <cstdlib> // Para usar atof
using namespace std;

int main(int argc, char** argv) {
    if (argc < 3) { // Verificamos que hay suficientes argumentos
        cout << "Uso: " << argv[0] << " <incremento> <t>" << endl;
        return 1;
    }
    
    float incr = atof(argv[1]);
    float t = atof(argv[2]);
    float y[100] = {0}; // Inicializamos los arreglos
    float x[100] = {0};

    for (int i = 0; i < 100; i++) {
        x[i] = i * incr; // Usamos el índice para calcular x[i]
    }

    for (int i = 0; i < 100; i++) {
        y[i] = sin(2 * M_PI * t * x[i]);
    }

    for (int i = 1; i < 100; i++) {
        if ((y[i] > 0 && y[i-1] < 0) || (y[i] < 0 && y[i-1] > 0)) {
            cout << x[i-1] << "," << y[i-1] << " <-" << endl;
        } else {
            cout << x[i-1] << "," << y[i-1] << endl;
        }
    }

    return 0;
}