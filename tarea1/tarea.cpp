//NICOLAS CARDENAS GABRIELA SOTO
#include <iostream>
#include <cstdlib> // para poder usar rand
#include <ctime> // para iniciar rand

void imprimir(int tamano, float vector[]){  //Funcion que imprime el vector recorriendo.
    for (int fila = 0; fila < 10; fila++){
        for (int columna = 0; columna < 5; columna++){
            int indice = fila * 5 + columna;
            std::cout << vector[indice] << "\t";
        } 
        std::cout << std::endl;
    }
    std::cout << "\n";
}

int main() {
    
    // INICIA todo en 0.0 usando un for

    std:: srand(static_cast<unsigned>(std::time(nullptr)));
    const int tamano = 50; //Tamaño del vector
    float vector[tamano];
    for (int i = 0; i < tamano; i++){  //Llenado de 0 del vector
        vector[i] = 0;
    }

    imprimir(tamano, vector); //Llamada a la funcion de imprimir vector

    // Llenado del vector entre 90 y 250 dejando en 0 el valor de la posición 25

    for (int i = 0; i < tamano; i++) {  // Llenado con numeros random
        if (i != 25) {
            vector[i] = 90.0 + static_cast<float>(std::rand()) / RAND_MAX * (250.0 - 90.0);
        }
    }
    
    imprimir(tamano, vector);  //Llamada a la funcion de imprimir vector
    
    // Ordene el vector de menor a mayor con el método de la burbuja
    
    for (int j = 0; j < tamano-1; j++){
        for (int i = 0; i < tamano-1; i++){
            if (vector[i] > vector[i+1]){
                float aux = vector[i];
                vector[i] = vector[i+1];
                vector[i+1] = aux;
            }
        }
    }
    
    imprimir(tamano, vector);  //Llamada a la funcion de imprimir vector

    return 0;
}