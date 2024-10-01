#include <iostream>
#include "complex.h"

/*  TALLER: Paula Daniela González Gómez y Selene Niño Pan
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
  complex a, b, c;
  a.re = 34.8; a.im = -12.4;
  b = conjugate(a);
  c.re = c.im = 24.59;
//Las líneas anteriores definen tres variables de tipo complejo con la estructura de datos implementada en el complex.h
  complex d =  c + b;//Asigna a la variable d la suma de c y b, haciendo uso del operador + de la librería "complex"

  
  cout << c << endl;

  cout << d << endl; //La líneas anteriores imprimen los valores de los números complejos c y d

  cout << "Son iguales a y b?: " << ( a==b ) << endl; 
  cout << "son iguales b y d?: " << ( b==d ) << endl; //La líneas anteriores utilizan el operador boleano de comparación 
  //para determinar si los números son iguales.

// Ahora con arreglos


  complex obj[5];  //Esta es una inicialización de un arreglo de 5 elementos de tipo complex llamado obj
  obj[0].re = 34.; obj[0].im = -4.;
  obj[1].re = obj[1].im = 45.;
  obj[2].re= 33.33; obj[2].im = -45.;
  obj[3].re = 12.; obj[3].im = 25.;
  obj[4].re = obj[4].im = -56.56;

  double tmp1, tmp2;
  bool cambio;

  // Qué hace este código?: Ordena los números del arreglo obj de menor a mayor con el método de la burbuja. 
  do{
    cambio = false;
    for (int i =0; i < 4; ++i ){
      if( obj[i] < obj[i+1] ){
      }else{
        tmp1 = obj[i].re;
        tmp2 = obj[i].im;
        obj[i].re = obj[i+1].re ;
        obj[i].im = obj[i+1].im ;
        obj[i+1].re = tmp1 ;
        obj[i+1].im = tmp2 ;
        cambio = true;
      }
    }
  }while(cambio == true);
  
  for( int i = 0 ; i < 5; ++i )
    cout << obj[i] << endl;

  return 0;
}
