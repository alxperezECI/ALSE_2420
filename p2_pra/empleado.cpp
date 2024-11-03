#include "empleado.h"
#include <iostream>
#include <string>
#include <vector>


// Constructor
Empleado::Empleado(const std::string& nombre, const std::string& apellido, 
                   unsigned int cedula, double salarioMensual) 
    : _nombre(nombre), _apellido(apellido), _cedula(cedula), _salarioMensual(salarioMensual) {}

// Método para agregar horas extras
void Empleado::agregarHorasExtras(int dia, float horas) {
    _horasExDia.push_back(std::make_pair(dia, horas));
}

// Calcula el valor de las horas extras según la tarifa dada
double Empleado::calcularValorHorasExtras(double tarifa) const {
    double total = 0;
    for (const auto& horas : _horasExDia) {
        total += horas.second * tarifa; // Multiplica horas por la tarifa y suma al total
    }
    return total;
}

// Obtiene el total de horas extras realizadas
int Empleado::obtenerTotalHorasExtras() const {
    int totalHoras = 0;
    for (const auto& horas : _horasExDia) {
        totalHoras += horas.second; // Asegúrate de que 'horas.second' sea del tipo correcto
    }
    return totalHoras;
}

// Devuelve las horas extras
const std::vector<HorasExtras>& Empleado::obtenerHorasExtras() const {
    return _horasExDia; 
}

// Getters
std::string Empleado::getNombre() const {
    return _nombre;
}

std::string Empleado::getApellido() const {
    return _apellido;
}

double Empleado::getSalarioMensual() const {
    return _salarioMensual;
}
