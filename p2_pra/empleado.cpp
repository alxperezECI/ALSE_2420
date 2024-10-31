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

double Empleado::CAL_salarioHorasExtras(int plata_hora_trabajo)
{
    double salario_hora = _salarioMensual/160;
    double total_HoraEx = 0.;

    for(const auto&horas : _horasExDia)
    {
        total_HoraEx += horas.second;
    }
    double salario_total = total_HoraEx * plata_hora_trabajo;
    return salario_total;
}


