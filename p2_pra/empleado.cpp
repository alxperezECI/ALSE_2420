#include "empleado.h"
#include <iostream>
#include <string>

// Constructor
Empleado::Empleado(const std::string& nombre, const std::string& apellido, 
                   const unsigned int& cedula, double salarioMensual)
    : _nombre(nombre), _apellido(apellido), _cedula(cedula), _salarioMensual(salarioMensual) {}

// Asigna el salario mensual
void Empleado::asignarSalarioMensual(double salario) {
    _salarioMensual = salario;
}

// Agrega horas extras
void Empleado::agregarHorasExtras(int dia, float horas) {
    _horasExDia.emplace_back(dia, horas); //emplace se usa puesto que se está usando un vector componente  de una clase
}

// Calcula el valor total de las horas extras
double Empleado::calcularValorHorasExtras(double valorExtra) const {
    double total = 0.0;
    for (const auto& horas : _horasExDia) {
        total += horas.second * valorExtra;  // horas.second representa las horas trabajadas
    }
    return total;
}
