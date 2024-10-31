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
// y mostrar el valor mensual y el valor de las horas extras en un 
// arreglo tabular
// Empleado (Nmbre y apellido) | Salario mensual | Horas extras | Total a pagar

  for (size_t i = 0; i < tam; i++){
    cout << _trabajadores[i].getNombre() << " " << _trabajadores[i].getApellido() << " | " << _trabajadores[i].getSalarioMensual() << " | ";
    vector<HorasExtras> horas = _trabajadores[i].getHorasExtras();
    for (size_t j = 0; j < horas.size(); j++){
      c += horas[j].second;
    }
    cout << c << " | " << _trabajadores[i].getSalarioTotal() << endl;
    c = 0.;
  }

/* Encontrar y reportar el empleado con mayor número de horas extras
*/

Empleado empleadoMax();
    double maxHorasExtras = 0;
    
    if (maxHorasExtras > 0) {
        cout << "Empleado con mayor número de horas extras: " 
            << empleadoMax.getNombre() << " " 
            << empleadoMax.getApellido() 
            << " | Horas extras: " << maxHorasExtras << endl;
    }


/* Encontrar y reportar el empleado con menor número de horas extras
*/
Empleado empleadoMin();
if (empleadoEncontrado) {
    cout << "Empleado con menor número de horas extras: " 
         << empleadoMin.getNombre() << " " 
         << empleadoMin.getApellido() 
         << " | Horas extras: " << minHorasExtras << endl;
}

/* Encontrar y reportar el día con mayor número de horas extras
*/

  vector<int> dias;
  vector<float> horas;
  for (size_t i = 0; i < tam; i++){
    vector<HorasExtras> horas = _trabajadores[i].getHorasExtras();
    for (size_t j = 0; j < horas.size(); j++){
      dias.push_back(horas[j].first);
    }
  }
  sort(dias.begin(), dias.end());
  reverse(dias.begin(), dias.end());
  cout << "Día con mayor número de horas extras: " << dias[0] << endl;

  return 0;
}