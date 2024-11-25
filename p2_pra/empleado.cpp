#include "empleado.h"
#include <iostream>
#include <string>

// Constructor
Empleado::Empleado(const std::string& nombre, const std::string& apellido, 
    const unsigned int& cedula, double salarioMensual)
    : _nombre(nombre), _apellidos(apellido), _cedula(cedula), 
    _salarioMensual(salarioMensual) 
    {
        _horasExDia.clear();
    }
Empleado::Empleado() : _nombre(""), _apellidos(""), _cedula(0), _salarioMensual(0.0) 
{
    _horasExDia.clear();
}
double Empleado::CAL_salarioHorasExtras()const 
{
    double salario_hora = _salarioMensual/160;
    double total_HoraEx= 0.;
    for(const auto&horas : _horasExDia)
    {
        total_HoraEx += horas.second;
    }
    double salario_extra_total = total_HoraEx * salario_hora;
    return salario_extra_total;
}

void Empleado:: setSalarioMensual(double salario)
    {
        _salarioMensual = salario;
    }
void Empleado:: agregarHorasExtras(int dia, float horas)
    {
        _horasExDia.push_back(HorasExtras(dia,horas));
    }

double Empleado:: obtener_Salariomensual()const
{
    return _salarioMensual;
}

std::vector<std::pair<int, float>> Empleado:: obtener_horasextras()const
{
  return _horasExDia;
}

double Empleado:: Total_horaEx()const
{
    double total_HoraEx2= 0.;
    for(const auto&horas2 : _horasExDia)
    {
        total_HoraEx2 += horas2.second;
    }
    return total_HoraEx2;
}

std::string Empleado::setTrabajador () const
{
    return _nombre + " "+ _apellidos;
}