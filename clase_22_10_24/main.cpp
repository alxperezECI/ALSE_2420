#include <iostream>
#include "complex.h"

using namespace std;

int main(){
  Complex a(34.8, -12.4), b, c(24.59, 24.59);
  //a.re = 34.8; a.im = -12.4;
  //b = conjugate(a);
  b = a.conjugate();
  //c.re = c.im = 24.59;
  cout << c << endl;

  Complex d =  c + b;
  cout << d << endl;
  d = c - a;
  cout << d << endl;

  cout << "Son iguales a y b?: " << ( a==b ) << endl;
  cout << "son iguales b y d?: " << ( b==d ) << endl;

// Ahora con arrglos
  Complex obj[5];
  obj[0].Re( 34. ); obj[0].Im( -4. );
  obj[1].Re( 45. ); obj[1].Im( 45. );
  obj[2].Re( 33.33 ); obj[2].Im( -45. );
  obj[3].Re( 12. ); obj[3].Im( 25. );
  obj[4].Re(-56.56 ); obj[4].Im( -56.56 );

  Complex tmp1;
  bool cambio;

  // Qué hace este código?
  do{
    cambio = false;
    for (int i =0; i < 4; ++i ){
      if( obj[i] < obj[i+1] ){
      }else{
        tmp1 = obj[i];
        obj[i].Re( obj[i+1].Re() );
        obj[i].Im( obj[i+1].Im() );
        obj[i+1] = tmp1 ;
        cambio = true;
      }
    }
  }while(cambio == true);
  
  for( int i = 0 ; i < 5; ++i )
    cout << obj[i] << endl;

  return 0;
}