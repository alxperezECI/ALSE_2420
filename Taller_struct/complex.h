/*desarrollado por Miguel Romero y Julian Ballesteros*/

#include <iostream>
#include <cmath> //para poder usar atan y sqrt

using namespace std;

struct complex
{
  double re;
  double im;
};

// Implemente la siguiente función y explique para qué sirve

/*es el constructor*/

complex crearcomplex(double r = 0., double i = 0)
{
  complex c;
  c.re = r;
  c.im = i;

  return c;
}

/* Ajuste la declaración de estas funciones para tener parámetros por referencia seguros
   e implementelas. Explique qué hace cada una de ellas.*/

double angle(const complex &a) // saca el angulo con la formula, queda en radianes.
{
  return atan2(a.im, a.re);
}
double magnitude(const complex &a) // saca la magnitud con su formula.
{
  return sqrt(a.re * a.re + a.im * a.im);
}
complex conjugate(const complex &a) // hace el conjugado.
{
  complex res;
  res.re = a.re;
  res.im = -a.im;
  return res;
}

// Ajuste la declaración de estas funciones para tener parámetros por referencia seguros
// e implementelas. Explique por qué se llama sobrecarga de operadores.

/*se llama sobrecarga de operadores porque de cierto modo se le añade una nueva forma
de operar, que es con nuestro nuevo tipo de dato, entonces le enseñamos a el operador
como operar con él, por lo que se "carga" al operador con una nueva "funcion", por ende
se dice que se sobrecarga */

complex operator+(const complex &a, const complex &b)
{
  complex res;
  res.re = a.re + b.re;
  res.im = a.im + b.im;
  return res;
}

complex operator-(const complex &a, const complex &b)
{
  complex res;
  res.re = a.re - b.re;
  res.im = a.im - b.im;
  return res;
}
complex operator*(const complex &a, const complex &b)
{
  complex res;
  res.re = a.re * b.re - a.im * b.im;
  res.im = a.re * b.im + a.im * b.re;
  return res;
}

bool operator==(const complex &a, const complex &b)
{
  return magnitude(a) == magnitude(b) && angle(a) == angle(b);
}
bool operator<(const complex &a, const complex &b)
{
  return magnitude(a) < magnitude(b);
}
bool operator>(const complex &a, const complex &b)
{
  return magnitude(a) > magnitude(b);
}
// Esta sobrecarga es espacial. Indague cómo se debe realizar, explique su correcto funcionamiento
// e implementela.

/*entiendo que es una sobrecarga especial porque debe definirse como funcion amiga
porque no pertenece a un operador normal como la suma, resta, etc. sino que pertenece
a la libreria estandar, a la cual no tenemos control, por eso la definimos fuera
como una funcion amiga, de este modo tenemos control sobre como se imprime nuestro obejeto,
que en este caso es un complex */

ostream &operator<<(std::ostream &out, complex a)
{
  out << a.re;
  if (a.im >= 0)
  {
    out << " + " << a.im << "i" << endl;
  }
  else
  {
    out << " - " << -a.im << "i" << endl;
  }
  return out;
}
