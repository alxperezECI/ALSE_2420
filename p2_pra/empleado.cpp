#include "empleado.h"
#include <iostream>
#include <string>

// Constructor
Empleado::Empleado(const std::string &nombre, const std::string &apellido,
                   const unsigned int &cedula, double salarioMensual)
    : _nombre(nombre), _apellido(apellido), _cedula(cedula),
      _salarioMensual(salarioMensual)
{
    _horasExDia.clear();
}

void Empleado::asignarSalarioMensual(double salario)
{
    _salarioMensual = salario;
}

void Empleado::agregarHorasExtras(int dia, float horas)
{
    _horasExDia.push_back({dia, horas});
}

double Empleado::calcularValorHorasExtras(double tasaHoraExtra) const
{
    double totalHorasExtras = 0.0;

    for (const auto &horaExtra : _horasExDia)
    {
        totalHorasExtras += horaExtra.second;
    }

    return totalHorasExtras * tasaHoraExtra;
}

std::string Empleado::getNombre() const
{
    return _nombre;
}

std::string Empleado::getApellido() const
{
    return _apellido;
}

unsigned int Empleado::getCedula() const
{
    return _cedula;
}

double Empleado::getSalarioMensual() const
{
    return _salarioMensual;
}
