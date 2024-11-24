#include <iostream>

using namespace std;

class Complex{
  double re;
  double im;

public:
  Complex( );
  Complex(double r , double i );

  double angle() const;
  double magnitude() const;
  Complex conjugate() const;

  Complex operator+( const Complex &a );
  Complex operator-( const Complex &a );
  Complex operator*( const Complex &a );
  bool operator==( const Complex &a ); 
  bool operator<( const Complex &a ); 
  bool operator>( const Complex &a ); 

  friend ostream& operator<<(std::ostream& out, Complex a);
// adicionar funciones get y set para re e im
  void Re(const double &r);
  void Im(const double &i);
  double Re();
  double Im();
};
