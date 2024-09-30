#include <iostream>
#include "complex.h"
using namespace std;

// Nombres: Juan David Ospina y Miguel Angel Pardo
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


int main(){
  complex a, b, c;
  a.re = 34.8; a.im = -12.4;
  b = conjugate(a);
  c.re = c.im = 24.59;

  complex d =  c + b;
//a, b y c con numeros complejos pero b, es la conjugacion de a y d es la suma entre c y b

  //d.im = c.im - a.im;  pues es b es el conjugado de a.
  cout << c << endl;

  cout << d << endl;

  cout << "Son iguales a y b?: " << ( a==b ) << endl;
  cout << "son iguales b y d?: " << ( b==d ) << endl;
//se muestra c y d y se verifica si a y b son iguales y si b y d son iguales

// Ahora con arrglos
  complex obj[5];
  obj[0].re = 34.; obj[0].im = -4.;
  obj[1].re = obj[1].im = 45.;
  obj[2].re = 33.33; obj[2].im = -45.;
  obj[3].re = 12.; obj[3].im = 25.;
  obj[4].re = obj[4].im = -56.56;

  double tmp1, tmp2;
  bool cambio;
    /* se esta definiendo a tmp1 y a tmp2 como un numero flotante muy grande y el cambio es de tipo booleano indicando que solo puede tener dos 
  valores, verdadero o falso*/


 /*compara los numeros imaginarios con los imaginarios del siguiente numero complejo de igual forma para los reales y los ordena de menor a mayor, si la verificacion
   de si es mayor que el siguiente no se cumple, entonces los guada en tmp2 y tmp1 respectivamente y realizar la ordenacion descendente, odenamiento burbuja*/

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
