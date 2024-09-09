#include <iostream>
#include <array>
#include <random>
using namespace std;

int main()
{
/*

  // Defina un vector de flotantes de 50 elementos e 
  // inicialicelo todo en 0.0 usando un for
  
  array<float, 50> vect = {0.0f}; 
  
  // debe llevar f por el tipo de dato float.
  // Inicializa todos los elementos del vector en 0.0 

  // Verificar la inicialización imprimiendo los valores
  for (size_t i = 0; i < vect.size(); ++i) 
  {
    cout << "vect[" << i+1 << "] = " << vect[i] << endl;
  }
*/


/*
  // Usando la función de números aleatorios llene el vector con 
  // con datos entre 90 y 250 dejando en 0 el valor de la posición 25
  array<float, 50> vect;

  // Crear una instancia de generador de números aleatorios
  random_device rd;
  mt19937 gen(rd());
  uniform_real_distribution<float> dis(90.0f, 250.0f);

  // Llenar el array con números aleatorios en el rango [90, 250]
  for (size_t i = 0; i < vect.size(); ++i)
  {
  vect[i] = (i == 25) ? 0.0f : dis(gen);
  }

  // Imprimir los valores del array
  for (size_t i = 0; i < vect.size(); ++i) 
  {
    cout << "vect[" << i << "] = " << vect[i] << endl;
  }

*/

  // Muestre el contenido del vector en la pantalla en un arreglo de
  // 10 filas por 5 columnas
/*
  array<float, 50> vect;

  // Crear una instancia de generador de números aleatorios
  random_device rd;
  mt19937 gen(rd());
  uniform_real_distribution<float> dis(90.0f, 250.0f);

  // Llenar el array con números aleatorios en el rango [90, 250]
  for (size_t i = 0; i < vect.size(); ++i) 
  {
    vect[i] = (i == 25) ? 0.0f : dis(gen);
  }

  // Mostrar el contenido del array en un formato de 10 filas por 5 columnas
  for (size_t fila = 0; fila < 10; ++fila)
  {
    for (size_t col = 0; col < 5; ++col) 
    {
      cout << vect[fila * 5 + col] << " ";
    }
    cout << std::endl;
  }
*/


  // Ordene el vector de menor a mayor con el método de la burbuja
  // Muestre nuevamente el contenido del vector en la pantalla en un 
  // arreglo de 10 filas por 5 columnas
/*
  array<float, 50> vect;

  // Crear una instancia de generador de números aleatorios
  random_device rd;
  mt19937 gen(rd());
  uniform_real_distribution<float> dis(90.0f, 250.0f);

  // Llenar el array con números aleatorios en el rango [90, 250]
  for (size_t i = 0; i < vect.size(); ++i) 
  {
    vect[i] = (i == 25) ? 0.0f : dis(gen);
  }

  // Ordenar el array de mayor a menor usando el método de la burbuja
  for (size_t i = 0; i < vect.size() - 1; ++i) 
  {
    for (size_t j = 0; j < vect.size() - i - 1; ++j) 
    {
      if (vect[j] < vect[j + 1]) 
      {
      
        float temp = vect[j];
        vect[j] = vect[j + 1];
        vect[j + 1] = temp;
      }
    }
  }

  // Mostrar el contenido del array en un formato de 10 filas por 5 columnas
  for (size_t fila = 0; fila < 10; ++fila)
  {
      for (size_t col = 0; col < 5; ++col) 
      {
          cout << vect[fila * 5 + col] << " ";
      }
      cout << endl;
  }
  return 0;


*/

 return 0;
}
