
#include <iostream>
#include<stdlib.h>
#include <cmath>

using namespace std;

int misuma(float a, int b){
    return int(a+ float(b) );
}
int main(){
    int a, b, c;
    float d, e, f;
    double h, i,j;


    a=7;
    b=9;
    d = 3.141592;
    e=78.87;
    h=667.897;
    i=(double) e;

    c =max(a, b);
    f= max(d,e);
    j=max(h,i);
    cout<< "los máximos son: " << c << "que usa"<< sizeof(c)<< endl; 
     cout<< "la suma de un numero flotante y un entero es : " << misuma(f, c) <<endl; 
    


    return 0;

}
