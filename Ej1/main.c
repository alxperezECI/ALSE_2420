#include <stdio.h>

int main(){

  int x, y ,aux;
  printf("Ingrese dos números enteros: ") ;
  scanf("%i", &x);
  scanf("%i", &y);
  aux = x;
  printf("Hola mundo alse 2024-2");
  x = y;
  y = aux;
  printf("%i, %i\n", x, y);
  return 0;
}
