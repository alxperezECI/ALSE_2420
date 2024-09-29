#include <iostream>
#include "complex.h" // llamamos el archivo complex.h que trae las funciones que usaremos

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

	
using namespace std;

int main(){
  complex a, b, c; // Se declaran 3 variables del tipo complejo 
  a.re = 34.8; a.im = -12.4; // Se le aasigna una parte real y otra imaginaria a la variable tipo complejo (a)
  b = conjugate(a); //se le asigna el conjugado de el cual solo es el cambio de signo en el imaginario (a) 
  c.re = c.im = 24.59;// a la variable (c) le damos un valor real y complejo que es el mismo

  complex d =  c + b; // al complejo (d) le damos un valor resultante de la suma de (c) y (b) con lo declarado en complex.h

  //d = c - a;
  cout << c << endl; // se imprime la variable (c)

  cout << d << endl; // se imprime la variable (d)

  cout << "Son iguales a y b?: " << ( a==b ) << endl; /*aqui se esta llamando a la funcion de comparacion
  que hicimos en el archivo complex.h del tipo bool , para que nos arroje 1 o 0 que seria lo mismo a true o false */
  
  cout << "son iguales b y d?: " << ( b==d ) << endl; /*Aqui tambien llamamos la funcion comparacion pero esta vez
  para comparar otro dos complejos totalmente distintos*/

// Ahora con arrglos
  complex obj[5]; /* La definicion que yo daria aqui para este arreglo es que es una lista donde 
 para cada posicion le asignamos una parte real y otra imaginaria, en este caso tiene tamaño 5*/
  obj[0].re = 34.; obj[0].im = -4.; // a la posicion 0 le asignamos un real de 34 y un imaginario de -4
  obj[1].re = obj[1].im = 45.; // a la posicion 1 le asignamos un real e imaginario de 45
  obj[2].re = 33.33; obj[2].im = -45.; // aqui aisgnamos un real de 33,33 y un imaginario de -45
  obj[3].re = 12.; obj[3].im = 25.; // Para la posicion 3 la parte real toma un valor de 12 y un imaginario de 25
  obj[4].re = obj[4].im = -56.56;// Asignamos el mismo valor de -56,56 a la parte real e imaginaria de la posicion 4

/* Aunque se nos dijo que no debiamos modificar el main.cpp, tuvimos que cambiar la linea de la posicion 2 y 4 de la
lista de obejtos ya que faltaba un (=) y sobraba un ")"*/
  

  double tmp1, tmp2; // declaramos dos variables de almacenamiento de tipo double
  bool cambio; // una variable de tipo bool

  // Qué hace este código?
  do{ /*Hacemos un do-while el cual a diferencia de los ciclos while o for donde primero revisan si tienen que cumplir
  una condicion o ejecutar el ciclo cierto numero de veces , aqui primero ejecutamos el ciclo y luego rectificamos la condicion
  para saber si lo tiene que volver a ejecutar */

    cambio = false; // A la variable tipo bool previamente declarada le dan un valor false
    for (int i =0; i < 4; ++i ){ // posteriormente hacemos un ciclo para recorrer la lista de objetos
      if( obj[i] < obj[i+1] ){/* aqui ponemos una condicion previamente definida en el complex.h donde si el primer onjeto de la 
      lista es menor al segundo no se ejecute nada en esta condicion*/
      
      }else{                        // De no llegar a cumplirse la primera condicion ejecutamos el else
        tmp1 = obj[i].re;         //Aqui tomamos las variables de almacenamiento y les damos un componente del complejo de la lista
        tmp2 = obj[i].im;
        obj[i].re = obj[i+1].re ; //cambiamos la parte real de la lista por el que le sucede 
        obj[i].im = obj[i+1].im ; // hacemos lo mismo que en la anterior linea pero con el imaginario
        obj[i+1].re = tmp1 ; // reasignamos a las variables de almacenamiento con el valor orginal de la lista
        obj[i+1].im = tmp2 ;// en la linea anterior se le asigno para los reales , aqui se hace para los imaginarios
        cambio = true; // la variable tipo bool pasa a ser true que hace referencia que el ordenamiento fue completado
      }
    }
  }while(cambio == true); //aqui se revisa si la variable tipo bool es true o false para saber si se necesita ejecutar de nuevo el do
  
  for( int i = 0 ; i < 5; ++i ) // Aqui se imprimen los valores de la lista ya ordenados
    cout << obj[i] << endl;// Desde el principio i=0 hasta el final i = 5 

  return 0; // se devuelve un cero para indicar que el programa se realizo correctamente
}