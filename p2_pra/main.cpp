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
  cout << "Empleado | Salario mensual | Horas extras | Total a pagar" << endl;

    Empleado maxHorasExtras = _trabajadores[0];
    Empleado minHorasExtras = _trabajadores[0];
    int diaMaxHorasExtras = -1;
    float maxHorasDia = 0.0;

    for (const auto& empleado : _trabajadores) {
      float totalHorasExtras = empleado.getTotalHorasExtras();
      int totalAPagar = empleado.getTotalAPagar();
      int salarioMensual = empleado.getSalarioMensual();
      c += totalAPagar;
      cout << empleado.getNombreCompleto() << " | " << salarioMensual << " | " << totalHorasExtras << " | " << totalAPagar << endl;

        // Encontrar el empleado con mayor y menor horas extras
        if (totalHorasExtras > maxHorasExtras.getTotalHorasExtras()) {
            maxHorasExtras = empleado;
        }
        if (totalHorasExtras < minHorasExtras.getTotalHorasExtras()) {
            minHorasExtras = empleado;
        }

        // Encontrar el día con mayor horas extras
        for (const auto& horasExtra : empleado.getHorasExtras()) {
            if (horasExtra.second > maxHorasDia) {
                maxHorasDia = horasExtra.second;
                diaMaxHorasExtras = horasExtra.first;
            }
        }
    }
    
    cout << "\nEmpleado con mayor horas extras: " << maxHorasExtras.getNombreCompleto()<< " " << maxHorasExtras.getTotalHorasExtras() << " horas" << endl;
    cout << "Empleado con menor horas extras: " << minHorasExtras.getNombreCompleto() << " " << minHorasExtras.getTotalHorasExtras() << " horas" << endl;
    cout << "Día con mayor horas extras: Día " << diaMaxHorasExtras << " con " << maxHorasDia << " horas." << endl;
    return 0;
}