#include <iostream> //Se incluye la libreria estandar de C++
#include <cmath>    //Se incluye la libreria cmath para utilizar constantes y funciones matematicas como atan()

using namespace std; //Se le indica al programa que se va a utilizar el espacio de nombres std para simplificar la escritura de algunas funciones.

struct complex{ //Se define una estructura con el nombre "complex"
  double re;    //Dentro de la estructura complex se crea una variable de tipo double para almacenar la parte real del numero complejo
  double im; //Se crea también una variable de tipo double llamada "im" para almacenar la parte imaginaria del numero complejo
  
  // Implemente la siguiente función y explique para qué sirve

  complex(double r =0.0 , double i = 0.0){ //Esta función se debe implementar dentro de la declaración de la estructura, es un constructor y permite inicializar una variable de tipo complex, en este caso con parte real 0.0 y parte imaginaria 0.0, cuando no se le asigne ningun valor al declarar la variable, por ejemplo si ponemos "complex a", la variable tendrá un valor de "0+0i"
    re = r;
    im = i;
  }
};

//Ajuste la declaración de estas funciones para tener parámetros por referencia seguros e implementelas. Explique qué hace cada una de ellas.

double angle(const complex &a){ //función que retorna el angulo del numero complejo, usando la funcion matematica arcotangente
  double c = atan(a.im/a.re);
  return c;
};

double magnitude(const complex &a){ //Función que retorna la magnitud del numero complejo, esto se realiza calculando la raiz de la suma de las componentes, cada una elevada al cuadrado.
  double c = sqrt((a.re*a.re)+(a.im*a.im));
  return c;
};

complex conjugate(const complex &a){ //Función que retorna el conjugado de una variable tipo complex, el conjugado, para un complejo expresado en parte real e imaginaria, se obtiene al multiplicar por -1 la parte imaginaria.
  complex c;
  c.re = a.re;
  c.im = -(a.im);
  return c;
};

// Ajuste la declaración de estas funciones para tener parámetros por referencia seguros
// e implementelas. Explique por qué se llama sobrecarga de operadores.

//Se llama sobrecarga de operadores debido a que los operadores, en este caso, los de suma, resta, multiplicación y comparación de igualdad, mayor y menor se "cargan" con un nuevo funcionamiento que en este caso nos permite realizar todas esas operaciones aritmeticas y de comparación con numeros complejos definidos en la estructura complex ademas de los tipos de datos que estos operadores soportan por defecto.

complex operator+(const complex &a, const complex &b){ //Se sobrecarga el operador de suma "+" para sumar dos variables que se pasan por referencia de tipo complex, recordando que la suma de dos complejos de la forma parte real e imaginaria se realiza sumando parte real con real e imaginaria con imaginaria, y se retorna el resultado de estas sumas.
  complex c;
  c.re=a.re+b.re;
  c.im=a.im+b.im;
  return c;
  
};

complex operator-(const complex &a, const complex &b){ //Se define la sobrecarga del operador resta "-" para restar un numero complejo menos otro, recordando que la resta se realiza restando parte real menos parte real y parte imaginaria menos parte imaginaria, retorna el resultado de estas restas como otro numero complejo.
  complex c;
  c.re=a.re-b.re;
  c.im=a.im-b.im;
  return c;
};

complex operator*(const complex &a, const complex &b){ //Se declara la sobrecarga del operador multiplicación para poder multiplicar dos numeros complejos, esta se realiza utilizando la propiedad distributiva y el hecho que i^2=-1, para separar toda la parte compleja de la parte real, llegando a la expresión para multiplicar dos numeros a+bi y c+di como (a*c-b*d)+(a*d+b*c)i
  complex c;
  c.re=(a.re*b.re)-(a.im*b.im);
  c.im=(a.re*b.im)+(a.im*b.re);
  return c;
};

// Implementar utilizando la magnitude y el angle
bool operator==(const complex &a, const complex &b){ //Se sobrecarga el operador de comparación para saber si dos numeros complejos son iguales o no, comparando si las magnitudes de los dos numeros son iguales, ademas de comparar si sus angulos son iguales.
  bool d;
  if (magnitude(a)==magnitude(b) && angle(a)==angle(b))
  d = true;
  else
  d = false;
  return d;
};

// Implementar utilizando la magnitude y el angle
bool operator<(complex a, complex b){ //Se declara la sobrecarga del operador de comparación menor que, para saber si un numero complejo es menor que otro, esta comparación se basa en revisar si la magnitud de un numero es menor que la del otro, si es asi, se asume que el numero es menor y se retorna un valor booleano true, y si tienen la misma magnitud, se revisa si el angulo es menor, de ser asi, tambien decimos que el numero es menor, de lo contrario el numero no es menor y se retorna un valor booleano de false.
  bool c;
  if (magnitude(a)<magnitude(b)){
    c = true;
  }
  else
  {
    if(magnitude(a)==magnitude(b)){
      if(angle(a)<angle(b)){
        c = true;
      }
      else
      {
        c = false;
      }
    }
    else
    {
      c = false;
    }
  }
  return c;
};

// Implementar utilizando la magnitude y el angle
bool operator>(complex a, complex b){ //Se define la sobrecarga de operador de comparacion mayor que, el cual permite saber si un numero complejo es mayor que otro, para esto se revisan primero las magnitudes de los numeros complejos,si la magnitud de un numero es mayor que la del otro, asumimos que el numero complejo es mayor y la funcion retorna un valor booleano true, si las magnitudes de los dos numeros son iguales, se revisan los angulos, y si el angulo es mayor, asumimos que el numero complejo es mayor y retornamos el valor booleano true, de lo contrario, se asume que el numero no es mayor y se retorna el valor booleano false
  bool c;
  if (magnitude(a)>magnitude(b)){
    c = true;
  }
  else
  {
    if(magnitude(a)==magnitude(b)){
      if(angle(a)>angle(b)){
        c = true;
      }
      else
      {
        c = false;
      }
    }
    else
    {
      c = false;
    }
  }
  return c;
};


// Esta sobrecarga es espacial. Indague cómo se debe realizar, explique su correcto funcionamiento
// e implementela.

ostream& operator<<(std::ostream& out, const complex a){ //Esta funcion permite sobrecargar el operador "<<", con el fin de imprimir variables de estructuras especificas, en este caso, queremos imprimir numeros complejos utilizando la salida del espacio de nombres std, std::cout, si la parte imaginaria es positiva, se agrega el signo "+" antes del numero, y si es menor a cero, no se le agrega el signo + con el fin de que no queden de la forma a+-bi, entonces como el numero ya tiene el signo, solamente se añade el numero para que quede de la forma a-bi.
  if (a.im >= 0){
    out << a.re << "+" << a.im << "i";
  }
  else
  {
    out << a.re << a.im << "i";
  }
  return out;
};
