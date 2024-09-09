#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
  int primer, segundo, ordenado;
  float ale, aux;
std::srand(static_cast<unsigned>(std::time(0)));

primer = 90;
segundo = 250;
float vec[50];
//inicializar en 0 el vector
for (int i = 0; i < 50; i++) {
    vec[i]= 0;
}

for (int i = 0; i < 50; ++i) {
        ale = primer + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (segundo - primer)));
        vec[i] = ale;
    }

vec[25] = 0;
std::cout<<"\n Matriz desordenada\n\n";

for (int i = 0; i < 50; i++) 
{
    std::cout << vec[i] << " ";
    if ((i + 1) % 5 == 0) 
    {
        std::cout << std::endl;
    }
}

std::cout << std::endl << std::endl;
// método burbuja
do{
    ordenado =1;
    for (int i=0; i < 49; i++){
        if (vec[i] > vec[i+1])
        {
            aux = vec[i];
            vec[i]= vec[i+1];
            vec[i+1] = aux;
            ordenado = 0;
        }
    }
}
while (ordenado == 0);

std::cout<<"\n Matriz Ordenada de Menor a Mayor\n\n";

for (int i = 0; i < 50; i++) 
{
    std::cout << vec[i] << " ";
    if ((i + 1) % 5 == 0) 
    {
        std::cout << std::endl;
    }
}
  return 0;
}