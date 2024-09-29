#include <iostream>
#include <cmath>

using namespace std;

struct complex{
  double re; // Parte real
  double im; // Parte imaginaria
  complex(double r =0. , double i = 0) : re(r), im(i) {} // Construye la estructura real + imaginaria

};

// Implemente la siguiente función y explique para qué sirve


/* Ajuste la declaración de estas funciones para tener parámetros por referencia seguros
   e implementelas. Explique qué hace cada una de ellas.
double angle(complex a);
*/
double angle(const complex& a){
  return atan2(a.im, a.re); // atan2 devuelve el ángulo en radianes de la parte imaginaria y real
}

/*
double magnitude(complex a);
*/
double magnitude(const complex& a){
  return sqrt(pow(a.re, 2) + pow(a.im, 2)); // sqrt devuelve la raíz cuadrada de la suma de los cuadrados de la parte real e imaginaria
}

/*
complex conjugate(complex a);
*/
complex conjugate(const complex& a){
  return complex(a.re, -a.im); // Devuelve el conjugado de un número complejo
}


/*
// Ajuste la declaración de estas funciones para tener parámetros por referencia seguros
// e implementelas. Explique por qué se llama sobrecarga de operadores.
complex operator+(complex a, complex b);
*/
complex operator+(const complex& a, const complex& b){
  return complex (a.re + b.re, a.im + b.im); // Devuelve la suma de dos números complejos
}

/*
complex operator-(complex a, complex b);
*/
complex operator-(const complex& a, const complex& b){
  return complex (a.re - b.re, a.im - b.im); // Devuelve la resta de dos números complejos
}

/*
complex operator*(complex a, complex b);
*/
complex operator*(const complex& a, const complex& b){
  return complex (a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re); // Devuelve el producto de dos números complejos
}

/*
bool operator==(complex a, complex b); // Implementar utilizando la magnitude y el angle
*/
bool operator == (const complex& a, const complex& b){
  return (magnitude(a) == magnitude(b) && angle(a) == angle(b)); // Devuelve true si dos números complejos son iguales
}

// bool operator<(complex a, complex b);  // Implementar utilizando la magnitude y el angle

bool operator<(const complex& a, const complex& b) // Devuelve true si el primer número complejo es menor que el segundo
{
  if (magnitude(a) < magnitude(b)) // Si la magnitud de a es menor que la de b, devuelve true
    return true;
  else if (magnitude(a) == magnitude(b)) // Si las magnitudes son iguales, compara los ángulos
    return angle(a) < angle(b);
  else
    return false;}


// bool operator>(complex a, complex b);  // Implementar utilizando la magnitude y el angle

bool operator>(const complex& a, const complex& b) // Devuelve true si el primer número complejo es mayor que el segundo
{
  if (magnitude(a) > magnitude(b)) // Si la magnitud de a es mayor que la de b, devuelve true
    return true;
  else if (magnitude(a) == magnitude(b)) // Si las magnitudes son iguales, compara los ángulos
    return angle(a) > angle(b);
  else
    return false;
}

// Esta sobrecarga es espacial. Indague cómo se debe realizar, explique su correcto funcionamiento
// e implementela. ostream& operator<<(std::ostream& out, complex a);

std::ostream& operator<<(std::ostream& out, const complex& a) {
  out << a.re << " + " << a.im << "i";
  return out;
}