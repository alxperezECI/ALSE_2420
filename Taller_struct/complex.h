#include <iostream>
#include <cmath>
using namespace std;
//Miguel pardo y Juan ospina/
struct complex{
  double re;
  double im;
};
// Implemente la siguiente función y explique para qué sirve: Inicializa la variable cuya magnitud es 0 y ángulo 0.
complex cero(double r =0.0 , double i = 0.0){
  complex c;
  c.re = r;
  c.im = i;
  return c;
};


complex conjugate(const complex &a){
  complex c;
  c.re =a.re;
  c.im =-a.im;
return c;
}
/*Double se usa para almacenar valores flotantes de mayor cantidad
de numeros, ya que el double ocupa hasta 64 bits, esta funcion cambia la conjugacion del numero imaginario y real,
el parametro "a" hace referencia a un objeto tipo complex, const asegura que el parametro no sera modificado dentro
de la funcion y el & es para el paso por referencia. Por otro lado, se dice que es sobre carga de operadores porque
repetidamente se hace uso de la función complex pero con diferente función o acción para operadores existentes en c++ para que ejecuten una acción determinada */

//segundo punto

double magnitude(const complex &a){
  return sqrt(a.re*a.re + a.im*a.im);
}

/*Double se usa para almacenar valores flotantes de mayor cantidad
de numeros, ya que el double ocupa hasta 64 bits, esta funcion calcula la magnitud de un numero  imaginario,
el parametro "a" hace referencia a un objeto tipo complex, const asegura que el parametro no sera modificado dentro
de la funcion y el & es para el paso por referencia */

double angle(const complex &a){
  return atan2( a.im, a.re);
}

/*Double se usa para almacenar valores flotantes de mayor cantidad
de numeros, ya que el double ocupa hasta 64 bits, esta funcion calcula el angulo un numero imaginario y real
el parametro "a" hace referencia a un objeto tipo complex, const asegura que el parametro no sera modificado dentro
de la funcion y el & es para el paso por referencia y el atan2 es el tangente^-1 entre el numero imaginario y el real */

complex operator+(const complex &a, const complex &b){
  complex c;
  c.re = a.re + b.re;
  c.im = a.im+b.im;
  return c;
}
complex operator-(const complex &a, const complex &b){
  complex c;
  c.re = a.re - b.re;
  c.im = a.im - b.im;
  return c;
}
complex operator*(const complex &a, const complex &b){
  complex c;
  c.re = a.re * b.re - a.im * b.im;
  c.im = a.re * b.im + a.im * b.re;
  return c;
}
bool operator==( const complex &a, const complex &b){
  return magnitude(a) == magnitude(b); //si se cumple es true
}
bool operator>(const complex &a, const complex &b){
  return magnitude(a) > magnitude(b); //si se cumple es true
}
bool operator<( const complex &a, const complex &b){
  return angle(a) < angle(b);//si se cumple es true
}
ostream& operator<<(std::ostream& out, complex a){
    // Definimos el formato de salida: (parte real, parte imaginaria)
    out << "(" << a.re << ", " << a.im << "i)";
    return out;
}  // permite encadenamiento para num complejo
/*Al intentar imprimir un número complejo con cout << sum, el compilador no sabe cómo hacerlo porque no se ha sobrecargado
 el operador << para la estructura complex, por lo tanto se utiliza la sobrecarga espacial para el correcto funcionamiento.
*/
