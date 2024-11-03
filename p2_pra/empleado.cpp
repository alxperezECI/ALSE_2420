#include "empleado.h"

Empleado::Empleado(const std::string& nombre, const std::string& apellido, 
                   float salarioBase, const std::string& codigo)
    : nombre(nombre), apellido(apellido), salarioBase(salarioBase), codigo(codigo) {}

void Empleado::agregarHorasExtras(int dia, float horas) {
    listaHorasExtras.emplace_back(dia, horas);
}

float Empleado::calcularSalarioTotal() const {
    float salarioPorHora = salarioBase / 160.0;
    float totalHorasExtras = obtenerTotalHorasExtras();
    float valorHorasExtras = totalHorasExtras * salarioPorHora * 1.5;
    return salarioBase + valorHorasExtras;
}

float Empleado::obtenerTotalHorasExtras() const {
    float totalHorasExtras = 0.0;
    for (const auto& horasExtras : listaHorasExtras) {
        totalHorasExtras += horasExtras.second;
    }
    return totalHorasExtras;
}

int Empleado::obtenerDiaConMasHorasExtras() const {
    int diaConMasHoras = -1;
    float maxHoras = 0.0;
    for (const auto& horasExtras : listaHorasExtras) {
        int dia = horasExtras.first;
        float horas = horasExtras.second;
        if (horas > maxHoras) {
            maxHoras = horas;
            diaConMasHoras = dia;
        }
    }
    return diaConMasHoras;
}


float Empleado::obtenerHorasEnDia(int dia) const {
    for (const auto& horasExtras : listaHorasExtras) {
        if (horasExtras.first == dia) {
            return horasExtras.second;
        }
    }
    return 0.0; 
}

float Empleado::obtenerSalarioBase() const {
    return salarioBase;
}

std::string Empleado::obtenerNombreCompleto() const {
    return nombre + " " + apellido;
}

std::string Empleado::obtenerCodigo() const {
    return codigo;
}
