#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>

#include "empleado.h"

using namespace std;

void cargarArchivo( char* file, vector<Empleado> &trabajadores ){
  string nombre, apellido;
  unsigned int cedula;
  double salario;
  int dia;
  float horas;
  string   texto;
  stringstream ss;
  
  ifstream archivo( file );
  if( archivo.is_open() ){
    while( !archivo.eof() && getline( archivo, texto)){
      ss.clear();
      ss << texto ; 
      ss >> nombre >> apellido >> cedula >> salario;
      Empleado e( nombre, apellido, cedula, salario );
      while( ss >> dia >> horas ){
        e.agregarHorasExtras( dia, horas );
      }
      trabajadores.push_back( e );
    }
    archivo.close();
  }
}

int main(int argc, char**argv){
  float c = 0.;
  vector<Empleado> _trabajadores;

  cargarArchivo( argv[1], _trabajadores );//carga bien
  size_t tam = _trabajadores.size();
  cout << "Número de trabajadores: " << tam << endl;
// Calcula el valor a pagar por horas extras de cada trabajador 
/*
 for (int i = 0; i < tam; i++){
    Empleado persona = _trabajadores.at(i)
    a.val_horasextra()
  }*/

// y mostrar el valor mensual y el valor de las horas extras en un 
// arreglo tabular
// Empleado (Nmbre y apellido) | Salario mensual | Horas extras | Total a pagar


/* Encontrar y reportar el empleado con mayor número de horas extras
*/


/* Encontrar y reportar el empleado con menor número de horas extras
*/

/* Encontrar y reportar el día con mayor número de horas extras
*/

  return 0;
}
