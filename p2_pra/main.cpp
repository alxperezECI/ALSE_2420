#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip> 
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
// Calcula el valor a pagar por horas extras de cada trabajador 
for ( auto&trabajador : _trabajadores)
{
  int Salario_hora_extra = trabajador.CAL_salarioHorasExtras();
}
// y mostrar el valor mensual y el valor de las horas extras en un 
// arreglo tabular
// Empleado (Nmbre y apellido) | Salario mensual | Horas extras | Total a pagar
cout << "Nombre y apellido        | Salario mensual | Horas extras | Total a pagar:\n";
cout <<"---------------------------------------------------------------------------\n";
for (const auto& trabajador : _trabajadores )
{
  std::string nombre = trabajador.setTrabajador();
  double sal_mensual = trabajador.obtener_Salariomensual();
  double total_a_pagar = trabajador.CAL_salarioHorasExtras()+ sal_mensual;
  double H_extras = trabajador.Total_horaEx();

  cout << left << setw(25) << nombre 
      << right << setw(15) << fixed << setprecision(0) << sal_mensual 
      << right << setw(15) << fixed << setprecision(0) << H_extras
      << right << setw(15) << fixed << setprecision(0) << total_a_pagar 
      << endl;
}
/* Encontrar y reportar el empleado con mayor número de horas extras
*/
double Mayor_empleado_horaEx = 0.;
Empleado empleado_con_mas_H;
for(const auto& trabajador : _trabajadores)
{
  double Horaextra_actual = trabajador.Total_horaEx();
  if(Horaextra_actual > Mayor_empleado_horaEx)
  {
    Mayor_empleado_horaEx = Horaextra_actual;
    empleado_con_mas_H = trabajador;
  }
}
std::string nombre_empleado = empleado_con_mas_H.setTrabajador();
cout <<"Empleado con mas horas extras:"<<nombre_empleado<<" "<<"Horas extras:"<<Mayor_empleado_horaEx<<" Horas"<<endl;
/* Encontrar y reportar el empleado con menor número de horas extras
*/
double Menor_empleado_horaEx = std::numeric_limits<double>::max();
Empleado empleado_con_menos_H;
for(const auto& trabajador : _trabajadores)
{
  double Horaextra_actual = trabajador.Total_horaEx();
  if(Horaextra_actual < Menor_empleado_horaEx)
  {
    Menor_empleado_horaEx = Horaextra_actual;
    empleado_con_menos_H = trabajador;
  }
}
std::string nombre_empleado2 = empleado_con_menos_H.setTrabajador();
cout <<"Empleado con menos horas extras:"<< nombre_empleado2 <<" "<<"Horas extras:"<<Menor_empleado_horaEx<<" Horas"<<endl;

/* Encontrar y reportar el día con mayor número de horas extras
*/
vector<double> Horas_dia(31,0.);
for(const auto& trabajador : _trabajadores)
{
  for(const auto& Hora_ex : trabajador.obtener_horasextras())
  {
    if(Hora_ex.first > 0 && Hora_ex.first <=30)
    {
      Horas_dia[Hora_ex.first] += Hora_ex.second;
    }
  }
}
int dia_mas_horas = 0;
double Maximo_horas = 0.;
for (int i = 1; i <= 30;++i)
{
  if(Horas_dia[i]>Maximo_horas)
  {
    Maximo_horas = Horas_dia[i];
    dia_mas_horas = i;
  }
}
cout<< "El dia con mas horas extra es:"<< dia_mas_horas<<endl;
  return 0;
}
