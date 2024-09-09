//Entrega Tarea 1 - ALSE 2024-2 - Por Arianne Patiño y Jose Velasco
#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

int mostrar(vector<float>vec, int fil, int col){ // Funcion para mostrar la matriz

 for(int i = 0; i < fil; ++i){
        for (int j = 0; j < col; ++j){
           std::cout << vec[(col*i)+j] << " ";
       }
    std::cout << "\n";
 }
return 0;
}

int main(){
    std::srand(static_cast<unsigned>(std::time(0)));
    int fil = 10;
    int col = 5;
    int aux = 0;
    std::vector<float>vec(50); //Se define el vector de flotantes de 50 elementos

    for(int i = 0; i < vec.size(); ++i){ //Se inicializa todo en 0.0
        vec[i] = 0.0f;
    }

    for(int i = 0; i < vec.size(); ++i){ //Se llena el vector con numeros aleatorios entre 90 y 250 dejando en 0 el valor de la posición 25
        vec[i] = 90 + (rand() % 161);
    }
    vec[25]=0;

    std::cout << "Contenido del vector desordenado:" << "\n";

    mostrar(vec, fil, col); //Se muestra el contenido del vector en un arreglo de 10 filas por 5 columnas

    int n = vec.size(); //Se ordena el vector de menor a mayor con el metodo de la burbuja
    for (int i = 0; i < n - 1; ++i) { //
        for (int j = 0; j < n - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                // Intercambiar los elementos
                float aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }
    std::cout << "\n";

    std::cout << "Contenido del vector ordenado:" << "\n";

    mostrar(vec, fil, col); //Se muestra el contenido ordenado del vector en un arreglo de 10 filas por 5 columnas

    return 0;   
}