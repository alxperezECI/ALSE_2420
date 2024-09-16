#include <iostream>
#include <cmath>
using namespace std;
//Camilo Cardenas y JUliana Chaparro

float funcion(float t, float incr){
    float x[100];
    x[0]=0.0;
    for(int i = 0; i < 100; i++){
        x[i]=x[i]+incr;
    }
    float f[100];
    for(int i = 0; i < 100; i++){
        f[i]=sin(2*3.1416*t*x[i]); 
            if(f[i]==0.0){
             cout<<x[i]<<" , "<< f[i]<< "<--"<<endl;
            }

        else{   
            cout<<x[i]<<" , "<< f[i]<<endl;
            
        }   
    }
    return 0;
}
int main(int t, char** x){
cout<< funcion<< endl;
return 0;
}
