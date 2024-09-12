#include <iostream>
#include <vector>
#include <cstdlib>


 //Esta es la primera tarea de ALSE
 //PAULA DANIELA GONZÁLEZ - SELENE NIÑO PAN

double generateRandomFloat(double min, double max) {
    // Generar un número aleatorio y escalarlo al rango [min, max]
    return min + drand48() * (max - min);
}


int main(){

 
  // Defina un vector de flotantes de 50 elementos e 
  // inicialicelo todo en 0.0 usando un for


  printf("Ordenando un vector con el método de la burbuja\n ");
  std::vector<float> v(49);
  // OTRA FORMA DE  HACERLO ES FLOAT V[50]={0.0}
  int i, j, h=0;
  float aux;
  for (i=0; i<49; i++){
    v[i]=0.;
  }




  // Usando la función de números aleatorios llene el vector con 
  // con datos entre 90 y 250 dejando en 0 el valor de la posición 25
  srand48(time(0));
   for (i=0; i<=49; i++){
    v[i]= generateRandomFloat(90, 250);;
  }
   v[25]=0;

    
  // Muestre el contenido del vector en la pantalla en un arreglo de
  // 10 filas por 5 columnas
  printf("Este es el verctor formado\n");
  while(h<=49){
  for(i=0;i<10;i++){
    for (j=h; j<(h+5);j++) {
        std::cout <<" "<< v[j];
       }
    h=h+5;
     std::cout << std::endl;
  }}
  h=0;

  // Ordene el vector de menor a mayor con el método de la burbuja

  for(i=0; i<49; i++){
    for(j=0; j<49;j++){
      if(v[j]>v[j+1]){
        aux=v[j];
        v[j]=v[j+1];
        v[j+1]=aux;
      }
    }
  }

  // Muestre nuevamente el contenido del vector en la pantalla en un 
  // arreglo de 10 filas por 5 columnas


  printf("Este es el verctor odenado\n");
  while(h<=49){
    for(i=0;i<10;i++){
      for (j=h; j<(h+5);j++) {
          std::cout <<" "<< v[j];
        }
      h=h+5;
      std::cout << std::endl;
    }
  }

  return 0;
}
