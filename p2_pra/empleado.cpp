#include "empleado.h"
#include <string>
#include <iostream>

const double PAGO_POR_HORA_EXTRA = 20.0;

// Constructor
Empleado::Empleado(const std::string& nombre, const std::string& apellido, 
    const unsigned int& cedula, double salarioMensual)
    : _nombre(nombre), _apellido(apellido), _cedula(cedula), 
      _salarioMensual(salarioMensual) 
{
    _horasExDia.clear();
}

void Empleado::agregarHorasExtras(int dia, float horas) {
    _horasExDia.emplace_back(dia, horas);
}

double Empleado::calcularHorasExtras() const {
    double totalPagoHorasExtras = 0.0;
    for (const auto& horasExtra : _horasExDia) {
        totalPagoHorasExtras += horasExtra.second * PAGO_POR_HORA_EXTRA;
    }
    return totalPagoHorasExtras;
}

float Empleado::getTotalHorasExtras() const {
    float totalHoras = 0.0;
    for (const auto& horasExtra : _horasExDia) {
        totalHoras += horasExtra.second;
    }
    return totalHoras;
}

std::string Empleado::getNombreCompleto() const {
    return _nombre + " " + _apellido;
}

double Empleado::getTotalAPagar() const {
    // Calcular el salario por hora
    double salarioPorHora = _salarioMensual / 240.0;
    double pagoHorasExtras = 0.0;

    // Calcular el pago total por las horas extras
    for (const auto& horasExtra : _horasExDia) {
        pagoHorasExtras += horasExtra.second * salarioPorHora;
    }
    return _salarioMensual + pagoHorasExtras;
}

double Empleado::getSalarioMensual() const {
    return _salarioMensual;
}

const std::vector<HorasExtras>& Empleado::getHorasExtras() const {
    return _horasExDia;
}
