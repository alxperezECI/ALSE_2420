#include <iostream>
#include <cmath>
#include <stdlib.h>

int main (int argc, char** argv){
    float x[100];
    float f_x[100];
    llenado(x,f_x);
    imprimir(x,f_x);
    return 1;
}

int llenado (x,f_x){
    float a = atof(arcv[2]);
    x[0]=0;
    for (i=1; i<100; i++){
        x[i] = x[i-1] + a;

    }
    float t = atof(arcv[1]);
    const double pi = 3.141592653589793;
    for (i=0; i<100; i++){
        f_x[i] = sin(2*pi*t*x[i]);
    }
    return 0;
}

int imprimir (x,f_x){
    cout << "la frecuencia usada es: " << t << "y el incremento es: " << a << endl;
    for (i = 1; i < 100; i++){
        if (((f_x[i] < 0) and (f_x[i-1] > 0)) or (((f_x[i] > 0) and (f_x[i-1] < 0)))){
            cout << x[i] << ", " << f_x[i] << "<--" << endl;
        }else{
            cout << x[i] << ", " << f_x[i] << endl;
        }
    }
    return 1;
}
// Fin del programa