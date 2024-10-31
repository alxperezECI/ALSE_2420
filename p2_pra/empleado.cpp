#include "empleado.h"
#include <iostream>
#include <string>

Empleado::Empleado(const std::string& nombre, const std::string& apellido, 
    const unsigned int& cedula, double salarioMensual)
    : _nombre(nombre), _apellido(apellido), _cedula(cedula), 
    _salarioMensual(salarioMensual) 
    {
        _horasExDia.clear();
    }
void Empleado:: agregarHorasExtras(int dia, float horas){

    _horasExDia.push_back( std::make_pair(dia, horas) );
}

 double Empleado::getSalarioTotal() const{
    double total = _salarioMensual;
    for( auto& par : _horasExDia ){
        total += par.second * 10;
    }
    return total;
}

void Empleado::getSalarioMensual(double salarioMensual) { 
    _salarioMensual = salarioMensual; 
}
std:: string empleadoMax{ 
    double maxHorasExtras = 0;
    for (size_t i = 0; i < tam; i++) {
        vector<HorasExtras> horas = _trabajadores[i].getHorasExtras();
        double totalHoras = 0.0;
        for (size_t j = 0; j < horas.size(); j++) {
            totalHoras += horas[j].second;
        }
        if (totalHoras > maxHorasExtras) {
            maxHorasExtras = totalHoras;
            empleadoMax = _trabajadores[i];
        }
    }
        
    return maxHorasExtras;
};

std:: string empleadoMin{ 
    double minHorasExtras = std::numeric_limits<double>::max();
Empleado empleadoMin;
bool empleadoEncontrado = false;

for (size_t i = 0; i < tam; i++) {
    vector<HorasExtras> horas = _trabajadores[i].getHorasExtras();
    double totalHoras = 0.0;

    for (size_t j = 0; j < horas.size(); j++) {
        totalHoras += horas[j].second;
    }

    if (totalHoras < minHorasExtras && totalHoras > 0) {
        minHorasExtras = totalHoras;
        empleadoMin = _trabajadores[i];
        empleadoEncontrado = true;
    }
}
    return empleadoMin;

};
// s