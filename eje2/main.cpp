#include <iostream>
#include <random>

int main(){
  // Defina un vector de flotantes de 50 elementos e 
  // inicialicelo todo en 0.0 usando un for

  float vector[50] = {0.0}; //vector de 50 inicia en 0.0 


  // Usando la función de números aleatorios llene el vector con 
  // con datos entre 90 y 250 dejando en 0 el valor de la posición 25

  std::random_device ale;
  std::mt19937 gen(ale());
  std::uniform_real_distribution<> rango(90.0,250.0);

  for(int i = 0; i < 50; i++ )
  {
    if(i == 25 )
    {
      vector[i] = 0.0;
    }
    else{
      vector[i] = rango(gen);
    }
  }

// prueba para mostrar el la posicion 25 del vector el valor 0
//  for (int i = 0; i < 50; i++) {
//          std::cout << i <<"---"<< vector[i] << std::endl;
//      }


  // Muestre el contenido del vector en la pantalla en un arreglo de
  // 10 filas por 5 columnas
printf("---------------------------------------------\n");

  for(int i = 0; i < 50; i++) {
        std::cout << vector[i] << "\t"; 

        if((i + 1) % 5 == 0) {
            std::cout << std::endl; 
        }
    }

  // Ordene el vector de menor a mayor con el método de la burbuja
printf("---------------------------------------------\n");

  bool burbuja;
    do {
        burbuja = false;
        for (int i = 0; i < 49; i++) {  // Hasta 49 porque comparas con el siguiente
            if (vector[i] > vector[i + 1]) {  // Compara los elementos
                float temp = vector[i];
                vector[i] = vector[i + 1];
                vector[i + 1] = temp;
                burbuja = true;  // Marca que se ha hecho un intercambio
            }
        }
        
    } while (burbuja); 

  

  // Muestre nuevamente el contenido del vector en la pantalla en un 
  // arreglo de 10 filas por 5 columnas
  for(int i = 0; i < 50; i++) {//recorre el vector
        std::cout << vector[i] << "\t";//para hacer las columnas 

        if((i + 1) % 5 == 0) {/// 
            std::cout << std::endl; 
        }
    }
  return 0;
}
