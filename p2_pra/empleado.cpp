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
    };

void Empleado::agregarHorasExtras(const int &dia, const float &horas){  
    HorasExtras aux (dia, horas);
    _horasExDia.push_back(aux);

};

float Empleado::numhorasextra(){
    float horas = 0.;
    std::vector<HorasExtras>::const_iterator it;
    for(it = _horasExDia.begin(); it != _horasExDia.end(); ++it){
        horas += it->second;
    };
    return horas;
};

float Empleado::valorhorasextra(){
    float horas = 0.;
    horas = numhorasextra();
    float valhora = _salarioMensual/192; //8 horas al dia * 6 dias a la semana * 30 dias del mes
    return horas*valhora;
}

std::string Empleado::getnombre_apellido(){
    return _nombre + " " + _apellido;
};



unsigned int Empleado::getsalariomensual(){
    return _salarioMensual;
};

std::vector<HorasExtras> Empleado::gethoras_exdia(){
    return _horasExDia;
};

void Empleado::asignarsalario(const double &s){
    _salarioMensual = s;
    return;
};