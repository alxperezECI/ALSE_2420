#include <iostream>
#include "complex.h"
#include <cmath>

using namespace std;

/* constructor */

Complex::Complex(double r, double i) : re(r), im(i)
{
  // forma eficiente, asigna los valores al crear
}

/* funciones get y set */

void Complex::Re(const double &r)
{
  re = r;
}

void Complex::Im(const double &i)
{
  im = i;
}

double Complex::Re()
{
  return re;
}

double Complex::Im()
{
  return im;
}

/* funciones matematicas */

double Complex::angle() const
{
  return atan2(im, re);
}
double Complex::magnitude() const
{
  return sqrt(re * re + im * im);
}
Complex Complex::conjugate() const
{
  Complex res;
  res.re = re;
  res.im = -im;
  return res;
}

/* sobrecarga de operadores */

Complex Complex::operator+(const Complex &a)
{
  Complex res;
  res.re = a.re + re;
  res.im = a.im + im;
  return res;
}
Complex Complex::operator-(const Complex &a)
{
  Complex res;
  res.re = a.re - re;
  res.im = a.im - im;
  return res;
}
Complex Complex::operator*(const Complex &a)
{
  Complex res;
  res.re = a.re * re - a.im * im;
  res.im = a.re * im + a.im * re;
  return res;
}
bool Complex::operator==(const Complex &a)
{
  return a.magnitude() == magnitude() && a.angle() == angle();
}
bool Complex::operator<(const Complex &a)
{
  return a.magnitude() < magnitude();
}
bool Complex::operator>(const Complex &a)
{
  return a.magnitude() < magnitude();
}

ostream &operator<<(std::ostream &out, Complex a)
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