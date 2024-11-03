#include "empleado.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

// Constructor con parámetros
Empleado::Empleado(const string &nombre, const string &apellido, unsigned int cedula, float salario) {
    _nombre = nombre;
    _apellido = apellido;
    _cedula = cedula;
    _salario = salario;
    _ValorHE = 0.0;
    _horasExt.clear();
}

// Constructor por defecto
Empleado::Empleado() {
    _nombre = "";
    _apellido = "";
    _cedula = 0;
    _salario = 0.0;
    _ValorHE = 0.0;
    _horasExt.clear();
}

double Empleado::salario() const {
    return _salario;
}

void Empleado::setSalario(double salario) {
    _salario = salario;
}

unsigned int Empleado::cedula() const {
    return _cedula;
}

void Empleado::setCedula(unsigned int cedula) {
    _cedula = cedula;
}

std::string Empleado::apellido() const {
    return _apellido;
}

void Empleado::setApellido(const string &apellido) {
    _apellido = apellido;
}

string Empleado::nombre() const {
    return _nombre;
}

void Empleado::setNombre(const string &nombre) {
    _nombre = nombre;
}

void Empleado::agregarHorasExtras(int dia, float horas) {
    _horasExt.push_back(HorasExtras(dia, horas));
}

std::vector<HorasExtras> Empleado::obtenerHorasExtras() const {
    return _horasExt;
}

double Empleado::horasExtras() const {
    double totalHoras = 0;
    for (const auto& horasExtra : _horasExt) {
        totalHoras += horasExtra.second;
    }
    return totalHoras;
}

double Empleado::ValorHE() const {
    return _ValorHE;
}

void Empleado::setValorHE(double totalAPagar) {
    _ValorHE = totalAPagar;
}