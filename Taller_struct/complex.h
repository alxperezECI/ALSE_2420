#include <iostream>
#include <cmath>//se incluye para las operaciones matematica arctan y raiz

using namespace std;

struct complex{
  double re;
  double im;
  // Implemente la siguiente función y explique para qué sirve
  complex(double r =0. , double i = 0):re(r),im(i){};
/* La funcion es un contructor con valores por defecto:
  la funcion tiene dos parametro r para la parte real iniciada en 0
  y el parametro i para la parte imaginaria iniciada en 0 luego lleva la intruccion
  :re(r),im(i){} donde indica que re(r) inician en cero al igual que im(i),
  este contructor siempre van detro de la clase y es el que inicializa los objetos*/
};

 //Ajuste la declaración de estas funciones para tener parámetros por referencia seguros
// e implementelas. Explique qué hace cada una de ellas.
/*
Para ajustar las funciones y asegurar que reciban parámetros por referencia de manera segura
modificamos sus firmas. Las firmas definen el comportamiento de las funciones como su nombre, 
tipo de retorno y la manera en que se pasan los parámetros para ello utilizamos conts y &
*/
double angle( const complex& a)// esta funcion calcula en angulo de un numero complejo (arctan(b/a))
{
    return atan2(a.im, a.re); // arctan(imaginario/real)
}
double magnitude(const complex& a)//calcula la magnitud de un numero complejo (√ a^2 + b^2)
{
    return sqrt(a.re * a.re + a.im * a.im);
}
complex conjugate(const complex& a)// calucla el conjugado del numeros complejo (se invierte el signo de la parte imaginaria)
{
    return complex(a.re, -a.im); // La parte imaginaria se invierte
}

// Ajuste la declaración de estas funciones para tener parámetros por referencia seguros
// e implementelas. Explique por qué se llama sobrecarga de operadores.
/*
la sobrecarga de operadores se llama asi porque puede usar el mismo operador para diferenctes
tipos de datos com numeros o vectores, sirven para trabajar con las propias clases y tipos de datos 
que el usuario crea
*/
complex operator+(const complex& a, const complex& b)
{
  return {a.re + b.re, a.im + b.im};
};  
complex operator-(const complex& a, const complex& b)
{
  return {a.re - b.re, a.im - b.im};
};
complex operator*(const complex& a, const complex& b)
{
  return { a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re };
};
bool operator==(const complex& a, const complex& b)// Implementar utilizando la magnitude y el angle
{
  return{(magnitude(a) == magnitude(b)) && (angle(a) == angle(b))};
};
bool operator<(const complex& a, const complex& b)  // Implementar utilizando la magnitude y el angle
{
  return{(magnitude(a) < magnitude(b)) && (angle(a) < angle(b))};
};
bool operator>(const complex& a, const complex& b)  // Implementar utilizando la magnitude y el angle
{
  return{(magnitude(a) > magnitude(b)) && (angle(a) > angle(b))};
};
// Esta sobrecarga es espacial. Indague cómo se debe realizar, explique su correcto funcionamiento
// e implementela.
ostream& operator<<(std::ostream& out, const complex& a)
{
  out<< "El número complejo es: \n" << a.re <<",+ " << a.im ;//forma de impresion parte real y parte imaginaria a + bi
  return out;//devuelve el flujo de salida out
};
/*
la sobrecarga se realiza mediante la definición de una función que toma como parámetro un objeto de tipo
std::ostream ó std::cout o cualquier otro flujo de salida y un objeto de la clase que se desea imprimir
en la consola en este caso complex en el segundo parametro se utiliza la referencia contante para que no sea modificada

*/