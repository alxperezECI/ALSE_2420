#include "empleado.h"
#include <iostream>
#include <string>
#include <vector>

// Constructor
Empleado::Empleado(const std::string& nombre, const std::string& apellido, 
                   const unsigned int& cedula, double salarioMensual)
    : _nombre(nombre), _apellido(apellido), _cedula(cedula), _salarioMensual(salarioMensual) {
    _horasExDia.clear();
}

void Empleado::agregarHorasExtras(const int &dia, const float &horas) {
    HorasExtras aux(dia, horas);
    _horasExDia.push_back(aux);
}

float Empleado::horasextras() const {
    float horas = 0.;
    for(const auto& it : _horasExDia) {
        horas += it.second;
    }
    return horas;
}

float Empleado::valorhorasextra() const {
    float horas = horasextras();
    float valor = _salarioMensual / 192; 
// 8 h * 6 lab* 4 semanas
    return horas * valor;
}

std::string Empleado::getnombre_apellido() const {
    return _nombre + " " + _apellido;
}

unsigned int Empleado::getsalariomensual() const {
    return _salarioMensual;
}

std::vector<HorasExtras> Empleado::gethoras() const {
    return _horasExDia;
}

void Empleado::asignarsalario(const double &s) {
    _salarioMensual = s;
}