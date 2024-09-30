#include <iostream> /*Incluye la libreria iostream*/
#include "complex.h" /*Inclye la libreria necesaria para manejar complejos y operaciones*/

/*  TALLER: 
    - Complete el CMakeLists.txt para configurar adecuadamente el proyecto. 
    - Nombrar el ejecutable usando la variable de configuración PROJECT_NAME
    - Usar tanto el main.cpp como el complex.h para construir el ejecutable.
    - Completar el archivo complex.h de acuerdo a las indicaciones internas.
	- No se debe modificar el código del main.cpp y la aplicación debe 
	    ejecutarse correctamente. Se deben explicar cada una de las líneas 
		del main en comentarios.
	- Enviar el pull request.
	- Se puede desarrollar de forma individual o máximo en parejas
*/

	
using namespace std; /*Se usa para que las variables definidas sean estandar y no haya necesidad
  de ponerlo antes de cada variable */

int main(){ /*Define la funcion principal o main con tipo de dato entero*/
  complex a, b, c; /*Define las variables a,b y c de tipo complejas*/
  a.re = 34.8; a.im = -12.4; /**/
  b = conjugate(a); /*Asigna a b el valor conjugado de la parte imaginaria de a*/
  c.re = c.im = 24.59; /*Asigna a la parte real e imaginaria de c el valor de 24.59*/

  complex d =  c + b; /*define la variable d de tipo complejo con la adición entre c y b*/

  //d = c - a;
  cout << c << endl; /*Imprime el valor de la variable c*/

  cout << d << endl; /*Imprime el valor de la variable d*/

  cout << "Son iguales a y b?: " << ( a==b ) << endl; /*Imprime el resultado booleano de la comparación entre a y b*/
  cout << "son iguales b y d?: " << ( b==d ) << endl; /*Imprime el resultado booleano de la comparación entre b y d*/

// Ahora con arrglos
  complex obj[5]; /*Se declara un arreglo llamado obj de 5 elementos de tipo complejo*/
  obj[0].re = 34.; obj[0].im = -4.; /*Asigna a la parte real de la variable en la posición 0 del arreglo obj 
  el valor de 34  y a la parte imaginaria el valor -4*/
  obj[1].re = obj[1].im = 45.; /*Asigna tanto a la parte real como la imaginaria de la variable en la posición 1
   del arreglo obj el valor de 45*/
  obj[2].re = 33.33 ; obj[2].im = -45.; /*Asigna a la parte real de la variable en la posición 2 del arreglo obj
  el valor de 33.33 y a la parte imaginaria el valor -45*/
  obj[3].re = 12.; obj[3].im = 25.; /*Asigna a la parte real de la variable en la posición 3 del arreglo obj 
  el valor de 12 y a la parte imaginaria el valor 25*/
  obj[4].re = obj[4].im = -56.56 ; /*Asigna tanto a la parte real como la imaginaria de la variable en la posición 4
   del arreglo obj el valor de -56.56*/

  double tmp1, tmp2; /*Se declaran las variables temporales tmp1 y tmp2 de tipo double*/
  bool cambio; /*Se define la variable cambio de tipo bool*/

  // Qué hace este código?
  do{ /*Se inicia el ciclo do - while*/
    cambio = false; /*Se asigna a la variable cambio el valor booleano false*/
    for (int i =0; i < 4; ++i ){  /*Se hace inicio del ciclo for desde i=0 hasta i=3*/
      if( obj[i] < obj[i+1] ){ /*Se plante el condicional que compara si el número complejo 
      obj[i] es menor que obj[i+1]*/
      }else{ /*Si no se cumple la condición de el if entonces se realiza lo siguiente*/
        tmp1 = obj[i].re; /*Asigna a la variable temporal tmp1 la parte real de obj[i]*/
        tmp2 = obj[i].im; /*Asigna a la variable temporal tmp2 la parte real de obj[i]*/
        obj[i].re = obj[i+1].re ; /*Asigna a la parte real de la variable del arreglo obj en 
        la posicion i la variable de la posición siguiente*/
        obj[i].im = obj[i+1].im ; /*Asigna a la parte imaginaria de la variable del arreglo obj en 
        la posicion i la variable de la posición siguiente*/
        obj[i+1].re = tmp1 ; /*Asigna a la parte real de la variable del arreglo obj en 
        la posicion i+1 la variable guardada temporalmente en tmp1*/
        obj[i+1].im = tmp2 ; /*Asigna a la parte imaginaria de la variable del arreglo obj en 
        la posicion i+1 la variable guardada temporalmente en tmp2*/
        cambio = true; /*Asigna a la variable cambio el valor booleano true*/
      }
    }
  }while(cambio == true); /*Se inicia el ciclo while, mientras que la varaible cambio sea true 
  entonces se ejecuta el ciclo for*/
  
  for( int i = 0 ; i < 5; ++i )/*Se hace inicio del ciclo for desde i=0 hasta i=4*/
    cout << obj[i] << endl; /*Se imprime el valor unicado en la posición i del arreglo obj*/

  return 0; /*Finaliza el programa*/
}