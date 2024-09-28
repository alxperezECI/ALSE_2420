#include <iostream>
#include <cmath> // Para funciones matemáticas como atan2, sqrt, etc.

using namespace std;

struct complex
{
  double re;
  double im;

  // Constructor por defecto y sobrecarga para inicializar valores
  complex(double r = 0., double i = 0.) : re(r), im(i)
  {
    // Inicializa un número complejo con la parte real y la parte imaginaria
  }
};

// Función para calcular el ángulo de un número complejo en radianes (fase)
double angle(const complex &a)
{
  return atan2(a.im, a.re); // atan2 devuelve el ángulo en radianes.
}

// Función para calcular la magnitud de un número complejo
double magnitude(const complex &a)
{
  return sqrt(a.re * a.re + a.im * a.im); // Magnitud: raíz cuadrada de la suma de los cuadrados de las partes real e imaginaria.
}

// Función para obtener el conjugado de un número complejo
complex conjugate(const complex &a)
{
  return complex(a.re, -a.im); // El conjugado invierte el signo de la parte imaginaria.
}

// Sobrecarga del operador + para sumar dos números complejos
complex operator+(const complex &a, const complex &b)
{
  return complex(a.re + b.re, a.im + b.im); // Suma de las partes reales e imaginarias.
}

// Sobrecarga del operador - para restar dos números complejos
complex operator-(const complex &a, const complex &b)
{
  return complex(a.re - b.re, a.im - b.im); // Resta de las partes reales e imaginarias.
}

// Sobrecarga del operador * para multiplicar dos números complejos
complex operator*(const complex &a, const complex &b)
{
  return complex(a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re); // Multiplicación según las reglas del álgebra compleja.
}

// Sobrecarga del operador == para comparar dos números complejos
bool operator==(const complex &a, const complex &b)
{
  return magnitude(a) == magnitude(b) && angle(a) == angle(b); // Dos números complejos son iguales si tienen la misma magnitud y ángulo.
}

// Sobrecarga del operador < para comparar la magnitud de dos números complejos
bool operator<(const complex &a, const complex &b)
{
  return magnitude(a) < magnitude(b); // Comparación basada en magnitud.
}

// Sobrecarga del operador > para comparar la magnitud de dos números complejos
bool operator>(const complex &a, const complex &b)
{
  return magnitude(a) > magnitude(b); // Comparación basada en magnitud.
}

// Sobrecarga del operador << para imprimir un número complejo en la forma "re + im*i"
ostream &operator<<(ostream &out, const complex &a)
{
  out << a.re;
  if (a.im >= 0)
  {
    out << " + " << a.im << "i"; // Si la parte imaginaria es positiva.
  }
  else
  {
    out << " - " << -a.im << "i"; // Si la parte imaginaria es negativa.
  }
  return out;
}
