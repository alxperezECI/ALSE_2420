#include<iostream>
#include<cmath>
using namespace std;
void graficos (int valores){
    int resultados[valores];
    float B = 0;
    float k = 0;
    int numeros[valores];
    for (int i = 0; i < valores; i++) {
        k +=0,01;
        numeros[i] += k;
    }
    float sen(2* M_PI *B);
    for (int j = 0 ; j < valores; j++){
         numeros[j] = B;
         resultados[j] += B;
    }
    for(int z = 0; z < valores; z++){
        cout << "resultado " << z++ << " es: "<< numeros [z] <<"  "<< resultados[z] << endl;
    };
};
int main(){
    int valores;
    cout << "Ingrese el número de valores con los que quiere trabajar: ";
    cin >> valores;
    graficos(valores);
    return 0;
}