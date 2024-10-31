#include "empleado.h"
#include <iostream>
#include <string>

// Constructor
Empleado::Empleado(const std::string& nombre, const std::string& apellido, 
    const unsigned int& cedula, double salarioMensual)
    : _nombre(nombre), _apellido(apellido), _cedula(cedula), _salario(salarioMensual) 
{
    _horasExDia.clear();
}

void Empleado::agregarHorasExtras(int dia, float horas) {
    HorasExtras h = std::make_pair(dia, horas);
    _horasExDia.push_back(h);
}

void Empleado::setSalario(double salario) {
    _salario = salario;
}

double Empleado::calcular_horas(double valor_hora_extra) const {
    double total_horas = 0;

    for (size_t i = 0; i < _horasExDia.size(); ++i) {
        total_horas += _horasExDia[i].second * valor_hora_extra;
    }
    return total_horas;
}

std::string Empleado::getNombre() const {
    return _nombre;
}

std::string Empleado::getApellido() const {
    return _apellido;
}

unsigned int Empleado::getCedula() const {
    return _cedula;
}

double Empleado::getSalario() const {
    return _salario;
}
