#include "empleado.h"
#include <iostream>
#include <string>

// Constructor
Empleado::Empleado(const std::string& nombre, const std::string& apellido, 
    const unsigned int& cedula, double salarioMensual)
    : _nombre(nombre), _apellido(apellido), _cedula(cedula), 
    _salarioMensual(salarioMensual) 
    {
        _horasExDia.clear();

       
    }

void Empleado::agregarHorasExtras(int dia, float horas){

    HorasExtras aux (dia, horas);

    _horasExDia.push_back(aux);

};

double Empleado::val_horasextra(){
    const double val_hora = _salarioMensual / 192;
    double tHorasExtras = 0;
    std::vector<HorasExtras>::const_iterator it;

    for ( it = _horasExDia.begin(); it != _horasExDia.end(); ++it) {
        tHorasExtras += it->second;
    }

    return tHorasExtras * val_hora;
}

bool Empleado::min(){
    std::vector<HorasExtras>::const_iterator it;
    double aux = 0;


    double tHorasExtras = 0;
    for ( it = _horasExDia.begin(); it != _horasExDia.end(); ++it) {
        tHorasExtras += it->second;
    }


    

};
