#include <iostream>
#include <cstdlib>
#include <ctime>
int main(){
  // Defina un vector de flotantes de 50 elementos e 
  // inicialicelo todo en 0.0 usando un for
  float flotantes[50];
  float auxi;
  srand(time(NULL));
for (int i = 0; i < 50; i++)
{
    // Usando la función de números aleatorios llene el vector con 
  // con datos entre 90 y 250 dejando en 0 el valor de la posición 25
  if(i == 25)
  {
    flotantes[i] = 0;
  }
  else
  {
    flotantes[i]= 90 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (250 - 90)));
  }
}
std::cout << "Matriz sin organizar:"<<std::endl;
  // Muestre el contenido del vector en la pantalla en un arreglo de
  // 10 filas por 5 columnas
for (int i = 0; i < 50; i++)
{
  std::cout << flotantes[i] << "\t";
  if ((i + 1) % 5 == 0)
  {
    std::cout << std::endl;
  }
}
std::cout << std::endl<< "Matriz Organizada:" << std::endl;
  // Ordene el vector de menor a mayor con el método de la burbujas
for (int i = 0; i < 50 - 1; i++)
{
  for (int j = 0; j < 50 - i - 1; j++)
  {
    if(flotantes[j] > flotantes[j + 1])
    {
      auxi = flotantes[j];
      flotantes[j] = flotantes[j + 1];
      flotantes[j + 1] = auxi;
    }
  }
}
  // Muestre nuevamente el contenido del vector en la pantalla en un 
  // arreglo de 10 filas por 5 columnas
for (int i = 0; i < 50; i++)
{
  std::cout << flotantes[i] << "\t";
  if ((i + 1) % 5 == 0)
  {
    std::cout << std::endl;
  }
}
  return 0;
}
