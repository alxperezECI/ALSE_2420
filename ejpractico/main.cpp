//Ejercicio Practico 1 ALSE - Arianne Patiño - Jose Velasco
#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char** argv){
    int size = 100;
    int aux1, aux2 = 0;
    float vector[size]={0.0};
    float incremento = atof(argv[2]);
    float frecuencia = atof(argv[1]);
    float resultado[size] = {0.0};

    for (int i = 1; i< size; i++){
        vector[i]=incremento*i;
    } 

    for (int k = 0; k < size; k++){
        resultado[k]=sin(vector[k]*frecuencia*2*M_PI);
    }
    cout << vector[0] << " , " << resultado[0] << "\n";
    for (int z = 1; z < size; z++){
        if(resultado[z]<0){
            aux1=1;
        }
        else
        {
            aux1=0;
        }
        if (resultado[z-1]<0){
            aux2=1;
        }
        else
        {
            aux2=0;
        }
        if (aux1==aux2){
            cout << vector[z] << "  ,  " << resultado[z] << "\n";
        }
        else
        {
            cout << vector[z] << "  ,  " << resultado[z] << "<-" << "\n";
        }
    }
    return 0;
}