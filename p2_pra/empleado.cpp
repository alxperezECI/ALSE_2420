#include "empleado.h"
#include <iostream>
#include <string>
#include <vector>

// Constructor
Empleado::Empleado(const std::string& nombre, const std::string& apellido, 
    const unsigned int& cedula, double salarioMensual)
    : _nombre(nombre), _apellido(apellido), _cedula(cedula), 
    _salarioMensual(salarioMensual) 
    {
        _horasExDia.clear();
    }   
void Empleado::agregarHorasExtras(int dia, float horas) {
        _horasExDia.push_back(std::make_pair(dia, horas));
    }
void Empleado::asigna_salario_mensual( double salarioMensual ) {
        _salarioMensual = salarioMensual;
    }
double Empleado::calcular_horas_extras( double salarioMensual, float horasExtras ) {
        horasExtras = 0;
        for (int i = 0; i < _horasExDia.size(); i++) {
        horasExtras += _horasExDia[i].second; 
        double valor = 0;
        valor = ((salarioMensual/30)/8) * horasExtras;
        return valor;
    }


