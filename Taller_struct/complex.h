#include <iostream>
#include <cmath> // Incluimos cmath para funciones matemáticas

using namespace std;

// Definición de la estructura complex para representar números complejos
struct complex {
    double re; // Parte real
    double im; // Parte imaginaria

    // Constructor de la estructura que inicializa re e im
    complex(double r = 0.0, double i = 0.0) : re(r), im(i) {}
};

// Función para calcular el ángulo de un número complejo
double angle(const complex& a) {
    return atan2(a.im, a.re); // Devuelve el ángulo en radianes
}

// Función para calcular la magnitud de un número complejo
double magnitude(const complex& a) {
    return sqrt(a.re * a.re + a.im * a.im); // Raíz cuadrada de la suma de los cuadrados
}

// Función para obtener el conjugado de un número complejo
complex conjugate(const complex& a) {
    return complex(a.re, -a.im); // Parte real igual, parte imaginaria opuesta
}

// Sobrecarga del operador + para sumar dos números complejos
complex operator+(const complex& a, const complex& b) {
    return complex(a.re + b.re, a.im + b.im); // Suma de partes reales e imaginarias
}

// Sobrecarga del operador - para restar dos números complejos
complex operator-(const complex& a, const complex& b) {
    return complex(a.re - b.re, a.im - b.im); // Resta de partes reales e imaginarias
}

// Sobrecarga del operador * para multiplicar dos números complejos
complex operator*(const complex& a, const complex& b) {
    return complex(a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re); // Multiplicación
}

// Sobrecarga del operador == para comparar dos números complejos
bool operator==(const complex& a, const complex& b) {
    return (magnitude(a - b) < 1e-10); // Comparar usando magnitudes
}

// Sobrecarga del operador < para comparar magnitudes de números complejos
bool operator<(const complex& a, const complex& b) {
    return magnitude(a) < magnitude(b); // Comparar magnitudes
}

// Sobrecarga del operador > para comparar magnitudes de números complejos
bool operator>(const complex& a, const complex& b) {
    return magnitude(a) > magnitude(b); // Comparar magnitudes
}

// Sobrecarga del operador << para imprimir números complejos
ostream& operator<<(ostream& out, const complex& a) {
    out << a.re << (a.im >= 0 ? "+" : "") << a.im << "i"; // Imprimir en formato adecuado
    return out; // Devolver el flujo de salida
}

/*
 * Explicación sobre la sobrecarga de operadores:
 * La sobrecarga de operadores permite redefinir cómo funcionan los operadores
 * (como +, -, *, etc.) para tipos de datos definidos por el usuario, en este caso,
 * para la estructura 'complex'. Esto permite utilizar expresiones naturales y 
 * legibles para operar con objetos de nuestra estructura, haciendo que el código
 * sea más intuitivo y similar al uso de tipos de datos básicos.
 */

