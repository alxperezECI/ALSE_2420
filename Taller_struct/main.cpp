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
  // Declaración de tres variables de tipo "complex"
  complex a, b, c;

  // Asignación de los valores de la parte real e imaginaria del complejo 'a'
  a.re = 34.8;
  a.im = -12.4;

  // Llamada a la función 'conjugate' para obtener el conjugado de 'a', y lo asigna a 'b'
  b = conjugate(a);

  // Asignación de valores a las partes real e imaginaria de 'c'
  c.re = c.im = 24.59;

  // Suma de los complejos 'c' y 'b', asignada al complejo 'd'
  complex d = c + b;

  // Resta 'a' de 'c' y asignaría el resultado a 'd'
  // d = c - a;

  // Imprime el número complejo 'c' usando la sobrecarga del operador <<
  cout << c << endl;

  // Imprime el número complejo 'd' (resultado de la suma de 'c' y 'b')
  cout << d << endl;

  // Comparación de igualdad entre 'a' y 'b' usando la sobrecarga del operador ==
  cout << "Son iguales a y b?: " << (a == b) << endl;

  // Comparación de igualdad entre 'b' y 'd'
  cout << "son iguales b y d?: " << (b == d) << endl;

  // Declaración de un arreglo de números complejos con 5 elementos
  // Asignación de valores a las partes reales e imaginarias de los números complejos en el arreglo
  complex obj[5];
  obj[0].re = 34.;
  obj[0].im = -4.;
  obj[1].re = obj[1].im = 45.;
  obj[2].re 33.33;
  obj[2].im = -45.;
  obj[3].re = 12.;
  obj[3].im = 25.;
  obj[4].re = obj[4].im = -56.56 );

  // Variables temporales y bandera para intercambio
  double tmp1, tmp2;
  bool cambio;

  // Algoritmo de ordenación burbuja para números complejos basados en magnitud
  do
  {
    cambio = false;
    for (int i = 0; i < 4; ++i)
    {
      // Si el número complejo actual es mayor que el siguiente, se intercambian
      if (obj[i] < obj[i + 1])
      {
        // No hacer nada, ya que están en el orden correcto
      }
      else
      {
        // Intercambiar los complejos si no están en el orden correcto
        tmp1 = obj[i].re;
        tmp2 = obj[i].im;
        obj[i].re = obj[i + 1].re;
        obj[i].im = obj[i + 1].im;
        obj[i + 1].re = tmp1;
        obj[i + 1].im = tmp2;
        cambio = true; // Señala que se hizo un intercambio
      }
    }
  } while (cambio == true); // Continúa hasta que no se realicen intercambios

  // Imprime los números complejos ordenados por magnitud
  for (int i = 0; i < 5; ++i)
    cout << obj[i] << endl;

  return 0;
}
