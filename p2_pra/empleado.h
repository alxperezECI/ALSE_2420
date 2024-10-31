#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>
#include <vector>

typedef std::pair<int, float> HorasExtras; // (día, horas)

class Empleado {
    std::string _nombre, _apellidos;
    unsigned int _cedula;
    double _salarioMensual;
    std::vector<HorasExtras> _horasExDia;
public:
    Empleado(const std::string& nombre, const std::string& apellido, 
        const unsigned int& cedula, double salarioMensual);
    void agregarHorasExtras(int dia, float horas)
    {
        _horasExDia.push_back(HorasExtras(dia,horas));
    }
    void pushSalarioMensual(double salario)
    {
        _salarioMensual = salario;
    }
};

