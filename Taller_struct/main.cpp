#include <iostream>
#include "complex.h" // Incluimos el archivo de encabezado para usar la estructura complex

using namespace std;

int main() {
    complex a(3.0, 4.0); // Creamos un número complejo a con parte real 3.0 y parte imaginaria 4.0
    complex b(1.0, 2.0); // Creamos otro número complejo b con parte real 1.0 y parte imaginaria 2.0

    // Sumar a y b
    complex c = a + b; // Usamos la sobrecarga del operador + para sumar a y b
    cout << "Suma: " << c << endl; // Imprimimos el resultado de la suma

    // Restar a y b
    complex d = a - b; // Usamos la sobrecarga del operador - para restar a y b
    cout << "Resta: " << d << endl; // Imprimimos el resultado de la resta

    // Multiplicar a y b
    complex e = a * b; // Usamos la sobrecarga del operador * para multiplicar a y b
    cout << "Multiplicación: " << e << endl; // Imprimimos el resultado de la multiplicación

    // Comparaciones
    cout << "¿a es igual a b? " << (a == b) << endl; // Comparamos a y b
    cout << "¿a es mayor que b? " << (a > b) << endl; // Comparamos si a es mayor que b
    cout << "¿a es menor que b? " << (a < b) << endl; // Comparamos si a es menor que b

    return 0; // Finaliza el programa
}
