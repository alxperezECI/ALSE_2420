#include <iostream>
#include "complex.h"

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
  complex a, b, c;
  a.re = 34.8; a.im = -12.4;
  b = conjugate(a);
  c.re = c.im = 24.59;

  complex d =  c + b;

  //d = c - a;
  cout << c << endl;

  cout << d << endl;

  cout << "Son iguales a y b?: " << ( a==b ) << endl;
  cout << "son iguales b y d?: " << ( b==d ) << endl;

// Ahora con arrglos
  complex obj[5];
  obj[0].re = 34.; obj[0].im = -4.;
  obj[1].re = obj[1].im = 45.;
  obj[2].re = 33.33; obj[2].im = -45.;
  obj[3].re = 12.; obj[3].im = 25.;
  obj[4].re = obj[4].im = -56.56 ;

  double tmp1, tmp2;
  bool cambio;

  // Qué hace este código?
/*
este codigo es el algoritmo de ordenamiento por burbuja, este metodo es para ordenar de menor a mayor
comparando los elementos, se repite hasta que este completamente ordenado, en este caso compara los numeros
complejos para ordenarlos de menor a mayor, utiliza un siclo do while para que almenos se ejecute una vez
*/
  do{
    cambio = false;//inicialmente no hay intercabio
    for (int i =0; i < 4; ++i ){
      if( obj[i] < obj[i+1] ){//se compara el primer obj en la posicion i e i+1 si i es mayor se intercambia
      }else{
        tmp1 = obj[i].re;//se guarda el valor de obj[i]
        tmp2 = obj[i].im;
        obj[i].re = obj[i+1].re ;//si es mayor aqui se intercambian
        obj[i].im = obj[i+1].im ;
        obj[i+1].re = tmp1 ;
        obj[i+1].im = tmp2 ;
        cambio = true;//si hay cambio
      }
    }
  }while(cambio == true);//si hay intercambio se repite el proceso

  for( int i = 0 ; i < 5; ++i )
    cout << obj[i] << endl;

  return 0;
};