/*desarrollado por Miguel Romero y Julian Ballesteros*/

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

int main()
{
  complex a, b, c;     // define 3 variables de tipo complex.
  a.re = 34.8;         // asigna valores a la parte real de a.
  a.im = -12.4;        // asigna valores a la parte imaginaria de b.
  b = conjugate(a);    // guarda en b el conjugado de a.
  c.re = c.im = 24.59; // asigna un valor a la parte imaginaria de c y la asigna a su parte real.

  complex d = c + b; // crea un complex d y le asigna c + d.

  // d = c - a;
  cout << c << endl; // imprime complex c.

  cout << d << endl; // imprime complex d.

  cout << "Son iguales a y b?: " << (a == b) << endl; // imprime si a y b son iguales
  cout << "son iguales b y d?: " << (b == d) << endl; // imprime si b y d son iguales

  // Ahora con arrglos
  complex obj[5];                 // crea un complejo obj de 5 posiciones
  obj[0].re = 34.;                // asigna a obj[0] en su parte real un valor
  obj[0].im = -4.;                // asigna a obj[0] en su parte imaginaria un valor
  obj[1].re = obj[1].im = 45.;    // asigna a obj[1] un valor igual en su parte real e imaginaria
  obj[2].re = 33.33;              // asigna a obj[2] en su parte real un valor
  obj[2].im = -45.;               // asigna a obj[2] en su parte imaginaria un valor
  obj[3].re = 12.;                // asigna a obj[3] en su parte real un valor
  obj[3].im = 25.;                // asigna a obj[3] en su parte imaginaria un valor
  obj[4].re = obj[4].im = -56.56; // asigna a obj[4] un valor igual en su parte real e imaginaria

  double tmp1, tmp2; // crea dos variables doble
  bool cambio;       // crea una variable bool

  // Qué hace este código?

  /*hace el ordenamiento burbuja optimizado para organizar un arreglo de numeros complex
  y al final con el ciclo for se imprime el obj[]*/

  do
  {
    cambio = false;
    for (int i = 0; i < 4; ++i)
    {
      if (obj[i] < obj[i + 1])
      {
      }
      else
      {
        tmp1 = obj[i].re;
        tmp2 = obj[i].im;
        obj[i].re = obj[i + 1].re;
        obj[i].im = obj[i + 1].im;
        obj[i + 1].re = tmp1;
        obj[i + 1].im = tmp2;
        cambio = true;
      }
    }
  } while (cambio == true);

  for (int i = 0; i < 5; ++i)
    cout << obj[i] << endl;

  return 0;
}
