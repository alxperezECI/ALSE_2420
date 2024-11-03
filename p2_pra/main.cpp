//Desarrollado por Arianne Patiño y Jose Velasco

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
  // Empleado (Nombre y apellido) | Salario mensual | Horas extras | Total a pagar

  std::vector<Empleado>::iterator it,found;

  cout << endl << "Nombre   |  Apellido   |  Salario mensual  |   Valor horas extra   |   Total a pagar" << endl;
  cout << "-------------------------------------------------------------------------------------" << endl;

  for(it = _trabajadores.begin(); it != _trabajadores.end(); ++it){
    cout << "Empleado" << " |  " << it->getnombre_apellido() << " |  $" << it->getsalariomensual() << "         |         $" << it->valorhorasextra() << "       |      $" << (it->getsalariomensual())+(it->valorhorasextra()) <<  endl;
  } //Los espacios se dejaron con el fin de facilitar la visualización de los datos en la consola.


/* Encontrar y reportar el empleado con mayor número de horas extras
*/

  found = it = _trabajadores.begin();
  ++it;

  while (it != _trabajadores.end()) {
      if (it->numhorasextra() > found->numhorasextra()) {
          found = it;
      }
      ++it;
  }

  cout << endl << "El empleado con mayor número de horas extra es: " << found->getnombre_apellido()  << " con " << found->numhorasextra() << " horas." << endl;


/* Encontrar y reportar el empleado con menor número de horas extras
*/

  found = it = _trabajadores.begin();
  ++it;

  while (it != _trabajadores.end()) {
    if (it->numhorasextra() < found->numhorasextra()) {
        found = it;
    }
    ++it;
  }
  cout << endl << "El empleado con menor número de horas extra es: " << found->getnombre_apellido()  << " con " << found->numhorasextra() << " horas." << endl;



/* Encontrar y reportar el día con mayor número de horas extras
*/

  int diamax = 0;
  float horasmax=0.;
  float tot_horasdia[31]={0.};
  std::vector<HorasExtras> vec_horas_ex;
  std::vector<HorasExtras>::iterator it1;
  
  for(it=_trabajadores.begin(); it!= _trabajadores.end(); ++it){
    vec_horas_ex = it->gethoras_exdia();
    for(it1 = vec_horas_ex.begin(); it1 != vec_horas_ex.end(); ++it1){
      int dia = it1->first;
      float horas = it1->second;
      tot_horasdia[dia-1] += horas;
    }
  }
  for(int i = 0;i < 31; i++){
    if(tot_horasdia[i]>horasmax){
      diamax = i+1;
      horasmax = tot_horasdia[i];
    }
  }
  cout << endl << "El dia con mayor numero de horas extra realizadas fue el dia #" <<  diamax << " con " << horasmax << " horas." << endl ;

  return 0;
}