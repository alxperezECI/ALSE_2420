//Taller ALSE Estructuras, Desarrollado por Arianne Patiño y Jose Velasco

#include <iostream>    //Se incluye la biblioteca estandar de C++
#include "complex.h"   //Se incluye el archivo de cabecera "complex.h", este se incluye usando comillas debido a que está ubicado en el mismo directorio que el archivo main.cpp

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

using namespace std;   //Para indicarle al programa que se va a usar el espacio de nombres std, lo que permite evitar escribir el prefijo std:: en algunas funciones

int main(){            //Se define la función main, la principal del programa.
  complex a, b, c;     //Se realiza la declaración de las variables a, b y c de tipo complex, cuya definición se encuentra en el archivo de cabecera "complex.h"
  a.re = 34.8; a.im = -12.4; //Para la variable de tipo complejo a, se declara una parte real de 34.8 y una parte imaginaria de -12.4

  b = conjugate(a); //se invoca la funcion conjugate con el parametro a y lo que retorna se asigna a b
  
  c.re = c.im = 24.59; //se le asigna el valor 24.59 a la parte real e imaginaria de c

  complex d =  c + b; //se define el complejo d y se le asigna la suma de c y b

  //d = c - a;
  cout << c << endl; // se imprime c en la terminal

  cout << d << endl; // se imprime c en la terminal

  cout << "Son iguales a y b?: " << ( a==b ) << endl; // se imprime la comparacion de a y b. si son iguales imprime 1, si son diferentes imprime 0
  cout << "son iguales b y d?: " << ( b==d ) << endl; // se imprime la comparacion de b y d. si son iguales imprime 1, si son diferentes imprime 0

  complex obj[5]; //se define el arreglo obj de longitud 5 de tipo complex
  obj[0].re = 34.; obj[0].im = -4.; // se le asigna a la posicion 0 del arreglo obj un complejo con parte real igual a 34 y parte imaginaria igual a -4
  obj[1].re = obj[1].im = 45.; // se le asigna a la posicion 1 del arreglo obj un complejo con parte real igual a 45 y parte imaginaria igual a 45
  obj[2].re = 33.33; obj[2].im = -45.; // se le asigna a la posicion 2 del arreglo obj un complejo con parte real igual a 33.33 y parte imaginaria igual a -45
  obj[3].re = 12.; obj[3].im = 25.; // se le asigna a la posicion 3 del arreglo obj un complejo con parte real igual a 12 y parte imaginaria igual a 25
  obj[4].re = obj[4].im = -56.56 ; // se le asigna a la posicion 4 del arreglo obj un complejo con parte real igual a -56.56 y parte imaginaria igual a -56.56



  double tmp1, tmp2; // se define las variables tmp1 y tmp2 como dobles 
  bool cambio; //se define la variable cambio como un booleano

// Qué hace este código?
// A continuacion se organizara el arreglo de menor a mayor y se imprimiran los valores de este en la terminal

  do{ //Comienza el loop do-while, una variante del loop while que ejecuta una vez el bloque de codigo antes de revisar si la condicion es verdadera
  //luego continuara el ciclo hasta que se cumpla la condicion
    cambio = false; // se le asigna como valor false a cambio
    for (int i =0; i < 4; ++i ){ //comienza el ciclo for que continuara mientras i siga siendo menor que 4, y en cada ciclo se le suma a i 1
      if( obj[i] < obj[i+1] ){ // comienza el if, donde no va a hacer nada si se cumple que el numero en la posicion i es menor que el siguiente
      }else{ //si no se cumple la condicion del if, se ejecutara este bloque del codigo
        tmp1 = obj[i].re; //se le asigna el valor real del arreglo obj en la posicion i a tmp1 
        tmp2 = obj[i].im; //se le asigna el valor imaginario del arreglo obj en la posicion i a tmp2
        obj[i].re = obj[i+1].re ; //se le asigna a la posicion i del arreglo obj el valor real de la siguiente posicion
        obj[i].im = obj[i+1].im ; //se le asigna a la posicion i del arreglo obj el valor complejo de la siguiente posicion
        obj[i+1].re = tmp1 ; //se le asigna a la posicion i+1 en el valor real del arreglo obj el valor en tmp1 
        obj[i+1].im = tmp2 ; //se le asigna a la posicion i+1 en el valor complejo del arreglo obj el valor en tmp2
        cambio = true; //se le asigna un valor verdadero a la variable cambio
      } //Llave de cierre del else
    } //Llave de cierre del bucle for
  }while(cambio == true);//condicion para que el loop do-while termine

  for( int i = 0 ; i < 5; ++i ) //Bucle for para imprimir el arreglo ya organizado en la terminal, termino a termino
    cout << obj[i] << endl; //Mostrar en la terminal los valores del arreglo en función de la variable incremental i que lo recorre con el bucle for
  return 0;//termina la funcion main y regresa un cero, que significa que cumplio la tarea exitosamente 
}
