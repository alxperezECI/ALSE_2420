#include <iostream>
#include <cmath>
#include "complex.h"

using namespace std;

void Complex:: Re(const double &r){
    re = r;
};

void Complex:: Im(const double &i){
    im = i;
};

double Complex:: Re(){
    return re;
};

double Complex:: Im(){
    return im;
};

<<<<<<< HEAD
Complex::Complex(double r =0. , double i = 0 ){
    re = r;
    im = i;
};

double Complex::angle()const{
    return atan2(im, re);
};
double Complex::magnitude()const{
    return sqrt(re*re + im*im);
};
Complex Complex::conjugate()const{
    Complex r;
    r.re = re;
    r.im = -im;
    return r;
};

Complex Complex::operator+( const Complex &a ){
    Complex r;
    r.re = re + a.re;
    r.im = im + a.im;
    return r;
};
Complex Complex::operator-( const Complex &a ){
    Complex r;
    r.re = re - a.re;
    r.im = im - a.im;
    return r;
};
Complex Complex::operator*( const Complex &a ){
    Complex r;
    r.re = re*a.re - im*a.im;
    r.im = re*a.im + im*a.re;
    return r;
};
bool Complex::operator==( const Complex &a ){
    bool res;
    if( magnitude() == a.magnitude() && angle() == a.angle() )
        res = true;
    return res;
}; 
bool Complex:: operator<( const Complex &a ){
    bool res;
    if( magnitude() < a.magnitude() )
        res = true;
    else if (magnitude() == a.magnitude())
    {
        if (angle() < a.angle())
        {
            res = true;
        }
    }
    else
    {
        res = false;
    }

    return res;
};
bool Complex::operator>( const Complex &a ){
    bool res;
    if( magnitude() > a.magnitude() )
        res = true;
    else if (magnitude() == a.magnitude())
    {
        if (angle() > a.angle())
        {
            res = true;
        }
    }
    else
    {
        res = false;
    }
    return res;
}; 

ostream& operator<<(std::ostream& out, Complex a){
    out << a.re << " + " << a.im << "j";
    return out;

};
=======
Complex::Complex()
{
  re = im = 0.;
}

Complex::Complex(double r, double i)
{
  re = r;
  im = i;
}

double Complex::angle() const
{
  return atan2(im, re);
}

double Complex::magnitude() const
{
  return sqrt(re*re + im*im);
}

Complex Complex::conjugate() const
{
  Complex r;
  r.re = re;
  r.im = -im;
  return r;
}

Complex Complex::operator+( const Complex &a )
{
  Complex res;

  return res;
}

Complex Complex::operator-( const Complex &a )
{
  Complex res;

  return res;
}

Complex Complex::operator*( const Complex &a )
{
  Complex res;

  return res;
}

bool Complex::operator==( const Complex &a )
{
  bool res = false;
  if ( magnitude() == a.magnitude())
  {
    res = true;
  }
  return res;
}

bool Complex::operator<( const Complex &a )
{
  bool res;

  return res;
}

bool Complex::operator>( const Complex &a )
{
  bool res;

  return res;
}


ostream& operator<<(ostream& out, Complex a)
{
  out << a.re << " + " << a.im << "j";
  return out;
}
>>>>>>> 0934d377241dd8e9973e019bd4201a33668a419b
