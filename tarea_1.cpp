#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ctime> // Para time()
int main() {
    int digito = 10; // Variable para redondear las cifras decimales
    int limite_inferior = 50 * digito;
    int limite_superior = 250 * digito;
    int usuario = 50; // Variable para el tamaño del vector

    /* Se utilizo la biblioteca <ctime para usar este comando y hacer que 
    los valores aleatorios cambien acorde al tiempo , si no estuviera este
    comando los valores aleatorios serian siempre los mismos>*/
    srand(time(NULL));

    /* Crear un vector flotante para almacenar los valores aleatorios y se
    inicializa con un 0.0f*/
    std::vector<float> valores(usuario, 0.0f); 

    // Inicializar los elementos del vector con valores entre 90 y 250
    for (int i = 0; i < usuario; i += 1) {
        valores[i] = float(limite_inferior + rand() % (limite_superior + 1 - limite_inferior)) / digito;
    }

    
    /* Ordenar los elementos del vector de mayor a menor usando el metodo burbuja 
    como se nos solicito en clase para organizar los numeros de mayor a menor */
    for (int i = 0; i < usuario - 1; ++i) {
        for (int j = 0; j < usuario - i - 1; ++j) {
            if (valores[j] < valores[j + 1]) {
                float temp = valores[j];
                valores[j] = valores[j + 1];
                valores[j + 1] = temp;
            }
        }
    }

    /* Asignar el valor 0 a la posicion 25 del vector  la cual tiene que ser despues
    del ordenamiento burbuja ya si dejo esta condicion antes, la posicion volvera a 
    a cambiar y lo dejara en la ultima posicion ya que seria el dato mas pequeño*/
    if (valores[24] != 0) {
        valores[24] = 0;
    }


    /* Se imprimen los elementos en una matriz 10 x 5 . Se trato darle la oportunidad
    al usuario de escoger el tamaño del vector pero eso hacia que la matriz no fuera 
    necesariamente de 10 x 5 , o que los valores que arroja la matriz puedan ser  no los esperados*/
    for (int i = 0; i < 10; ++i) { // Filas
        for (int j = 0; j < 5; ++j) { // Columnas
            if (i * 5 + j < usuario) {
                std::cout << valores[i * 5 + j] << " // "; // dejo un "//" entre espacios para diferenciar los numeros
            }
        }
        std::cout << std::endl; // Insertar un salto de línea después de cada fila
    }

    return 0;
}