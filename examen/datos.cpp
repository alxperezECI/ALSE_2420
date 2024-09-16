#include <iostream>
#include <math.h>
//Ejercicio práctico del examen 
//Paula Daniela González y Selene Niño Pan
using namespace std; 

float datos( float t, float inc) {
    int i;
    float f[100];
    float x[100];
    float aux=0.0;

        for(i=0; i<99; i++){
            x[i]=aux;
            aux=aux+inc;

        }
        for(i=0; i<99; i++){
            f[i]=sin(2*M_PIl*t*x[i]);

        }
        
        for(i=0; i<99; i++){
            if(f[i]=0){
                cout<<"El valor de x es :  " << x[i]<< " y el valor de f(x) es + "<< endl;
        
            }
            else{
                cout<<"El valor de x es :  " << x[i]<< " y el valor de f(x) es  "<<f[i]<< endl;
            }
        }
        
     return 0;
}
