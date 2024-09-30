
#include <iostream>
using namespace std;

// Estructura para representar números complejos
struct complex {
    double re;  // Parte real
    double im; // Parte imaginaria
    
    // Constructor por defecto
    complex(double r = 0., double i = 0.) : re(r), im(i) {}
};

// Función para calcular el ángulo en radianes
double angle(complex c) {
    return atan2(c.im, c.re);
}

// Función para calcular la magnitud
double magnitude(complex c) {
    return sqrt(c.re * c.re + c.im * c.im);
}

// Función para calcular el conjugado
complex conjugate(complex c) {
    return complex(c.re, -c.im);
}

// Sobrecarga del operador +
complex operator+(complex a, complex b) {
    return complex(a.re + b.re, a.im + b.im);
}

// Sobrecarga del operador -
complex operator-(complex a, complex b) {
    return complex(a.re - b.re, a.im - b.im);
}

// Sobrecarga del operador *
complex operator*(complex a, complex b) {
    double r = a.re * b.re - a.im * b.im;
    double i = a.re * b.im + a.im * b.re;
    return complex(r, i);
}

// Sobrecarga del operador == para comparación de igualdad
bool operator==(complex a, complex b) {
    return magnitude(a) == magnitude(b);
}

// Sobrecarga del operador < para comparación menor que
bool operator<(complex a, complex b) {
    return magnitude(a) < magnitude(b);
}

// Sobrecarga del operador > para comparación mayor que
bool operator>(complex a, complex b) {
    return magnitude(a) > magnitude(b);
}

// Sobrecarga del operador << para salida en consola
ostream& operator<<(ostream& out, const complex& c) {
    out << c.re << " + " << c.im << "i";
    return out;
}
//*El operador <<se utiliza para escribir datos en la salida estándar (por ejemplo, en la consola). Cuando se sobrecarga  para el tipo complex, se esta diciendo al compilador que sabe cómo imprimir objetos de tipo complex de manera personalizada.
