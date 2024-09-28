// Gabriela Soto y Nicolas Cardenas

#include <iostream>
#include "complex.h" //esto incluye el archivo complex.h que contiene la estructura de los complejos y sus funciones a utilizar

/*  TALLER: 
    - Complete el CMakeLists.txt para configurar adecuadamente el proyecto. 
    - Nombrar el ejecutable usando la variable de configuración PROJECT_NAME
    - Usar tanto el main.cpp como el complex.h para construir el ejecutable.
    - Completar el archivo complex.h de acuerdo a las indicaciones internas.
	- No se debe modificar el código del main.cpp y la aplicación debe 
	    ejecutarse correctamente. Se deben explicar cada una de las líneas 
		del main en comentarios.
	- Enviar el pull request.
	- Se puede desarrollar de forma individual o máximo en parejas.
*/

	
using namespace std; //permite usar los elementos del espacio como nombres estándar sin tener que especificarlo explícitamente cada vez.

int main(){
  complex a, b, c; // le dice al programa que a,b,c son numeros complejos
  a.re = 34.8; a.im = -12.4; // se le asigna un valor real a a de 34.8 y uno imaginario de -12.4, es decir a= 34.8 -12.4i
  b = conjugate(a); // conjuga el valor de a, es decir b= 34.8 + 12.4i
  c.re = c.im = 24.59; // se le asigna un valor real a c de 24.59 y uno imaginario del mismo valor, es decir c= 24.59 +24.59i

  complex d =  c + b; // crea otro valor complejo apartir de la suma de c + b; d= 59.39 + 36.99i

  //d = c - a;
  cout << c << endl; // imprime el valor de c

  cout << d << endl; // imprime el valor de d

  cout << "Son iguales a y b?: " << ( a==b ) << endl; // imprime si a y b son iguales
  cout << "son iguales b y d?: " << ( b==d ) << endl;// imprime si b y d son iguales

// Ahora con arrglos
  complex obj[5]; // crea un arreglo de 5 valores complejos
  obj[0].re = 34.; obj[0].im = -4.; // se le asigna un valor real a obj[0] de 34 y uno imaginario de -4, es decir obj[0]= 34 -4i
  obj[1].re = obj[1].im = 45.; // se le asigna un valor real a obj[1] de 45 y uno imaginario del mismo valor, es decir obj[1]= 45 +45i
  obj[2].re 33.33; obj[2].im = -45.; // se le asigna un valor real a obj[2] de 33.33 y uno imaginario de -45, es decir obj[2]= 33.33 -45i
  obj[3].re = 12.; obj[3].im = 25.; // se le asigna un valor real a obj[3] de 12 y uno imaginario de 25, es decir obj[3]= 12 +25i
  obj[4].re = obj[4].im = -56.56 ); // se le asigna un valor real a obj[4] de -56.56 y uno imaginario del mismo valor, es decir obj[4]= -56.56 -56.56i
  
  // En la linea anterior existe un parentesis de cierre que no deberia estar ahi

  double tmp1, tmp2; // se crean dos variables temporales
  bool cambio; // se crea una variable booleana

  // Qué hace este código?
  do{
    cambio = false; // se le asigna a cambio el valor de false
    for (int i =0; i < 4; ++i ){ // se crea un ciclo for que recorre el arreglo de obj
      if( obj[i] < obj[i+1] )// si el valor de obj[i] es menor que el valor de obj[i+1] no hace nada
      {
      }else{
        tmp1 = obj[i].re; // se le asigna a tmp1 el valor real de obj[i]
        tmp2 = obj[i].im; // se le asigna a tmp2 el valor imaginario de obj[i]
        obj[i].re = obj[i+1].re ; // se le asigna a obj[i].re el valor real de obj[i+1]
        obj[i].im = obj[i+1].im ; // se le asigna a obj[i].im el valor imaginario de obj[i+1]
        obj[i+1].re = tmp1 ; // se le asigna a obj[i+1].re el valor de tmp1
        obj[i+1].im = tmp2 ;// se le asigna a obj[i+1].im el valor de tmp2
        cambio = true; // se le asigna a cambio el valor de true
      }
    }
  }while(cambio == true); // se repite el ciclo do while mientras cambio sea igual a true
  
  for( int i = 0 ; i < 5; ++i ) // se crea un ciclo for que recorre el arreglo de obj
    cout << obj[i] << endl; // imprime el valor de obj[i]

  return 0; // retorna 0
}
// no me corre el programa, me sale un error en la linea 43, no se si es por el parentesis de cierre que no deberia estar ahi pero no puedo modificar el codigo main.cpp
// no se pueede modificar por indicaciones del taller