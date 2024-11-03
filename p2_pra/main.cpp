#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "empleado.h"
#include <algorithm>

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

int main(int argc, char** argv) {

  int dia_mayor_h = 0;
  float horas_mayor = 0.;
  float totalhoras[31] = {0.};

  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " <file_path>" << endl;
    return 1;
  }

  vector<Empleado> trabajadores;
  cargarArchivo(argv[1], trabajadores);
  size_t tam = trabajadores.size();
  cout << "Número de trabajadores en la empresa actualmente: " << tam << endl;

  cout << endl << "Nombre   Apellido   Pago salario mensual   Pago horas extras  Total" << endl;

  for (const auto& empleado : trabajadores) {
    cout << empleado.getnombre_apellido() << "   $" 
         << empleado.getsalariomensual() << "           $" 
         << empleado.valorhorasextra() << "            $" 
         << (empleado.getsalariomensual() + empleado.valorhorasextra()) << endl;
  }


  auto max_it = max_element(trabajadores.begin(), trabajadores.end(), 
    [](const Empleado& a, const Empleado& b) {
      return a.horasextras() < b.horasextras();
    });

  if (max_it != trabajadores.end()) {
    cout << endl << "El empleado con más horas extras es: " 
         << max_it->getnombre_apellido() << " con " << max_it->horasextras() 
         << " horas." << endl;
  }


  auto min_it = min_element(trabajadores.begin(), trabajadores.end(), 
    [](const Empleado& a, const Empleado& b) {
      return a.horasextras() < b.horasextras();
    });

  if (min_it != trabajadores.end()) {
    cout << endl << "El empleado con menor horas extras es: " 
         << min_it->getnombre_apellido() << " con " << min_it->horasextras() 
         << " horas." << endl;
  }

  for (const auto& empleado : trabajadores) {
    for (const auto& extras : empleado.gethoras()) {
      int dia = extras.first;
      float horas = extras.second;
      totalhoras[dia - 1] += horas;
    }}

  for (int i = 0; i < 31; ++i) {
    if (totalhoras[i] > horas_mayor) {
      dia_mayor_h = i + 1;
      horas_mayor = totalhoras[i];
    }}

  cout << endl << "El día con mayor número de horas extras fue el día #" 
       << dia_mayor_h << " con " << horas_mayor << " horas." << endl;

  return 0;
}
//Entregable por Miguel Angel Pardo y Juan David Ospina