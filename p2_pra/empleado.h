#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <vector>



typedef std::pair<int, float> HorasExtras;

class Empleado {
    std::string _nombre;
    std::string _apellido;
    unsigned int _cedula;
    double _salarioMensual;
    std::vector<HorasExtras> _horasExDia;

public:
    Empleado(const std::string& nombre, const std::string& apellido, 
        const unsigned int& cedula, double salarioMensual);

    void agregarHorasExtras(int dia, float horas) ;

    double val_horasextra();

    bool menor();
    bool mayor();

};

#endif