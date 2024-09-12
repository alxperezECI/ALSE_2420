#include <iostream>
//<<<<<<< HEAD
#include <random>

//=======
#include <stdlib.h>
#include <time.h>
//>>>>>>> f6a9e21dae80bb55ded24f8d5941ab496721f98a

int main(){
  srand(time(NULL));
  // Defina un datos de flotantes de 50 elementos e 
  // inicialicelo todo en 0.0 usando un for
  float datos[50]={0.0};
  for(int i = 0; i < 50; i++){
    datos[i] = 0.0;
  }
  
  // Usando la función de números aleatorios llene el datos con 
  // con datos entre 90 y 250 dejando en 0 el valor de la posición 25
  for(int i = 0; i < 50; i++){
    datos[i] = 90 + rand() * 160.0;
  }

  // Muestre el contenido del datos en la pantalla en un arreglo de
  // 10 filas por 5 columnas
  for( int i = 0; i < 10; i++){
    for( int j = 0; j < 5; j++ )
      std:: cout << datos[5*i+j] << "\t" ;

    std::cout << std::endl;
  }

  for(int i = 0; i < 50; i++) {
        std::cout << datos[i] << "\t"; 

        if((i + 1) % 5 == 0) {
            std::cout << std::endl; 
        }
    }

  // Ordene el datos de menor a mayor con el método de la burbuja
printf("---------------------------------------------\n");

  bool burbuja;
    do {
        burbuja = false;
        for (int i = 0; i < 49; i++) {  // Hasta 49 porque comparas con el siguiente
            if (datos[i] > datos[i + 1]) {  // Compara los elementos
                float temp = datos[i];
                datos[i] = datos[i + 1];
                datos[i + 1] = temp;
                burbuja = true;  // Marca que se ha hecho un intercambio
            }
        }
        
    } while (burbuja); 

  

  // Muestre nuevamente el contenido del datos en la pantalla en un 
  // arreglo de 10 filas por 5 columnas
  for(int i = 0; i < 50; i++) {//recorre el datos
        std::cout << datos[i] << "\t";//para hacer las columnas 

        if((i + 1) % 5 == 0) {/// 
            std::cout << std::endl; 
        }
    }
  return 0;
}
