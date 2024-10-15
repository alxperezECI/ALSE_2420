#include <iostream>
#include <math.h>
using namespace std;

struct complex{
  double re;
  double im;

// Implemente la siguiente función y explique para qué sirve:

//Inicializa el valor real e imaginario del número complejo en cero si no se pasa ningún parámetro. 
complex(double r =0.0 , double i = 0.0) {
        re = r;
        im = i;
    }


};




//Ajuste la declaración de estas funciones para tener parámetros por referencia seguros   e implementelas. Explique qué hace cada una de ellas.

//Estas funciones se declarason con parámetros de referencia con el comando const y &


//Esta función calcula el ángulo de un número complejo
double angle(const complex &a){
  double an=atan(a.im/a.re);
  return an;
};


//Esta función calcula la mangnitud de u número complejo
double magnitude(const complex &a){
  double mn=sqrt((a.re*a.re)+(a.im*a.im));
  return mn;
};

//Esta función devuelve el conjugado de un númer complejo
complex conjugate(const complex &a){
  complex conj;
  conj.im=-1*a.im; 
  return conj;
};

// Ajuste la declaración de estas funciones para tener parámetros por referencia seguros
// e implementelas. Explique por qué se llama sobrecarga de operadores.


//Se dice que se genera una sobrecarga de operadores ya que al implementar la estructura de datos
//En el main cada uno de los operadores definidos en este archivo se ejecurarán si son llamados como una función
//es decir, no es necesario definir en el main la suma de complejos, sino que se utiliza el mismo operador para 
//distintas funciones sin tener conflictos.

//Esta función suma dos números complejos a y b, haciendo suma de partes 
//imaginarias y partes reales respectivamente

complex operator+(const complex &a, const  complex &b){

  complex sum;
   sum.re=a.re+b.re;
   sum.im=a.im+b.im;
   return sum;
};

//Esta función resta dos números complejos a y b, haciendo resta de partes 
//imaginarias y partes reales respectivamente
complex operator-(complex a, complex b){
  

  complex res;
   res.re=a.re-b.re;
   res.im=a.im-b.im;
   return res;
};

//Esta función multiplica dos números complejos a y b
  complex operator*(complex a, complex b){
  complex mult; 
  mult.re=(a.re*b.re)-(a.im*b.im);
  mult.im=(a.re*b.im)+(a.im*b.re);
  return mult;

};

//Esta función compara dos números complejos a y b, es decir que la magnitud y el ángulo sean iguales
bool operator==(complex a, complex b){ // Implementar utilizando la magnitude y el angle
   bool indicator;
  if(angle(a)==angle(b) && magnitude(a)==magnitude(b))
     indicator=true;
  
  else indicator=false;
  return indicator;
  };


//Esta función indica cuál de los dos números complejos es menor, teniendo en cuenta sus magnitudes, 
//por lo que si ambas magnitudes son iguales se indicará que a no es menor que b.
bool operator<(complex a, complex b){
  bool indicator;

  if(magnitude(a)<magnitude(b))
    indicator=true;
  
  else 
   indicator=false;

  return indicator; 
}; 



  //Esta función indica cuál de los dos números complejos es mayor, teniendo en cuenta sus magnitudes, 
//por lo que si ambas magnitudes son iguales se indicará que a no es mayor que b.
bool operator>(complex a, complex b){
  bool indicator;

  if(magnitude(a)>magnitude(b))
    indicator=true;
  
  else 
   indicator=false;

  return indicator; 
}; 


// Esta sobrecarga es espacial. Indague cómo se debe realizar, explique su correcto funcionamiento
// e implementela.
 

 //La sobrecarga del operador << en C++ para una estructura o clase personalizada como complex permite 
 //imprimir objetos de esa estructura directamente utilizando el operador <<, lo que hace que la impresión 
 //sea más intuitiva y limpia. 
 ostream& operator<<(ostream& out, const complex& a) {
    // Definimos el formato de salida: (parte real, parte imaginaria)
    out << "(" << a.re << ", " << a.im << "i)";
    return out;  // Devolver la referencia al flujo para permitir encadenamiento
};
